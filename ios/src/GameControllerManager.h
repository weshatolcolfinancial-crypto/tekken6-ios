#pragma once

#import <Foundation/Foundation.h>
#import <GameController/GameController.h>
#import "TouchOverlayView.h"

@protocol GameControllerDelegate <NSObject>
- (void)gamepadInputChanged:(uint32_t)pressedButtons leftStickX:(float)lx leftStickY:(float)ly;
- (void)gamepadConnectionStatusChanged:(BOOL)isConnected;
@end

@interface GameControllerManager : NSObject

@property (nonatomic, weak) id<GameControllerDelegate> delegate;
@property (nonatomic, readonly) BOOL hasConnectedController;

+ (instancetype)sharedManager;
- (void)startMonitoring;
- (void)stopMonitoring;

@end
