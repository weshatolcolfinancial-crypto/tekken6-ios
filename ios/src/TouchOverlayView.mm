#import "TouchOverlayView.h"
#import <cmath>

@interface TouchOverlayView () {
    uint32_t _currentButtons;
    uint32_t _dpadButtons;
    UIImpactFeedbackGenerator *_haptic;
    
    // 8-Way D-Pad Component
    UIView *_dpadBase;
    UIView *_dpadKnob;
    CGPoint _dpadCenter;
    CGFloat _dpadRadius;
    UITouch *_activeDpadTouch;
    
    UILabel *_lblUp;
    UILabel *_lblDown;
    UILabel *_lblLeft;
    UILabel *_lblRight;
    
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
    UIButton *_btnRage;   // All
    
    // System controls
    UIButton *_btnStart;
    UIButton *_btnBack;
    UIButton *_btnProMotion;
    UIButton *_btnAspect;
    UIButton *_btnToggleControls;
    
    BOOL _autoHidden;
    BOOL _userHidden;
}
@end

@implementation TouchOverlayView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        self.multipleTouchEnabled = YES;
        self.userInteractionEnabled = YES;
        _haptic = [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleLight];
        [_haptic prepare];
        _isPromotion120Hz = YES;
        _isUltrawideFull = NO;
        _currentButtons = 0;
        _dpadButtons = 0;
        _dpadRadius = 65.0f;
        
        [self setupControls];
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self updateControlLayout];
}

#pragma mark - Control Creation Helpers

- (UIButton *)createFightButtonWithTitle:(NSString *)title
                               subTitle:(NSString *)sub
                                    tag:(NSInteger)tag
                             themeColor:(UIColor *)color {
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.tag = tag;
    
    // Two-line title: Title (LP) + Number (1)
    NSString *fullText = [NSString stringWithFormat:@"%@\n%@", title, sub];
    NSMutableAttributedString *attr = [[NSMutableAttributedString alloc] initWithString:fullText];
    [attr addAttribute:NSFontAttributeName value:[UIFont boldSystemFontOfSize:14.0f] range:NSMakeRange(0, title.length)];
    [attr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:11.0f weight:UIFontWeightMedium] range:NSMakeRange(title.length + 1, sub.length)];
    [attr addAttribute:NSForegroundColorAttributeName value:[UIColor whiteColor] range:NSMakeRange(0, fullText.length)];
    
    btn.titleLabel.numberOfLines = 2;
    btn.titleLabel.textAlignment = NSTextAlignmentCenter;
    [btn setAttributedTitle:attr forState:UIControlStateNormal];
    
    btn.backgroundColor = [UIColor colorWithRed:0.08f green:0.09f blue:0.12f alpha:0.75f];
    btn.layer.cornerRadius = 30.0f;
    btn.layer.borderWidth = 2.5f;
    btn.layer.borderColor = color.CGColor;
    btn.layer.shadowColor = color.CGColor;
    btn.layer.shadowOpacity = 0.6f;
    btn.layer.shadowRadius = 8.0f;
    btn.layer.shadowOffset = CGSizeZero;
    
    [btn addTarget:self action:@selector(buttonDown:) forControlEvents:UIControlEventTouchDown];
    [btn addTarget:self action:@selector(buttonUp:) forControlEvents:UIControlEventTouchUpInside | UIControlEventTouchUpOutside | UIControlEventTouchCancel];
    
    [self addSubview:btn];
    return btn;
}

- (UIButton *)createMacroButtonWithTitle:(NSString *)title tag:(NSInteger)tag color:(UIColor *)color {
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.tag = tag;
    [btn setTitle:title forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont boldSystemFontOfSize:12.0f];
    btn.backgroundColor = [UIColor colorWithRed:0.12f green:0.13f blue:0.18f alpha:0.75f];
    btn.layer.cornerRadius = 14.0f;
    btn.layer.borderWidth = 1.5f;
    btn.layer.borderColor = color.CGColor;
    
    [btn addTarget:self action:@selector(buttonDown:) forControlEvents:UIControlEventTouchDown];
    [btn addTarget:self action:@selector(buttonUp:) forControlEvents:UIControlEventTouchUpInside | UIControlEventTouchUpOutside | UIControlEventTouchCancel];
    
    [self addSubview:btn];
    return btn;
}

