#import "TouchOverlayView.h"

@interface TouchOverlayView () {
    uint32_t _currentButtons;
    UIImpactFeedbackGenerator *_haptic;
    
    // UI elements
    UIView *_dpadContainer;
    UIButton *_btnUp;
    UIButton *_btnDown;
    UIButton *_btnLeft;
    UIButton *_btnRight;
    
    // Attack buttons (Tekken diamond)
    UIButton *_btnLP; // X (1)
    UIButton *_btnRP; // Y (2)
    UIButton *_btnLK; // A (3)
    UIButton *_btnRK; // B (4)
    
    // Shortcuts (Macros)
    UIButton *_btn1Plus2; // LB
    UIButton *_btn3Plus4; // LT
    UIButton *_btn1Plus3; // RT
    UIButton *_btn2Plus4; // RB
    
    // System
    UIButton *_btnStart;
    UIButton *_btnBack;
    UIButton *_btnProMotion;
    UIButton *_btnToggleControls;
    
    BOOL _autoHidden;
}
@end

@implementation TouchOverlayView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        self.multipleTouchEnabled = YES;
        _haptic = [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleLight];
        [_haptic prepare];
        _isPromotion120hz = YES;
        
        [self setupControls];
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self updateControlLayout];
}

- (UIButton *)createButtonWithTitle:(NSString *)title tag:(NSInteger)tag color:(UIColor *)color {
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.tag = tag;
    [btn setTitle:title forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont boldSystemFontOfSize:15.0f];
    btn.backgroundColor = [color colorWithAlphaComponent:0.45f];
    btn.layer.cornerRadius = 24.0f;
    btn.layer.borderWidth = 1.5f;
    btn.layer.borderColor = [[UIColor whiteColor] colorWithAlphaComponent:0.6f].CGColor;
    
    [btn addTarget:self action:@selector(buttonDown:) forControlEvents:UIControlEventTouchDown];
    [btn addTarget:self action:@selector(buttonUp:) forControlEvents:UIControlEventTouchUpInside | UIControlEventTouchUpOutside | UIControlEventTouchCancel];
    
    [self addSubview:btn];
    return btn;
}

