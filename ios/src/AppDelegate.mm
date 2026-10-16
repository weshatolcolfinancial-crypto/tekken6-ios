#import "AppDelegate.h"
#import "ViewController.h"
#import "tekken6_hooks.h"

static void TekkenUncaughtExceptionHandler(NSException *exception) {
    NSString *log = [NSString stringWithFormat:@"CRASH EXCEPTION:\nName: %@\nReason: %@\nCallStack:\n%@\n",
                     exception.name, exception.reason, [exception.callStackSymbols componentsJoinedByString:@"\n"]];
    NSLog(@"%@", log);
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    if (paths.count > 0) {
        NSString *crashPath = [paths.firstObject stringByAppendingPathComponent:@"crash.log"];
        [log writeToFile:crashPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    }
}

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSSetUncaughtExceptionHandler(&TekkenUncaughtExceptionHandler);
    NSLog(@"[Tekken 6 iOS] Launching Tekken 6 Recompiled on iOS...");
    
    // Initialize Tekken 6 hooks (resolution scaling, thread wait, ProMotion)
    Tekken6InitHooks();
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.viewController = [[ViewController alloc] init];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Pause rendering and audio stream when entering background
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Resume execution
}

@end