- (UIButton *)createSystemButtonWithTitle:(NSString *)title action:(SEL)action {
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setTitle:title forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor colorWithWhite:0.9f alpha:1.0f] forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont boldSystemFontOfSize:11.0f];
    btn.backgroundColor = [UIColor colorWithRed:0.08f green:0.08f blue:0.10f alpha:0.75f];
    btn.layer.cornerRadius = 12.0f;
    btn.layer.borderWidth = 1.0f;
    btn.layer.borderColor = [UIColor colorWithWhite:0.4f alpha:0.6f].CGColor;
    [btn addTarget:self action:action forControlEvents:UIControlEventTouchUpInside];
    [self addSubview:btn];
    return btn;
}

#pragma mark - Setup Controls

- (void)setupControls {
    // 1. 8-Way Floating D-Pad Base
    _dpadBase = [[UIView alloc] initWithFrame:CGRectMake(0, 0, _dpadRadius * 2, _dpadRadius * 2)];
    _dpadBase.backgroundColor = [UIColor colorWithRed:0.08f green:0.09f blue:0.13f alpha:0.72f];
    _dpadBase.layer.cornerRadius = _dpadRadius;
    _dpadBase.layer.borderWidth = 2.0f;
    _dpadBase.layer.borderColor = [UIColor colorWithWhite:0.5f alpha:0.6f].CGColor;
    _dpadBase.userInteractionEnabled = NO;
    
    // Direction indicators
    _lblUp = [self createDirectionLabel:@"▲"];
    _lblDown = [self createDirectionLabel:@"▼"];
    _lblLeft = [self createDirectionLabel:@"◀"];
    _lblRight = [self createDirectionLabel:@"▶"];
    [_dpadBase addSubview:_lblUp];
    [_dpadBase addSubview:_lblDown];
    [_dpadBase addSubview:_lblLeft];
    [_dpadBase addSubview:_lblRight];
    
    // Thumb Knob
    _dpadKnob = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 44.0f, 44.0f)];
    _dpadKnob.backgroundColor = [UIColor colorWithWhite:0.35f alpha:0.85f];
    _dpadKnob.layer.cornerRadius = 22.0f;
    _dpadKnob.layer.borderWidth = 1.5f;
    _dpadKnob.layer.borderColor = [UIColor colorWithWhite:0.9f alpha:0.8f].CGColor;
    _dpadKnob.userInteractionEnabled = NO;
    [_dpadBase addSubview:_dpadKnob];
    
    [self addSubview:_dpadBase];
    
    // 2. Tekken 4-Button Fight Diamond
    // LP (1 - Blue), RP (2 - Yellow), LK (3 - Green), RK (4 - Red)
    UIColor *colorLP = [UIColor colorWithRed:0.0f green:0.75f blue:1.0f alpha:1.0f]; // Cyan Blue
    UIColor *colorRP = [UIColor colorWithRed:1.0f green:0.84f blue:0.0f alpha:1.0f]; // Amber Yellow
    UIColor *colorLK = [UIColor colorWithRed:0.0f green:0.90f blue:0.46f alpha:1.0f]; // Emerald Green
    UIColor *colorRK = [UIColor colorWithRed:1.0f green:0.18f blue:0.30f alpha:1.0f]; // Flare Red
    
    _btnLP = [self createFightButtonWithTitle:@"LP" subTitle:@"1" tag:BTN_X themeColor:colorLP];
    _btnRP = [self createFightButtonWithTitle:@"RP" subTitle:@"2" tag:BTN_Y themeColor:colorRP];
    _btnLK = [self createFightButtonWithTitle:@"LK" subTitle:@"3" tag:BTN_A themeColor:colorLK];
    _btnRK = [self createFightButtonWithTitle:@"RK" subTitle:@"4" tag:BTN_B themeColor:colorRK];
    
    // 3. Fighting Macros Arc
    UIColor *macroColor = [UIColor colorWithRed:0.65f green:0.45f blue:0.95f alpha:1.0f];
    _btn1Plus2 = [self createMacroButtonWithTitle:@"1+2" tag:BTN_LEFT_SHOULDER color:macroColor];
    _btn3Plus4 = [self createMacroButtonWithTitle:@"3+4" tag:BTN_LEFT_TRIGGER color:macroColor];
    _btn1Plus3 = [self createMacroButtonWithTitle:@"1+3" tag:BTN_RIGHT_TRIGGER color:macroColor];
    _btn2Plus4 = [self createMacroButtonWithTitle:@"2+4" tag:BTN_RIGHT_SHOULDER color:macroColor];
    _btnRage = [self createMacroButtonWithTitle:@"RAGE" tag:BTN_RAGE_MACRO color:[UIColor colorWithRed:1.0f green:0.3f blue:0.1f alpha:1.0f]];
    
    // 4. System Top Bar
    _btnBack = [self createSystemButtonWithTitle:@"SELECT" action:@selector(selectButtonTapped)];
    _btnStart = [self createSystemButtonWithTitle:@"START" action:@selector(startButtonTapped)];
    _btnProMotion = [self createSystemButtonWithTitle:@"120Hz" action:@selector(toggleProMotionTapped)];
    _btnAspect = [self createSystemButtonWithTitle:@"16:9" action:@selector(toggleAspectTapped)];
    _btnToggleControls = [self createSystemButtonWithTitle:@"HIDE" action:@selector(toggleControlsTapped)];
    
    [self updateProMotionButtonUI];
    [self updateAspectRatioButton:_isUltrawideFull];
}