- (void)setupControls {
    // Top Bar Controls
    _btnStart = [self createButtonWithTitle:@"START" tag:BTN_START color:[UIColor grayColor]];
    _btnStart.layer.cornerRadius = 14.0f;
    _btnStart.titleLabel.font = [UIFont boldSystemFontOfSize:11.0f];
    
    _btnBack = [self createButtonWithTitle:@"SELECT" tag:BTN_BACK color:[UIColor grayColor]];
    _btnBack.layer.cornerRadius = 14.0f;
    _btnBack.titleLabel.font = [UIFont boldSystemFontOfSize:11.0f];
    
    _btnProMotion = [UIButton buttonWithType:UIButtonTypeCustom];
    [_btnProMotion setTitle:@"120Hz" forState:UIControlStateNormal];
    [_btnProMotion setTitleColor:[UIColor colorWithRed:0.2f green:1.0f blue:0.4f alpha:1.0f] forState:UIControlStateNormal];
    _btnProMotion.titleLabel.font = [UIFont boldSystemFontOfSize:11.0f];
    _btnProMotion.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.5f];
    _btnProMotion.layer.cornerRadius = 14.0f;
    _btnProMotion.layer.borderWidth = 1.0f;
    _btnProMotion.layer.borderColor = [UIColor colorWithRed:0.2f green:1.0f blue:0.4f alpha:0.7f].CGColor;
    [_btnProMotion addTarget:self action:@selector(toggleProMotionTapped) forControlEvents:UIControlEventTouchUpInside];
    [self addSubview:_btnProMotion];
    
    // D-Pad (Left side)
    UIColor *dpadColor = [UIColor colorWithWhite:0.2f alpha:1.0f];
    _btnUp = [self createButtonWithTitle:@"▲" tag:BTN_DPAD_UP color:dpadColor];
    _btnDown = [self createButtonWithTitle:@"▼" tag:BTN_DPAD_DOWN color:dpadColor];
    _btnLeft = [self createButtonWithTitle:@"◀" tag:BTN_DPAD_LEFT color:dpadColor];
    _btnRight = [self createButtonWithTitle:@"▶" tag:BTN_DPAD_RIGHT color:dpadColor];
    
    // Face Attack Buttons (Tekken Diamond on Right)
    // LP (1 / Square / X) - Blue
    _btnLP = [self createButtonWithTitle:@"LP (1)" tag:BTN_X color:[UIColor colorWithRed:0.1f green:0.4f blue:0.9f alpha:1.0f]];
    // RP (2 / Triangle / Y) - Yellow
    _btnRP = [self createButtonWithTitle:@"RP (2)" tag:BTN_Y color:[UIColor colorWithRed:0.9f green:0.7f blue:0.1f alpha:1.0f]];
    // LK (3 / Cross / A) - Green
    _btnLK = [self createButtonWithTitle:@"LK (3)" tag:BTN_A color:[UIColor colorWithRed:0.1f green:0.8f blue:0.3f alpha:1.0f]];
    // RK (4 / Circle / B) - Red
    _btnRK = [self createButtonWithTitle:@"RK (4)" tag:BTN_B color:[UIColor colorWithRed:0.9f green:0.2f blue:0.2f alpha:1.0f]];
    
    // Fighting Macros
    _btn1Plus2 = [self createButtonWithTitle:@"1+2" tag:BTN_LEFT_SHOULDER color:[UIColor colorWithRed:0.6f green:0.3f blue:0.8f alpha:1.0f]];
    _btn3Plus4 = [self createButtonWithTitle:@"3+4" tag:BTN_LEFT_TRIGGER color:[UIColor colorWithRed:0.3f green:0.7f blue:0.8f alpha:1.0f]];
    _btn1Plus3 = [self createButtonWithTitle:@"1+3" tag:BTN_RIGHT_TRIGGER color:[UIColor colorWithRed:0.8f green:0.5f blue:0.2f alpha:1.0f]];
    _btn2Plus4 = [self createButtonWithTitle:@"2+4" tag:BTN_RIGHT_SHOULDER color:[UIColor colorWithRed:0.8f green:0.2f blue:0.5f alpha:1.0f]];
}

