#import "GameControllerManager.h"

@interface GameControllerManager () {
    GCController *_activeController;
}
@end

@implementation GameControllerManager

+ (instancetype)sharedManager {
    static GameControllerManager *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[GameControllerManager alloc] init];
    });
    return instance;
}

- (BOOL)hasConnectedController {
    return _activeController != nil;
}

- (void)startMonitoring {
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(controllerDidConnect:)
                                                 name:GCControllerDidConnectNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(controllerDidDisconnect:)
                                                 name:GCControllerDidDisconnectNotification
                                               object:nil];
    
    if ([GCController controllers].count > 0) {
        [self attachController:[GCController controllers].firstObject];
    }
}

- (void)stopMonitoring {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)controllerDidConnect:(NSNotification *)notification {
    GCController *controller = notification.object;
    NSLog(@"[Tekken 6 GameController] Controller connected: %@", controller.vendorName);
    [self attachController:controller];
}

- (void)controllerDidDisconnect:(NSNotification *)notification {
    GCController *controller = notification.object;
    NSLog(@"[Tekken 6 GameController] Controller disconnected: %@", controller.vendorName);
    if (_activeController == controller) {
        _activeController = nil;
        if ([self.delegate respondsToSelector:@selector(gamepadConnectionStatusChanged:)]) {
            [self.delegate gamepadConnectionStatusChanged:NO];
        }
    }
}

- (void)attachController:(GCController *)controller {
    _activeController = controller;
    
    if ([self.delegate respondsToSelector:@selector(gamepadConnectionStatusChanged:)]) {
        [self.delegate gamepadConnectionStatusChanged:YES];
    }
    
    GCExtendedGamepad *profile = controller.extendedGamepad;
    if (!profile) return;
    
    __weak GameControllerManager *weakSelf = self;
    profile.valueChangedHandler = ^(GCExtendedGamepad * _Nonnull gamepad, GCControllerElement * _Nonnull element) {
        GameControllerManager *strongSelf = weakSelf;
        if (!strongSelf) return;
        
        uint32_t buttons = 0;
        
        // D-Pad
        if (gamepad.dpad.up.isPressed) buttons |= BTN_DPAD_UP;
        if (gamepad.dpad.down.isPressed) buttons |= BTN_DPAD_DOWN;
        if (gamepad.dpad.left.isPressed) buttons |= BTN_DPAD_LEFT;
        if (gamepad.dpad.right.isPressed) buttons |= BTN_DPAD_RIGHT;
        
        // Face Buttons (Tekken mapping: X = LP, Y = RP, A = LK, B = RK)
        if (gamepad.buttonX.isPressed) buttons |= BTN_X;
        if (gamepad.buttonY.isPressed) buttons |= BTN_Y;
        if (gamepad.buttonA.isPressed) buttons |= BTN_A;
        if (gamepad.buttonB.isPressed) buttons |= BTN_B;
        
        // Shoulders & Triggers
        if (gamepad.leftShoulder.isPressed) buttons |= BTN_LEFT_SHOULDER;
        if (gamepad.rightShoulder.isPressed) buttons |= BTN_RIGHT_SHOULDER;
        if (gamepad.leftTrigger.isPressed) buttons |= BTN_LEFT_TRIGGER;
        if (gamepad.rightTrigger.isPressed) buttons |= BTN_RIGHT_TRIGGER;
        
        // Sticks & System
        if (gamepad.leftThumbstickButton.isPressed) buttons |= BTN_LEFT_THUMB;
        if (gamepad.rightThumbstickButton.isPressed) buttons |= BTN_RIGHT_THUMB;
        if (gamepad.buttonMenu.isPressed) buttons |= BTN_START;
        if (gamepad.buttonOptions.isPressed) buttons |= BTN_BACK;
        
        float lx = gamepad.leftThumbstick.xAxis.value;
        float ly = gamepad.leftThumbstick.yAxis.value;
        
        [strongSelf.delegate gamepadInputChanged:buttons leftStickX:lx leftStickY:ly];
    };
}

@end