- (UILabel *)createDirectionLabel:(NSString *)text {
    UILabel *lbl = [[UILabel alloc] init];
    lbl.text = text;
    lbl.textColor = [UIColor colorWithWhite:0.8f alpha:0.8f];
    lbl.font = [UIFont boldSystemFontOfSize:13.0f];
    lbl.textAlignment = NSTextAlignmentCenter;
    return lbl;
}

#pragma mark - Layout

- (void)updateControlLayout {
    CGFloat w = self.bounds.size.width;
    CGFloat h = self.bounds.size.height;
    if (w <= 0 || h <= 0) return;
    
    // Read safe areas for Notch / Dynamic Island / Home Indicator
    UIEdgeInsets insets = UIEdgeInsetsZero;
    if (@available(iOS 11.0, *)) {
        insets = self.safeAreaInsets;
    }
    
    // Top Bar (Safely under status/notch area)
    CGFloat topY = MAX(insets.top, 14.0f);
    CGFloat sysBtnW = 54.0f;
    CGFloat sysBtnH = 26.0f;
    CGFloat sysSpacing = 8.0f;
    
    // Center cluster: SELECT & START
    CGFloat centerClusterX = w / 2.0f;
    _btnBack.frame = CGRectMake(centerClusterX - sysBtnW - sysSpacing/2.0f, topY, sysBtnW, sysBtnH);
    _btnStart.frame = CGRectMake(centerClusterX + sysSpacing/2.0f, topY, sysBtnW, sysBtnH);
    
    // Right cluster: 120Hz, 16:9, HIDE
    CGFloat rightSafeX = w - MAX(insets.right, 16.0f);
    _btnToggleControls.frame = CGRectMake(rightSafeX - sysBtnW, topY, sysBtnW, sysBtnH);
    _btnAspect.frame = CGRectMake(rightSafeX - sysBtnW * 2.0f - sysSpacing, topY, sysBtnW, sysBtnH);
    _btnProMotion.frame = CGRectMake(rightSafeX - sysBtnW * 3.0f - sysSpacing * 2.0f, topY, sysBtnW, sysBtnH);
    
    // Left D-Pad positioning (respecting left safe area notch & bottom home indicator)
    CGFloat dpadMarginLeft = MAX(insets.left + 50.0f, 115.0f);
    CGFloat dpadMarginBottom = MAX(insets.bottom + 55.0f, 105.0f);
    _dpadCenter = CGPointMake(dpadMarginLeft, h - dpadMarginBottom);
    
    _dpadBase.center = _dpadCenter;
    _dpadKnob.center = CGPointMake(_dpadRadius, _dpadRadius);
    
    // Position direction arrows inside D-Pad
    CGFloat padOffset = 14.0f;
    _lblUp.frame = CGRectMake(_dpadRadius - 12.0f, padOffset, 24.0f, 20.0f);
    _lblDown.frame = CGRectMake(_dpadRadius - 12.0f, _dpadRadius * 2 - padOffset - 20.0f, 24.0f, 20.0f);
    _lblLeft.frame = CGRectMake(padOffset, _dpadRadius - 10.0f, 20.0f, 20.0f);
    _lblRight.frame = CGRectMake(_dpadRadius * 2 - padOffset - 20.0f, _dpadRadius - 10.0f, 20.0f, 20.0f);
    
    // Right Attack Diamond (respecting right safe area & bottom home indicator)
    CGFloat atkCenterX = w - MAX(insets.right + 70.0f, 130.0f);
    CGFloat atkCenterY = h - MAX(insets.bottom + 60.0f, 110.0f);
    
    CGFloat btnSize = 60.0f;
    CGFloat diamondRadius = 52.0f;
    
    // Tekken Cross:
    // LP (1) = Left, RP (2) = Top, LK (3) = Bottom, RK (4) = Right
    _btnLP.frame = CGRectMake(atkCenterX - diamondRadius - btnSize/2.0f, atkCenterY - btnSize/2.0f, btnSize, btnSize);
    _btnRP.frame = CGRectMake(atkCenterX - btnSize/2.0f, atkCenterY - diamondRadius - btnSize/2.0f, btnSize, btnSize);
    _btnLK.frame = CGRectMake(atkCenterX - btnSize/2.0f, atkCenterY + diamondRadius - btnSize/2.0f, btnSize, btnSize);
    _btnRK.frame = CGRectMake(atkCenterX + diamondRadius - btnSize/2.0f, atkCenterY - btnSize/2.0f, btnSize, btnSize);
    
    // Macro Buttons Arc (Positioned ergonomically above attack diamond)
    CGFloat macroW = 46.0f;
    CGFloat macroH = 32.0f;
    CGFloat arcY = atkCenterY - diamondRadius - 48.0f;
    
    _btn1Plus2.frame = CGRectMake(atkCenterX - 95.0f, arcY + 8.0f, macroW, macroH);
    _btn3Plus4.frame = CGRectMake(atkCenterX - 45.0f, arcY - 4.0f, macroW, macroH);
    _btn1Plus3.frame = CGRectMake(atkCenterX + 5.0f, arcY - 4.0f, macroW, macroH);
    _btn2Plus4.frame = CGRectMake(atkCenterX + 55.0f, arcY + 8.0f, macroW, macroH);
    _btnRage.frame = CGRectMake(atkCenterX - 24.0f, arcY + 36.0f, 48.0f, 24.0f);
    _btnRage.layer.cornerRadius = 12.0f;
}