- (void)updateControlLayout {
    CGFloat w = self.bounds.size.width;
    CGFloat h = self.bounds.size.height;
    if (w <= 0 || h <= 0) return;
    
    // Safe area top margin
    CGFloat top = 16.0f;
    _btnStart.frame = CGRectMake(w / 2.0f + 10.0f, top, 64.0f, 28.0f);
    _btnBack.frame = CGRectMake(w / 2.0f - 74.0f, top, 64.0f, 28.0f);
    _btnProMotion.frame = CGRectMake(w - 74.0f, top, 58.0f, 28.0f);
    
    // D-Pad sizing & positioning (bottom left)
    CGFloat dpadCenterLeft = 110.0f;
    CGFloat dpadCenterBottom = h - 110.0f;
    CGFloat dSize = 52.0f;
    CGFloat dSpacing = 42.0f;
    
    _btnUp.frame = CGRectMake(dpadCenterLeft - dSize/2.0f, dpadCenterBottom - dSpacing - dSize, dSize, dSize);
    _btnDown.frame = CGRectMake(dpadCenterLeft - dSize/2.0f, dpadCenterBottom + dSpacing, dSize, dSize);
    _btnLeft.frame = CGRectMake(dpadCenterLeft - dSpacing - dSize, dpadCenterBottom - dSize/2.0f, dSize, dSize);
    _btnRight.frame = CGRectMake(dpadCenterLeft + dSpacing, dpadCenterBottom - dSize/2.0f, dSize, dSize);
    
    // Attack Diamond sizing & positioning (bottom right)
    CGFloat atkCenterX = w - 120.0f;
    CGFloat atkCenterY = h - 110.0f;
    CGFloat btnSize = 56.0f;
    CGFloat radius = 48.0f;
    
    _btnLP.frame = CGRectMake(atkCenterX - radius - btnSize/2.0f, atkCenterY - btnSize/2.0f, btnSize, btnSize); // Left
    _btnRP.frame = CGRectMake(atkCenterX - btnSize/2.0f, atkCenterY - radius - btnSize/2.0f, btnSize, btnSize); // Top
    _btnLK.frame = CGRectMake(atkCenterX - btnSize/2.0f, atkCenterY + radius - btnSize/2.0f, btnSize, btnSize); // Bottom
    _btnRK.frame = CGRectMake(atkCenterX + radius - btnSize/2.0f, atkCenterY - btnSize/2.0f, btnSize, btnSize); // Right
    
    // Macro buttons positioned arc-above attack diamond
    CGFloat macroW = 44.0f;
    CGFloat macroH = 34.0f;
    _btn1Plus2.frame = CGRectMake(atkCenterX - 85.0f, atkCenterY - 115.0f, macroW, macroH);
    _btn3Plus4.frame = CGRectMake(atkCenterX - 35.0f, atkCenterY - 130.0f, macroW, macroH);
    _btn1Plus3.frame = CGRectMake(atkCenterX + 15.0f, atkCenterY - 130.0f, macroW, macroH);
    _btn2Plus4.frame = CGRectMake(atkCenterX + 65.0f, atkCenterY - 115.0f, macroW, macroH);
}

- (void)buttonDown:(UIButton *)sender {
    [_haptic impactOccurred];
    sender.transform = CGAffineTransformMakeScale(0.92f, 0.92f);
    sender.backgroundColor = [sender.backgroundColor colorWithAlphaComponent:0.85f];
    
    _currentButtons |= (uint32_t)sender.tag;
    if ([self.delegate respondsToSelector:@selector(touchInputChanged:)]) {
        [self.delegate touchInputChanged:_currentButtons];
    }
}

- (void)buttonUp:(UIButton *)sender {
    sender.transform = CGAffineTransformIdentity;
    sender.backgroundColor = [sender.backgroundColor colorWithAlphaComponent:0.45f];
    
    _currentButtons &= ~(uint32_t)sender.tag;
    if ([self.delegate respondsToSelector:@selector(touchInputChanged:)]) {
        [self.delegate touchInputChanged:_currentButtons];
    }
}

- (void)toggleProMotionTapped {
    [_haptic impactOccurred];
    _isPromotion120hz = !_isPromotion120hz;
    if (_isPromotion120hz) {
        [_btnProMotion setTitle:@"120Hz" forState:UIControlStateNormal];
        [_btnProMotion setTitleColor:[UIColor colorWithRed:0.2f green:1.0f blue:0.4f alpha:1.0f] forState:UIControlStateNormal];
        _btnProMotion.layer.borderColor = [UIColor colorWithRed:0.2f green:1.0f blue:0.4f alpha:0.7f].CGColor;
    } else {
        [_btnProMotion setTitle:@"60Hz" forState:UIControlStateNormal];
        [_btnProMotion setTitleColor:[UIColor colorWithRed:0.9f green:0.9f blue:0.2f alpha:1.0f] forState:UIControlStateNormal];
        _btnProMotion.layer.borderColor = [UIColor colorWithRed:0.9f green:0.9f blue:0.2f alpha:0.7f].CGColor;
    }
    
    if ([self.delegate respondsToSelector:@selector(togglePromotionRequested)]) {
        [self.delegate togglePromotionRequested];
    }
}

- (void)setControllerConnected:(BOOL)connected {
    _autoHidden = connected;
    [UIView animateWithDuration:0.25 animations:^{
        self.alpha = connected ? 0.0f : 1.0f;
    }];
}

@end
