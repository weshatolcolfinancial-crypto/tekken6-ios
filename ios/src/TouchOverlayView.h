#pragma once

#import <UIKit/UIKit.h>

// Xbox 360 gamepad button bitmask matching ReXGlue input state
enum TekkenInputButtons : uint32_t {
    BTN_DPAD_UP        = 1 << 0,
    BTN_DPAD_DOWN      = 1 << 1,
    BTN_DPAD_LEFT      = 1 << 2,
    BTN_DPAD_RIGHT     = 1 << 3,
    BTN_START          = 1 << 4,
    BTN_BACK           = 1 << 5,
    BTN_LEFT_THUMB     = 1 << 6,
    BTN_RIGHT_THUMB    = 1 << 7,
    BTN_LEFT_SHOULDER  = 1 << 8,  // LB (1+2 Macro)
    BTN_RIGHT_SHOULDER = 1 << 9,  // RB (2+4 Macro)
    BTN_A              = 1 << 12, // LK (3)
    BTN_B              = 1 << 13, // RK (4)
    BTN_X              = 1 << 14, // LP (1)
    BTN_Y              = 1 << 15, // RP (2)
    BTN_LEFT_TRIGGER   = 1 << 16, // LT (3+4 Macro)
    BTN_RIGHT_TRIGGER  = 1 << 17, // RT (1+3 Macro)
    BTN_RAGE_MACRO     = BTN_LEFT_SHOULDER | BTN_RIGHT_SHOULDER | BTN_LEFT_TRIGGER | BTN_RIGHT_TRIGGER, // 1+2+3+4
};

@protocol TouchOverlayDelegate <NSObject>
- (void)touchInputChanged:(uint32_t)pressedButtons;
- (void)togglePromotionRequested;
- (void)toggleAspectRatioRequested;
@end

@interface TouchOverlayView : UIView

@property (nonatomic, weak) id<TouchOverlayDelegate> delegate;
@property (nonatomic, assign) BOOL isPromotion120Hz;
@property (nonatomic, assign) BOOL isUltrawideFull;

- (void)setControllerConnected:(BOOL)connected;
- (void)updateAspectRatioButton:(BOOL)isFull;

@end