#pragma mark - 8-Way D-Pad Continuous Touch Tracking

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch *touch in touches) {
        CGPoint pt = [touch locationInView:self];
        if (hypot(pt.x - _dpadCenter.x, pt.y - _dpadCenter.y) <= _dpadRadius * 1.5f) {
            _activeDpadTouch = touch;
            [self handleDpadTouch:pt];
            break;
        }
    }
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch *touch in touches) {
        if (touch == _activeDpadTouch) {
            CGPoint pt = [touch locationInView:self];
            [self handleDpadTouch:pt];
            break;
        }
    }
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch *touch in touches) {
        if (touch == _activeDpadTouch) {
            _activeDpadTouch = nil;
            [self resetDpad];
            break;
        }
    }
}

- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self touchesEnded:touches withEvent:event];
}

- (void)handleDpadTouch:(CGPoint)point {
    CGFloat dx = point.x - _dpadCenter.x;
    CGFloat dy = point.y - _dpadCenter.y;
    CGFloat dist = hypot(dx, dy);
    
    // Clamp knob position inside base
    CGFloat maxKnobOffset = _dpadRadius * 0.65f;
    CGFloat knobX = _dpadRadius;
    CGFloat knobY = _dpadRadius;
    
    if (dist > 0.001f) {
        CGFloat clampedDist = MIN(dist, maxKnobOffset);
        knobX = _dpadRadius + (dx / dist) * clampedDist;
        knobY = _dpadRadius + (dy / dist) * clampedDist;
    }
    _dpadKnob.center = CGPointMake(knobX, knobY);
    
    // Deadzone
    if (dist < 12.0f) {
        _dpadButtons = 0;
        [self emitCombinedButtons];
        return;
    }
    
    // Angle in degrees (-180 to 180)
    CGFloat angle = atan2(dy, dx) * (180.0f / M_PI);
    
    uint32_t newDpad = 0;
    
    // 8-Direction Sectors (45 degrees each)
    if (angle >= -22.5f && angle <= 22.5f) {
        newDpad = BTN_DPAD_RIGHT;
    } else if (angle > 22.5f && angle < 67.5f) {
        newDpad = BTN_DPAD_DOWN | BTN_DPAD_RIGHT; // Down-Forward
    } else if (angle >= 67.5f && angle <= 112.5f) {
        newDpad = BTN_DPAD_DOWN;
    } else if (angle > 112.5f && angle < 157.5f) {
        newDpad = BTN_DPAD_DOWN | BTN_DPAD_LEFT;  // Down-Back
    } else if (angle >= 157.5f || angle <= -157.5f) {
        newDpad = BTN_DPAD_LEFT;
    } else if (angle > -157.5f && angle < -112.5f) {
        newDpad = BTN_DPAD_UP | BTN_DPAD_LEFT;    // Up-Back
    } else if (angle >= -112.5f && angle <= -67.5f) {
        newDpad = BTN_DPAD_UP;
    } else if (angle > -67.5f && angle < -22.5f) {
        newDpad = BTN_DPAD_UP | BTN_DPAD_RIGHT;   // Up-Forward
    }
    
    if (newDpad != _dpadButtons) {
        [_haptic impactOccurred];
        _dpadButtons = newDpad;
        [self emitCombinedButtons];
    }
}

