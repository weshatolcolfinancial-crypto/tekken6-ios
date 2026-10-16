#import "TekkenLogger.h"
#import <os/lock.h>
#import <sys/signal.h>
#import <execinfo.h>
#import <unistd.h>

NSString * const TekkenLogUpdatedNotification = @"TekkenLogUpdatedNotification";

static TekkenLogger *s_sharedLogger = nil;
static os_unfair_lock s_logLock = OS_UNFAIR_LOCK_INIT;
static FILE *s_logFile = NULL;
static int s_pipeFds[2];
static dispatch_source_t s_pipeSource = nil;

extern "C" void TekkenLog(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[2048];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    
    NSString *msg = [NSString stringWithUTF8String:buffer];
    [[TekkenLogger sharedLogger] logMessage:msg];
}

static void TekkenSignalHandler(int sig) {
    void *callstack[128];
    int frames = backtrace(callstack, 128);
    char **strs = backtrace_symbols(callstack, frames);
    
    NSMutableString *crashReport = [NSMutableString string];
    [crashReport appendFormat:@"\n================ CRASH SIGNAL CAUGHT: %d ================\n", sig];
    [crashReport appendFormat:@"Timestamp: %@\n", [NSDate date]];
    [crashReport appendString:@"Backtrace:\n"];
    for (int i = 0; i < frames; ++i) {
        if (strs && strs[i]) {
            [crashReport appendFormat:@"  [%d] %s\n", i, strs[i]];
        }
    }
    if (strs) free(strs);
    
    NSLog(@"%@", crashReport);
    
    NSString *crashPath = [[TekkenLogger sharedLogger] crashFilePath];
    [crashReport writeToFile:crashPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    
    if (s_logFile) {
        fputs(crashReport.UTF8String, s_logFile);
        fflush(s_logFile);
    }
    
    signal(sig, SIG_DFL);
    raise(sig);
}

@interface TekkenLogger () {
    NSMutableArray<NSString *> *_memoryLogs;
    NSDateFormatter *_dateFormatter;
    NSString *_logPath;
    NSString *_crashPath;
}
@end

@implementation TekkenLogger

+ (instancetype)sharedLogger {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        s_sharedLogger = [[TekkenLogger alloc] init];
    });
    return s_sharedLogger;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _memoryLogs = [NSMutableArray arrayWithCapacity:500];
        _dateFormatter = [[NSDateFormatter alloc] init];
        _dateFormatter.dateFormat = @"HH:mm:ss.SSS";
        
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *docs = paths.firstObject ?: NSTemporaryDirectory();
        
        // Ensure logs directory exists
        NSString *logsDir = [docs stringByAppendingPathComponent:@"logs"];
        [[NSFileManager defaultManager] createDirectoryAtPath:logsDir withIntermediateDirectories:YES attributes:nil error:nil];
        
        _logPath = [docs stringByAppendingPathComponent:@"tekken6.log"];
        _crashPath = [docs stringByAppendingPathComponent:@"crash.log"];
    }
    return self;
}

- (void)setupLogging {
    os_unfair_lock_lock(&s_logLock);
    
    if (!s_logFile) {
        // Open ~/Documents/tekken6.log in append mode
        s_logFile = fopen(_logPath.UTF8String, "a");
        if (s_logFile) {
            fprintf(s_logFile, "\n\n=== Tekken 6 iOS Log Session Started: %s ===\n", [NSDate date].description.UTF8String);
            fflush(s_logFile);
        }
    }
    
    // Register crash signal handlers
    signal(SIGSEGV, TekkenSignalHandler);
    signal(SIGBUS,  TekkenSignalHandler);
    signal(SIGABRT, TekkenSignalHandler);
    signal(SIGILL,  TekkenSignalHandler);
    signal(SIGFPE,  TekkenSignalHandler);
    
    // Redirect stdout & stderr using POSIX pipe so all printf and runtime messages are saved
    if (pipe(s_pipeFds) == 0) {
        // Duplicate stdout & stderr to the pipe write-end
        dup2(s_pipeFds[1], STDOUT_FILENO);
        dup2(s_pipeFds[1], STDERR_FILENO);
        
        s_pipeSource = dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, s_pipeFds[0], 0, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0));
        dispatch_source_set_event_handler(s_pipeSource, ^{
            char buf[1024];
            ssize_t n = read(s_pipeFds[0], buf, sizeof(buf) - 1);
            if (n > 0) {
                buf[n] = '\0';
                NSString *str = [NSString stringWithUTF8String:buf];
                if (!str) {
                    str = [[NSString alloc] initWithBytes:buf length:n encoding:NSASCIIStringEncoding];
                }
                if (str.length > 0) {
                    NSArray *lines = [str componentsSeparatedByCharactersInSet:[NSCharacterSet newlineCharacterSet]];
                    for (NSString *line in lines) {
                        NSString *trimmed = [line stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
                        if (trimmed.length > 0) {
                            [[TekkenLogger sharedLogger] logMessage:trimmed];
                        }
                    }
                }
            }
        });
        dispatch_resume(s_pipeSource);
    }
    
    os_unfair_lock_unlock(&s_logLock);
    
    [self logMessage:@"[Tekken 6 Logger] Logging subsystem initialized. Target: Documents/tekken6.log"];
}

- (void)logMessage:(NSString *)message {
    if (!message || message.length == 0) return;
    
    NSString *timestamp = [_dateFormatter stringFromDate:[NSDate date]];
    NSString *formatted = [NSString stringWithFormat:@"[%@] %@", timestamp, message];
    
    os_unfair_lock_lock(&s_logLock);
    
    if (s_logFile) {
        fprintf(s_logFile, "%s\n", formatted.UTF8String);
        fflush(s_logFile);
    }
    
    if (_memoryLogs.count >= 600) {
        [_memoryLogs removeObjectsInRange:NSMakeRange(0, 100)];
    }
    [_memoryLogs addObject:formatted];
    
    os_unfair_lock_unlock(&s_logLock);
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [[NSNotificationCenter defaultCenter] postNotificationName:TekkenLogUpdatedNotification object:formatted];
    });
}

- (NSString *)logFilePath {
    return _logPath;
}

- (NSString *)crashFilePath {
    return _crashPath;
}

- (NSArray<NSString *> *)recentLogs {
    os_unfair_lock_lock(&s_logLock);
    NSArray *copy = [_memoryLogs copy];
    os_unfair_lock_unlock(&s_logLock);
    return copy;
}

- (NSString *)fullLogText {
    os_unfair_lock_lock(&s_logLock);
    if ([[NSFileManager defaultManager] fileExistsAtPath:_logPath]) {
        NSError *err = nil;
        NSString *content = [NSString stringWithContentsOfFile:_logPath encoding:NSUTF8StringEncoding error:&err];
        os_unfair_lock_unlock(&s_logLock);
        return content ?: @"(Unable to read log file)";
    }
    NSString *memContent = [_memoryLogs componentsJoinedByString:@"\n"];
    os_unfair_lock_unlock(&s_logLock);
    return memContent;
}

- (void)clearLogs {
    os_unfair_lock_lock(&s_logLock);
    [_memoryLogs removeAllObjects];
    if (s_logFile) {
        fclose(s_logFile);
        s_logFile = fopen(_logPath.UTF8String, "w");
    }
    os_unfair_lock_unlock(&s_logLock);
    
    [self logMessage:@"[Tekken 6 Logger] Log file cleared."];
}

@end
