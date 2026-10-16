#import "AppDelegate.h"
#import "ViewController.h"
#import "../tekken6_hooks.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
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