- (void)resetDpad {
    [UIView animateWithDuration:0.1 animations:^{
        self->_dpadKnob.center = CGPointMake(self->_dpadRadius, self->_dpadRadius);
    }];
    _dpadButtons = 0;
    [self emitCombinedButtons];
}

#pragma mark - Button Actions

- (void)buttonDown:(UIButton *)sender {
    [_haptic impactOccurred];
    sender.transform = CGAffineTransformMakeScale(0.92f, 0.92f);
    
    _currentButtons |= (uint32_t)sender.tag;
    [self emitCombinedButtons];
}

- (void)buttonUp:(UIButton *)sender {
    sender.transform = CGAffineTransformIdentity;
    
    _currentButtons &= ~(uint32_t)sender.tag;
    [self emitCombinedButtons];
}

- (void)emitCombinedButtons {
    uint32_t combined = _currentButtons | _dpadButtons;
    if ([self.delegate respondsToSelector:@selector(touchInputChanged:)]) {
        [self.delegate touchInputChanged:combined];
    }
}

#pragma mark - System Actions

- (void)selectButtonTapped {
    [_haptic impactOccurred];
    [self pulseButtonAction:BTN_BACK];
}

- (void)startButtonTapped {
    [_haptic impactOccurred];
    [self pulseButtonAction:BTN_START];
}

