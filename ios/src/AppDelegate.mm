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
    // 1. Initialize persistent file logger (~/Documents/logs/tekken6.log & ~/Documents/tekken6.log)
    [[TekkenLogger sharedLogger] setupLogging];
    NSSetUncaughtExceptionHandler(&TekkenUncaughtExceptionHandler);
    
    [[TekkenLogger sharedLogger] logMessage:@"=================================================="];
    [[TekkenLogger sharedLogger] logMessage:@"[Tekken 6 iOS] Starting Tekken 6 Native Host Runner"];
    [[TekkenLogger sharedLogger] logMessage:@"=================================================="];
    
    // 2. Log hardware & environment metrics
    UIDevice *dev = [UIDevice currentDevice];
    UIScreen *screen = [UIScreen mainScreen];
    NSProcessInfo *pInfo = [NSProcessInfo processInfo];
    
    CGFloat w = MAX(screen.bounds.size.width, screen.bounds.size.height);
    CGFloat h = MIN(screen.bounds.size.width, screen.bounds.size.height);
    
    // Check if legacy 480x320 was reported; if so, recover true dimensions from nativeBounds
    if (w <= 480.0f && screen.nativeBounds.size.width > 0 && screen.nativeScale > 0) {
        w = MAX(screen.nativeBounds.size.width, screen.nativeBounds.size.height) / screen.nativeScale;
        h = MIN(screen.nativeBounds.size.width, screen.nativeBounds.size.height) / screen.nativeScale;
    }
    
    [[TekkenLogger sharedLogger] logMessage:[NSString stringWithFormat:@"[Device] Model: %@ | OS: %@ %@", dev.model, dev.systemName, dev.systemVersion]];
    [[TekkenLogger sharedLogger] logMessage:[NSString stringWithFormat:@"[Hardware] Active CPU Cores: %lu | Physical RAM: %.2f GB",
                                             (unsigned long)pInfo.activeProcessorCount,
                                             (double)pInfo.physicalMemory / (1024.0 * 1024.0 * 1024.0)]];
    [[TekkenLogger sharedLogger] logMessage:[NSString stringWithFormat:@"[Display] Screen Target: %.0fx%.0f @ %.1fx (Native: %.0fx%.0f) | Max FPS: %ld | LowPowerMode: %s",
                                             w, h, screen.nativeScale,
                                             screen.nativeBounds.size.width, screen.nativeBounds.size.height,
                                             (long)screen.maximumFramesPerSecond,
                                             pInfo.isLowPowerModeEnabled ? "YES" : "NO"]];
    [[TekkenLogger sharedLogger] logMessage:[NSString stringWithFormat:@"[Storage] Documents Path: %@",
                                             NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject]];
    
    // 3. Initialize Tekken 6 hooks (resolution scaling, thread wait, ProMotion)
    Tekken6InitHooks();
    
    // 4. Setup primary window with full landscape bounds and window scene if available
    CGRect windowFrame = CGRectMake(0, 0, w, h);
    if (@available(iOS 13.0, *)) {
        for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
            if ([scene isKindOfClass:[UIWindowScene class]]) {
                UIWindowScene *winScene = (UIWindowScene *)scene;
                self.window = [[UIWindow alloc] initWithWindowScene:winScene];
                break;
            }
        }
    }
    
    if (!self.window) {
        self.window = [[UIWindow alloc] initWithFrame:windowFrame];
    } else {
        self.window.frame = windowFrame;
    }
    
    self.viewController = [[ViewController alloc] init];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window {
    return UIInterfaceOrientationMaskLandscape;
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
