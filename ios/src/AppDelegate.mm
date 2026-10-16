#import "AppDelegate.h"
#import "ViewController.h"
#import "TekkenLogger.h"
#import "tekken6_hooks.h"

static void TekkenUncaughtExceptionHandler(NSException *exception) {
    NSString *log = [NSString stringWithFormat:@"\n================ UNCAUGHT EXCEPTION ================\n"
                     @"Name: %@\nReason: %@\nCallStack:\n%@\n====================================================\n",
                     exception.name, exception.reason, [exception.callStackSymbols componentsJoinedByString:@"\n"]];
    [[TekkenLogger sharedLogger] logMessage:log];
    
    NSString *crashPath = [[TekkenLogger sharedLogger] crashFilePath];
    [log writeToFile:crashPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
}

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // 1. Initialize persistent file logger (~/Documents/tekken6.log)
    [[TekkenLogger sharedLogger] setupLogging];
    NSSetUncaughtExceptionHandler(&TekkenUncaughtExceptionHandler);
    
    [[TekkenLogger sharedLogger] logMessage:@"=================================================="];
    [[TekkenLogger sharedLogger] logMessage:@"[Tekken 6 iOS] Starting Tekken 6 Native Host Runner"];
    [[TekkenLogger sharedLogger] logMessage:@"=================================================="];
    
    // 2. Log hardware & environment metrics
    UIDevice *dev = [UIDevice currentDevice];
    UIScreen *screen = [UIScreen mainScreen];
    NSProcessInfo *pInfo = [NSProcessInfo processInfo];
    
    [[TekkenLogger sharedLogger] logMessage:[NSString stringWithFormat:@"[Device] Model: %@ | OS: %@ %@", dev.model, dev.systemName, dev.systemVersion]];
    [[TekkenLogger sharedLogger] logMessage:[NSString stringWithFormat:@"[Hardware] Active CPU Cores: %lu | Physical RAM: %.2f GB",
                                             (unsigned long)pInfo.activeProcessorCount,
                                             (double)pInfo.physicalMemory / (1024.0 * 1024.0 * 1024.0)]];
    [[TekkenLogger sharedLogger] logMessage:[NSString stringWithFormat:@"[Display] Screen Size: %.0fx%.0f @ %.1fx | Max FPS: %ld | LowPowerMode: %s",
                                             screen.bounds.size.width, screen.bounds.size.height,
                                             screen.nativeScale, (long)screen.maximumFramesPerSecond,
                                             pInfo.isLowPowerModeEnabled ? "YES" : "NO"]];
    [[TekkenLogger sharedLogger] logMessage:[NSString stringWithFormat:@"[Storage] Documents Path: %@",
                                             NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject]];
    
    // 3. Initialize Tekken 6 hooks (resolution scaling, thread wait, ProMotion)
    Tekken6InitHooks();
    
    // 4. Setup primary window
    self.window = [[UIWindow alloc] initWithFrame:screen.bounds];
    self.viewController = [[ViewController alloc] init];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    [[TekkenLogger sharedLogger] logMessage:@"[Lifecycle] App will resign active (pausing rendering)"];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [[TekkenLogger sharedLogger] logMessage:@"[Lifecycle] App did become active (resuming presentation)"];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [[TekkenLogger sharedLogger] logMessage:@"[Lifecycle] App entered background"];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    [[TekkenLogger sharedLogger] logMessage:@"[Lifecycle] App will terminate"];
}

@end