- (void)pulseButtonAction:(uint32_t)btnTag {
    _currentButtons |= btnTag;
    [self emitCombinedButtons];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.12 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self->_currentButtons &= ~btnTag;
        [self emitCombinedButtons];
    });
}

- (void)setIsPromotion120Hz:(BOOL)isPromotion120Hz {
    _isPromotion120Hz = isPromotion120Hz;
    [self updateProMotionButtonUI];
}

- (void)updateProMotionButtonUI {
    if (_isPromotion120Hz) {
        [_btnProMotion setTitle:@"120Hz" forState:UIControlStateNormal];
        [_btnProMotion setTitleColor:[UIColor colorWithRed:0.2f green:1.0f blue:0.4f alpha:1.0f] forState:UIControlStateNormal];
        _btnProMotion.layer.borderColor = [UIColor colorWithRed:0.2f green:1.0f blue:0.4f alpha:0.8f].CGColor;
    } else {
        [_btnProMotion setTitle:@"60Hz" forState:UIControlStateNormal];
        [_btnProMotion setTitleColor:[UIColor colorWithRed:0.95f green:0.85f blue:0.2f alpha:1.0f] forState:UIControlStateNormal];
        _btnProMotion.layer.borderColor = [UIColor colorWithRed:0.95f green:0.85f blue:0.2f alpha:0.8f].CGColor;
    }
}

- (void)toggleProMotionTapped {
    [_haptic impactOccurred];
    _isPromotion120Hz = !_isPromotion120Hz;
    [self updateProMotionButtonUI];
    
    if ([self.delegate respondsToSelector:@selector(togglePromotionRequested)]) {
        [self.delegate togglePromotionRequested];
    }
}

- (void)toggleAspectTapped {
    [_haptic impactOccurred];
    _isUltrawideFull = !_isUltrawideFull;
    [self updateAspectRatioButton:_isUltrawideFull];
    
    if ([self.delegate respondsToSelector:@selector(toggleAspectRatioRequested)]) {
        [self.delegate toggleAspectRatioRequested];
    }
}

- (void)updateAspectRatioButton:(BOOL)isFull {
    if (isFull) {
        [_btnAspect setTitle:@"FULL" forState:UIControlStateNormal];
        [_btnAspect setTitleColor:[UIColor colorWithRed:0.0f green:0.8f blue:1.0f alpha:1.0f] forState:UIControlStateNormal];
        _btnAspect.layer.borderColor = [UIColor colorWithRed:0.0f green:0.8f blue:1.0f alpha:0.8f].CGColor;
    } else {
        [_btnAspect setTitle:@"16:9" forState:UIControlStateNormal];
        [_btnAspect setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        _btnAspect.layer.borderColor = [UIColor colorWithWhite:0.5f alpha:0.6f].CGColor;
    }
}

- (void)toggleControlsTapped {
    [_haptic impactOccurred];
    _userHidden = !_userHidden;
    
    CGFloat targetAlpha = _userHidden ? 0.15f : 1.0f;
    [UIView animateWithDuration:0.2 animations:^{
        self->_dpadBase.alpha = targetAlpha;
        self->_btnLP.alpha = targetAlpha;
        self->_btnRP.alpha = targetAlpha;
        self->_btnLK.alpha = targetAlpha;
        self->_btnRK.alpha = targetAlpha;
        self->_btn1Plus2.alpha = targetAlpha;
        self->_btn3Plus4.alpha = targetAlpha;
        self->_btn1Plus3.alpha = targetAlpha;
        self->_btn2Plus4.alpha = targetAlpha;
        self->_btnRage.alpha = targetAlpha;
        [self->_btnToggleControls setTitle:self->_userHidden ? @"SHOW" : @"HIDE" forState:UIControlStateNormal];
    }];
}

- (void)setControllerConnected:(BOOL)connected {
    _autoHidden = connected;
    [UIView animateWithDuration:0.25 animations:^{
        self.alpha = (connected && !self->_userHidden) ? 0.0f : 1.0f;
    }];
}

@end
