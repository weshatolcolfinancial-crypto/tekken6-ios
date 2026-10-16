#import "TouchOverlayView.h"
#import "TekkenLogger.h"
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
    UILabel *_lblUpRight;
    UILabel *_lblDownRight;
    UILabel *_lblDownLeft;
    UILabel *_lblUpLeft;
    
    // Attack buttons (Arcade 2x2 Slanted Matrix)
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
    UIButton *_btnSize;
    UIButton *_btnOpacity;
    UIButton *_btnLogs;
    UIButton *_btnToggleControls;
    
    // Live On-Screen Log Drawer
    UIView *_logDrawerView;
    UITextView *_logTextView;
    UILabel *_logTitleLabel;
    UILabel *_logStatusBadge;
    UIButton *_btnCopyLogs;
    UIButton *_btnClearLogs;
    UIButton *_btnRefreshLogs;
    UIButton *_btnCloseLogs;
    BOOL _isLogsDrawerOpen;
    
    BOOL _autoHidden;
    BOOL _userHidden;
    NSArray<NSNumber *> *_opacityLevels;
    NSInteger _currentOpacityIndex;
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
        _layoutSize = TouchLayoutSizeNormal;
        _currentButtons = 0;
        _dpadButtons = 0;
        _dpadRadius = 70.0f;
        _isLogsDrawerOpen = NO;
        
        _opacityLevels = @[@1.0f, @0.75f, @0.50f, @0.25f];
        _currentOpacityIndex = 0;
        _controlsOpacity = 1.0f;
        
        [self setupControls];
        [self setupLogsDrawer];
        
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(handleLogNotification:)
                                                     name:TekkenLogUpdatedNotification
                                                   object:nil];
    }
    return self;
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self updateControlLayout];
}

#pragma mark - Control Creation Helpers

- (UIButton *)createFightButtonWithTitle:(NSString *)title
                                subTitle:(NSString *)sub
                               xboxLabel:(NSString *)xbox
                                     tag:(NSInteger)tag
                              themeColor:(UIColor *)color {
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.tag = tag;
    
    // 3-part layout: Title (LP), Number (1), Xbox hint ([X])
    NSString *fullText = [NSString stringWithFormat:@"%@\n%@  %@", title, sub, xbox];
    NSMutableAttributedString *attr = [[NSMutableAttributedString alloc] initWithString:fullText];
    
    [attr addAttribute:NSFontAttributeName value:[UIFont boldSystemFontOfSize:15.0f] range:NSMakeRange(0, title.length)];
    [attr addAttribute:NSForegroundColorAttributeName value:[UIColor whiteColor] range:NSMakeRange(0, title.length)];
    
    NSInteger subStart = title.length + 1;
    [attr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:12.0f weight:UIFontWeightHeavy] range:NSMakeRange(subStart, sub.length)];
    [attr addAttribute:NSForegroundColorAttributeName value:color range:NSMakeRange(subStart, sub.length)];
    
    NSInteger xboxStart = subStart + sub.length + 2;
    [attr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:9.0f weight:UIFontWeightRegular] range:NSMakeRange(xboxStart, xbox.length)];
    [attr addAttribute:NSForegroundColorAttributeName value:[UIColor colorWithWhite:0.7f alpha:0.8f] range:NSMakeRange(xboxStart, xbox.length)];
    
    btn.titleLabel.numberOfLines = 2;
    btn.titleLabel.textAlignment = NSTextAlignmentCenter;
    [btn setAttributedTitle:attr forState:UIControlStateNormal];
    
    btn.backgroundColor = [UIColor colorWithRed:0.07f green:0.08f blue:0.12f alpha:0.82f];
    btn.layer.borderWidth = 2.5f;
    btn.layer.borderColor = color.CGColor;
    btn.layer.shadowColor = color.CGColor;
    btn.layer.shadowOpacity = 0.7f;
    btn.layer.shadowRadius = 10.0f;
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
    btn.backgroundColor = [UIColor colorWithRed:0.10f green:0.11f blue:0.16f alpha:0.82f];
    btn.layer.cornerRadius = 14.0f;
    btn.layer.borderWidth = 1.5f;
    btn.layer.borderColor = color.CGColor;
    btn.layer.shadowColor = color.CGColor;
    btn.layer.shadowOpacity = 0.5f;
    btn.layer.shadowRadius = 6.0f;
    btn.layer.shadowOffset = CGSizeZero;
    
    [btn addTarget:self action:@selector(buttonDown:) forControlEvents:UIControlEventTouchDown];
    [btn addTarget:self action:@selector(buttonUp:) forControlEvents:UIControlEventTouchUpInside | UIControlEventTouchUpOutside | UIControlEventTouchCancel];
    
    [self addSubview:btn];
    return btn;
}

- (UIButton *)createSystemButtonWithTitle:(NSString *)title action:(SEL)action {
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setTitle:title forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor colorWithWhite:0.92f alpha:1.0f] forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont boldSystemFontOfSize:11.0f];
    btn.backgroundColor = [UIColor colorWithRed:0.08f green:0.09f blue:0.14f alpha:0.85f];
    btn.layer.cornerRadius = 12.0f;
    btn.layer.borderWidth = 1.0f;
    btn.layer.borderColor = [UIColor colorWithWhite:0.35f alpha:0.7f].CGColor;
    [btn addTarget:self action:action forControlEvents:UIControlEventTouchUpInside];
    [self addSubview:btn];
    return btn;
}

#pragma mark - Setup Controls

- (void)setupControls {
    // 1. 8-Way D-Pad Base
    _dpadBase = [[UIView alloc] initWithFrame:CGRectMake(0, 0, _dpadRadius * 2, _dpadRadius * 2)];
    _dpadBase.backgroundColor = [UIColor colorWithRed:0.06f green:0.08f blue:0.12f alpha:0.80f];
    _dpadBase.layer.cornerRadius = _dpadRadius;
    _dpadBase.layer.borderWidth = 2.0f;
    _dpadBase.layer.borderColor = [UIColor colorWithRed:0.0f green:0.8f blue:1.0f alpha:0.6f].CGColor;
    _dpadBase.layer.shadowColor = [UIColor colorWithRed:0.0f green:0.8f blue:1.0f alpha:0.5f].CGColor;
    _dpadBase.layer.shadowRadius = 8.0f;
    _dpadBase.layer.shadowOpacity = 0.5f;
    _dpadBase.userInteractionEnabled = NO;
    
    // Cardinal & Diagonal Direction Indicators
    _lblUp = [self createDirectionLabel:@"▲"];
    _lblDown = [self createDirectionLabel:@"▼"];
    _lblLeft = [self createDirectionLabel:@"◀"];
    _lblRight = [self createDirectionLabel:@"▶"];
    _lblUpRight = [self createDirectionLabel:@"↗"];
    _lblDownRight = [self createDirectionLabel:@"↘"];
    _lblDownLeft = [self createDirectionLabel:@"↙"];
    _lblUpLeft = [self createDirectionLabel:@"↖"];
    
    [_dpadBase addSubview:_lblUp];
    [_dpadBase addSubview:_lblDown];
    [_dpadBase addSubview:_lblLeft];
    [_dpadBase addSubview:_lblRight];
    [_dpadBase addSubview:_lblUpRight];
    [_dpadBase addSubview:_lblDownRight];
    [_dpadBase addSubview:_lblDownLeft];
    [_dpadBase addSubview:_lblUpLeft];
    
    // Center Thumb Knob
    _dpadKnob = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 48.0f, 48.0f)];
    _dpadKnob.backgroundColor = [UIColor colorWithRed:0.25f green:0.28f blue:0.38f alpha:0.90f];
    _dpadKnob.layer.cornerRadius = 24.0f;
    _dpadKnob.layer.borderWidth = 2.0f;
    _dpadKnob.layer.borderColor = [UIColor colorWithRed:0.0f green:0.9f blue:1.0f alpha:0.9f].CGColor;
    _dpadKnob.layer.shadowColor = [UIColor colorWithRed:0.0f green:0.9f blue:1.0f alpha:0.6f].CGColor;
    _dpadKnob.layer.shadowRadius = 6.0f;
    _dpadKnob.layer.shadowOpacity = 0.8f;
    _dpadKnob.userInteractionEnabled = NO;
    [_dpadBase addSubview:_dpadKnob];
    
    [self addSubview:_dpadBase];
    
    // 2. Authentic Arcade 2x2 Slanted Fight Matrix
    // LP (1 - Cyan), RP (2 - Yellow), LK (3 - Green), RK (4 - Red)
    UIColor *colorLP = [UIColor colorWithRed:0.0f green:0.90f blue:1.0f alpha:1.0f];  // Cyan Punch 1
    UIColor *colorRP = [UIColor colorWithRed:1.0f green:0.84f blue:0.0f alpha:1.0f];  // Amber Punch 2
    UIColor *colorLK = [UIColor colorWithRed:0.0f green:0.92f blue:0.46f alpha:1.0f]; // Emerald Kick 3
    UIColor *colorRK = [UIColor colorWithRed:1.0f green:0.18f blue:0.32f alpha:1.0f]; // Crimson Kick 4
    
    _btnLP = [self createFightButtonWithTitle:@"LP" subTitle:@"1" xboxLabel:@"[X]" tag:BTN_X themeColor:colorLP];
    _btnRP = [self createFightButtonWithTitle:@"RP" subTitle:@"2" xboxLabel:@"[Y]" tag:BTN_Y themeColor:colorRP];
    _btnLK = [self createFightButtonWithTitle:@"LK" subTitle:@"3" xboxLabel:@"[A]" tag:BTN_A themeColor:colorLK];
    _btnRK = [self createFightButtonWithTitle:@"RK" subTitle:@"4" xboxLabel:@"[B]" tag:BTN_B themeColor:colorRK];
    
    // 3. Tekken Macro Shortcuts Arc
    UIColor *macroColor = [UIColor colorWithRed:0.75f green:0.45f blue:1.0f alpha:1.0f];
    _btn1Plus2 = [self createMacroButtonWithTitle:@"1+2" tag:BTN_LEFT_SHOULDER color:macroColor];
    _btn3Plus4 = [self createMacroButtonWithTitle:@"3+4" tag:BTN_LEFT_TRIGGER color:macroColor];
    _btn1Plus3 = [self createMacroButtonWithTitle:@"1+3" tag:BTN_RIGHT_TRIGGER color:macroColor];
    _btn2Plus4 = [self createMacroButtonWithTitle:@"2+4" tag:BTN_RIGHT_SHOULDER color:macroColor];
    _btnRage = [self createMacroButtonWithTitle:@"RAGE" tag:BTN_RAGE_MACRO color:[UIColor colorWithRed:1.0f green:0.35f blue:0.15f alpha:1.0f]];
    
    // 4. System Top Bar
    _btnBack = [self createSystemButtonWithTitle:@"SELECT" action:@selector(selectButtonTapped)];
    _btnStart = [self createSystemButtonWithTitle:@"START" action:@selector(startButtonTapped)];
    _btnProMotion = [self createSystemButtonWithTitle:@"120Hz" action:@selector(toggleProMotionTapped)];
    _btnAspect = [self createSystemButtonWithTitle:@"16:9" action:@selector(toggleAspectTapped)];
    _btnSize = [self createSystemButtonWithTitle:@"SIZE" action:@selector(toggleSizeTapped)];
    _btnOpacity = [self createSystemButtonWithTitle:@"100%" action:@selector(toggleOpacityTapped)];
    _btnLogs = [self createSystemButtonWithTitle:@"[LOGS]" action:@selector(toggleLogsDrawer)];
    _btnLogs.layer.borderColor = [UIColor colorWithRed:0.0f green:0.85f blue:1.0f alpha:0.8f].CGColor;
    _btnLogs.layer.borderWidth = 1.5f;
    [_btnLogs setTitleColor:[UIColor colorWithRed:0.0f green:0.85f blue:1.0f alpha:1.0f] forState:UIControlStateNormal];
    
    _btnToggleControls = [self createSystemButtonWithTitle:@"HIDE" action:@selector(toggleControlsTapped)];
    
    [self updateProMotionButtonUI];
    [self updateAspectRatioButton:_isUltrawideFull];
}

- (UILabel *)createDirectionLabel:(NSString *)text {
    UILabel *lbl = [[UILabel alloc] init];
    lbl.text = text;
    lbl.textColor = [UIColor colorWithWhite:0.6f alpha:0.6f];
    lbl.font = [UIFont boldSystemFontOfSize:11.0f];
    lbl.textAlignment = NSTextAlignmentCenter;
    return lbl;
}

#pragma mark - On-Screen Live Log Drawer

- (void)setupLogsDrawer {
    CGFloat w = self.bounds.size.width;
    CGFloat h = self.bounds.size.height;
    CGFloat drawerW = MIN(w - 32.0f, 680.0f);
    CGFloat drawerH = MIN(h - 80.0f, 320.0f);
    
    _logDrawerView = [[UIView alloc] initWithFrame:CGRectMake((w - drawerW)/2.0f, -drawerH - 20.0f, drawerW, drawerH)];
    _logDrawerView.backgroundColor = [UIColor colorWithRed:0.05f green:0.06f blue:0.09f alpha:0.96f];
    _logDrawerView.layer.cornerRadius = 16.0f;
    _logDrawerView.layer.borderWidth = 1.5f;
    _logDrawerView.layer.borderColor = [UIColor colorWithRed:0.0f green:0.8f blue:1.0f alpha:0.8f].CGColor;
    _logDrawerView.layer.shadowColor = [UIColor colorWithRed:0.0f green:0.8f blue:1.0f alpha:0.6f].CGColor;
    _logDrawerView.layer.shadowRadius = 14.0f;
    _logDrawerView.layer.shadowOpacity = 0.6f;
    _logDrawerView.layer.shadowOffset = CGSizeZero;
    _logDrawerView.clipsToBounds = YES;
    
    // Header Bar
    UIView *header = [[UIView alloc] initWithFrame:CGRectMake(0, 0, drawerW, 40)];
    header.backgroundColor = [UIColor colorWithRed:0.08f green:0.10f blue:0.16f alpha:1.0f];
    [_logDrawerView addSubview:header];
    
    _logTitleLabel = [[UILabel alloc] initWithFrame:CGRectMake(16, 8, 220, 24)];
    _logTitleLabel.text = @"TEKKEN 6 RUNTIME LOGS";
    _logTitleLabel.textColor = [UIColor whiteColor];
    _logTitleLabel.font = [UIFont boldSystemFontOfSize:12.0f];
    [header addSubview:_logTitleLabel];
    
    _logStatusBadge = [[UILabel alloc] initWithFrame:CGRectMake(240, 10, 110, 20)];
    _logStatusBadge.text = @"ACTIVE";
    _logStatusBadge.textColor = [UIColor colorWithRed:0.0f green:1.0f blue:0.5f alpha:1.0f];
    _logStatusBadge.font = [UIFont boldSystemFontOfSize:10.0f];
    _logStatusBadge.textAlignment = NSTextAlignmentCenter;
    _logStatusBadge.backgroundColor = [[UIColor colorWithRed:0.0f green:1.0f blue:0.5f alpha:0.15f] colorWithAlphaComponent:0.15f];
    _logStatusBadge.layer.cornerRadius = 8.0f;
    _logStatusBadge.layer.masksToBounds = YES;
    [header addSubview:_logStatusBadge];
    
    CGFloat btnW = 55.0f;
    CGFloat btnH = 26.0f;
    CGFloat curX = drawerW - 12.0f - btnW;
    
    _btnCloseLogs = [UIButton buttonWithType:UIButtonTypeCustom];
    _btnCloseLogs.frame = CGRectMake(curX, 7, btnW, btnH);
    _btnCloseLogs.backgroundColor = [UIColor colorWithRed:0.8f green:0.1f blue:0.2f alpha:0.8f];
    _btnCloseLogs.layer.cornerRadius = 8.0f;
    [_btnCloseLogs setTitle:@"CLOSE" forState:UIControlStateNormal];
    _btnCloseLogs.titleLabel.font = [UIFont boldSystemFontOfSize:10.0f];
    [_btnCloseLogs addTarget:self action:@selector(toggleLogsDrawer) forControlEvents:UIControlEventTouchUpInside];
    [header addSubview:_btnCloseLogs];
    
    curX -= (btnW + 6.0f);
    _btnCopyLogs = [UIButton buttonWithType:UIButtonTypeCustom];
    _btnCopyLogs.frame = CGRectMake(curX, 7, btnW, btnH);
    _btnCopyLogs.backgroundColor = [UIColor colorWithRed:0.15f green:0.18f blue:0.25f alpha:0.8f];
    _btnCopyLogs.layer.cornerRadius = 8.0f;
    [_btnCopyLogs setTitle:@"COPY" forState:UIControlStateNormal];
    _btnCopyLogs.titleLabel.font = [UIFont boldSystemFontOfSize:10.0f];
    [_btnCopyLogs addTarget:self action:@selector(copyLogsTapped) forControlEvents:UIControlEventTouchUpInside];
    [header addSubview:_btnCopyLogs];
    
    curX -= (btnW + 6.0f);
    _btnClearLogs = [UIButton buttonWithType:UIButtonTypeCustom];
    _btnClearLogs.frame = CGRectMake(curX, 7, btnW, btnH);
    _btnClearLogs.backgroundColor = [UIColor colorWithRed:0.15f green:0.18f blue:0.25f alpha:0.8f];
    _btnClearLogs.layer.cornerRadius = 8.0f;
    [_btnClearLogs setTitle:@"CLEAR" forState:UIControlStateNormal];
    _btnClearLogs.titleLabel.font = [UIFont boldSystemFontOfSize:10.0f];
    [_btnClearLogs addTarget:self action:@selector(clearLogsTapped) forControlEvents:UIControlEventTouchUpInside];
    [header addSubview:_btnClearLogs];
    
    curX -= (btnW + 6.0f);
    _btnRefreshLogs = [UIButton buttonWithType:UIButtonTypeCustom];
    _btnRefreshLogs.frame = CGRectMake(curX, 7, btnW, btnH);
    _btnRefreshLogs.backgroundColor = [UIColor colorWithRed:0.0f green:0.6f blue:0.8f alpha:0.8f];
    _btnRefreshLogs.layer.cornerRadius = 8.0f;
    [_btnRefreshLogs setTitle:@"RELOAD" forState:UIControlStateNormal];
    _btnRefreshLogs.titleLabel.font = [UIFont boldSystemFontOfSize:10.0f];
    [_btnRefreshLogs addTarget:self action:@selector(refreshLogsTapped) forControlEvents:UIControlEventTouchUpInside];
    [header addSubview:_btnRefreshLogs];
    
    // Log TextView
    _logTextView = [[UITextView alloc] initWithFrame:CGRectMake(12, 46, drawerW - 24, drawerH - 54)];
    _logTextView.backgroundColor = [UIColor clearColor];
    _logTextView.textColor = [UIColor colorWithRed:0.2f green:0.95f blue:0.5f alpha:1.0f];
    _logTextView.font = [UIFont fontWithName:@"Courier" size:11.0f] ?: [UIFont monospacedSystemFontOfSize:11.0f weight:UIFontWeightRegular];
    _logTextView.editable = NO;
    _logTextView.indicatorStyle = UIScrollViewIndicatorStyleWhite;
    [_logDrawerView addSubview:_logTextView];
    
    [self addSubview:_logDrawerView];
    
    [self refreshLogsContent];
}

- (void)toggleLogsDrawer {
    [_haptic impactOccurred];
    [self showLogsDrawer:!_isLogsDrawerOpen];
}

- (void)showLogsDrawer:(BOOL)show {
    _isLogsDrawerOpen = show;
    
    CGFloat w = self.bounds.size.width;
    CGFloat drawerW = _logDrawerView.bounds.size.width;
    CGFloat drawerH = _logDrawerView.bounds.size.height;
    
    UIEdgeInsets insets = UIEdgeInsetsZero;
    if (@available(iOS 11.0, *)) {
        insets = self.safeAreaInsets;
    }
    
    CGFloat targetY = show ? (MAX(insets.top, 16.0f) + 40.0f) : (-drawerH - 30.0f);
    
    if (show) {
        [self refreshLogsContent];
    }
    
    [UIView animateWithDuration:0.35 delay:0 usingSpringWithDamping:0.85 initialSpringVelocity:0.5 options:UIViewAnimationOptionCurveEaseInOut animations:^{
        self->_logDrawerView.frame = CGRectMake((w - drawerW)/2.0f, targetY, drawerW, drawerH);
        self->_btnLogs.backgroundColor = show ? [UIColor colorWithRed:0.0f green:0.75f blue:1.0f alpha:0.9f] : [UIColor colorWithRed:0.08f green:0.09f blue:0.14f alpha:0.85f];
        [self->_btnLogs setTitleColor:show ? [UIColor blackColor] : [UIColor colorWithRed:0.0f green:0.85f blue:1.0f alpha:1.0f] forState:UIControlStateNormal];
    } completion:nil];
}

- (void)refreshLogsContent {
    NSString *allLogs = [[TekkenLogger sharedLogger] fullLogText];
    _logTextView.text = allLogs;
    if (allLogs.length > 0) {
        [_logTextView scrollRangeToVisible:NSMakeRange(allLogs.length - 1, 1)];
    }
}

- (void)handleLogNotification:(NSNotification *)note {
    NSString *line = note.object;
    if (line) {
        [self appendLogLine:line];
    }
}

- (void)appendLogLine:(NSString *)line {
    if (!_logTextView) return;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        NSString *existing = self->_logTextView.text ?: @"";
        self->_logTextView.text = [existing stringByAppendingFormat:@"\n%@", line];
        if (self->_logTextView.text.length > 0) {
            [self->_logTextView scrollRangeToVisible:NSMakeRange(self->_logTextView.text.length - 1, 1)];
        }
    });
}

- (void)copyLogsTapped {
    [_haptic impactOccurred];
    [UIPasteboard generalPasteboard].string = _logTextView.text ?: @"";
    
    NSString *orig = _btnCopyLogs.titleLabel.text;
    [_btnCopyLogs setTitle:@"COPIED!" forState:UIControlStateNormal];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self->_btnCopyLogs setTitle:orig forState:UIControlStateNormal];
    });
}

- (void)clearLogsTapped {
    [_haptic impactOccurred];
    [[TekkenLogger sharedLogger] clearLogs];
    _logTextView.text = @"[Tekken 6 Logger] Logs cleared.";
}

- (void)refreshLogsTapped {
    [_haptic impactOccurred];
    [self refreshLogsContent];
}

- (void)setGameStatusBadgeText:(NSString *)text color:(UIColor *)color {
    _logStatusBadge.text = text;
    _logStatusBadge.textColor = color;
    _logStatusBadge.backgroundColor = [color colorWithAlphaComponent:0.15f];
}

#pragma mark - Layout Calculations (Arcade Slanted 2x2 Matrix)

- (void)updateControlLayout {
    CGFloat w = self.bounds.size.width;
    CGFloat h = self.bounds.size.height;
    if (w <= 0 || h <= 0) return;
    
    UIEdgeInsets insets = UIEdgeInsetsZero;
    if (@available(iOS 11.0, *)) {
        insets = self.safeAreaInsets;
    }
    
    // Top Bar (Safely under notch/island)
    CGFloat topY = MAX(insets.top, 12.0f);
    CGFloat sysBtnW = 54.0f;
    CGFloat sysBtnH = 26.0f;
    CGFloat sysSpacing = 6.0f;
    
    // Center cluster: SELECT & START
    CGFloat centerX = w / 2.0f;
    _btnBack.frame = CGRectMake(centerX - sysBtnW - sysSpacing/2.0f, topY, sysBtnW, sysBtnH);
    _btnStart.frame = CGRectMake(centerX + sysSpacing/2.0f, topY, sysBtnW, sysBtnH);
    
    // Right cluster: 120Hz, 16:9, SIZE, OPAC, [LOGS], HIDE
    CGFloat rightX = w - MAX(insets.right, 14.0f);
    _btnToggleControls.frame = CGRectMake(rightX - sysBtnW, topY, sysBtnW, sysBtnH);
    _btnLogs.frame = CGRectMake(rightX - sysBtnW * 2.0f - sysSpacing, topY, sysBtnW + 4.0f, sysBtnH);
    _btnOpacity.frame = CGRectMake(rightX - sysBtnW * 3.0f - sysSpacing * 2.0f - 4.0f, topY, sysBtnW, sysBtnH);
    _btnSize.frame = CGRectMake(rightX - sysBtnW * 4.0f - sysSpacing * 3.0f - 4.0f, topY, sysBtnW, sysBtnH);
    _btnAspect.frame = CGRectMake(rightX - sysBtnW * 5.0f - sysSpacing * 4.0f - 4.0f, topY, sysBtnW, sysBtnH);
    _btnProMotion.frame = CGRectMake(rightX - sysBtnW * 6.0f - sysSpacing * 5.0f - 4.0f, topY, sysBtnW, sysBtnH);
    
    // Scaling adjustments according to layout size preset
    CGFloat btnSize = 66.0f;
    CGFloat spacingX = 72.0f;
    CGFloat spacingY = 70.0f;
    CGFloat macroW = 48.0f;
    CGFloat macroH = 32.0f;
    
    switch (_layoutSize) {
        case TouchLayoutSizeLarge:
            btnSize = 76.0f;
            spacingX = 82.0f;
            spacingY = 80.0f;
            _dpadRadius = 82.0f;
            macroW = 54.0f;
            macroH = 36.0f;
            break;
        case TouchLayoutSizeCompact:
            btnSize = 56.0f;
            spacingX = 62.0f;
            spacingY = 60.0f;
            _dpadRadius = 60.0f;
            macroW = 42.0f;
            macroH = 28.0f;
            break;
        case TouchLayoutSizeNormal:
        default:
            btnSize = 66.0f;
            spacingX = 72.0f;
            spacingY = 70.0f;
            _dpadRadius = 70.0f;
            macroW = 48.0f;
            macroH = 32.0f;
            break;
    }
    
    // Left D-Pad positioning
    CGFloat dpadMarginLeft = MAX(insets.left + 45.0f, 110.0f);
    CGFloat dpadMarginBottom = MAX(insets.bottom + 50.0f, 95.0f);
    _dpadCenter = CGPointMake(dpadMarginLeft, h - dpadMarginBottom);
    
    _dpadBase.frame = CGRectMake(0, 0, _dpadRadius * 2, _dpadRadius * 2);
    _dpadBase.center = _dpadCenter;
    _dpadBase.layer.cornerRadius = _dpadRadius;
    
    _dpadKnob.center = CGPointMake(_dpadRadius, _dpadRadius);
    
    // Direction indicators placement
    CGFloat padOffset = 14.0f;
    _lblUp.frame = CGRectMake(_dpadRadius - 12.0f, padOffset, 24.0f, 20.0f);
    _lblDown.frame = CGRectMake(_dpadRadius - 12.0f, _dpadRadius * 2 - padOffset - 20.0f, 24.0f, 20.0f);
    _lblLeft.frame = CGRectMake(padOffset, _dpadRadius - 10.0f, 20.0f, 20.0f);
    _lblRight.frame = CGRectMake(_dpadRadius * 2 - padOffset - 20.0f, _dpadRadius - 10.0f, 20.0f, 20.0f);
    
    CGFloat diagOffset = _dpadRadius * 0.32f;
    _lblUpLeft.frame = CGRectMake(_dpadRadius - diagOffset - 10.0f, _dpadRadius - diagOffset - 10.0f, 20.0f, 20.0f);
    _lblUpRight.frame = CGRectMake(_dpadRadius + diagOffset - 10.0f, _dpadRadius - diagOffset - 10.0f, 20.0f, 20.0f);
    _lblDownLeft.frame = CGRectMake(_dpadRadius - diagOffset - 10.0f, _dpadRadius + diagOffset - 10.0f, 20.0f, 20.0f);
    _lblDownRight.frame = CGRectMake(_dpadRadius + diagOffset - 10.0f, _dpadRadius + diagOffset - 10.0f, 20.0f, 20.0f);
    
    // Right Attack Cluster: Authentic Arcade 2x2 Matrix with Ergonomic Thumb Slant
    CGFloat atkCenterX = w - MAX(insets.right + 70.0f, 130.0f);
    CGFloat atkCenterY = h - MAX(insets.bottom + 55.0f, 100.0f);
    
    // Slant angle (18 degrees upwards to right)
    CGFloat angle = 18.0f * (M_PI / 180.0f);
    CGFloat cosA = cosf(angle);
    CGFloat sinA = sinf(angle);
    
    // Local 2x2 matrix unrotated offsets:
    // Top-left: (-spacingX/2, -spacingY/2)  -> LP (1)
    // Top-right: (+spacingX/2, -spacingY/2) -> RP (2)
    // Bottom-left: (-spacingX/2, +spacingY/2)  -> LK (3)
    // Bottom-right: (+spacingX/2, +spacingY/2) -> RK (4)
    auto rotatePoint = [&](CGFloat lx, CGFloat ly) -> CGPoint {
        CGFloat rx = lx * cosA - ly * sinA;
        CGFloat ry = lx * sinA + ly * cosA;
        return CGPointMake(atkCenterX + rx, atkCenterY + ry);
    };
    
    CGPoint ptLP = rotatePoint(-spacingX/2.0f, -spacingY/2.0f);
    CGPoint ptRP = rotatePoint(+spacingX/2.0f, -spacingY/2.0f);
    CGPoint ptLK = rotatePoint(-spacingX/2.0f, +spacingY/2.0f);
    CGPoint ptRK = rotatePoint(+spacingX/2.0f, +spacingY/2.0f);
    
    _btnLP.frame = CGRectMake(ptLP.x - btnSize/2.0f, ptLP.y - btnSize/2.0f, btnSize, btnSize);
    _btnRP.frame = CGRectMake(ptRP.x - btnSize/2.0f, ptRP.y - btnSize/2.0f, btnSize, btnSize);
    _btnLK.frame = CGRectMake(ptLK.x - btnSize/2.0f, ptLK.y - btnSize/2.0f, btnSize, btnSize);
    _btnRK.frame = CGRectMake(ptRK.x - btnSize/2.0f, ptRK.y - btnSize/2.0f, btnSize, btnSize);
    
    _btnLP.layer.cornerRadius = btnSize / 2.0f;
    _btnRP.layer.cornerRadius = btnSize / 2.0f;
    _btnLK.layer.cornerRadius = btnSize / 2.0f;
    _btnRK.layer.cornerRadius = btnSize / 2.0f;
    
    // Macro Buttons Arc (Comfortably above the 4 attack buttons)
    CGFloat arcBaseY = atkCenterY - spacingY - 26.0f;
    _btn1Plus2.frame = CGRectMake(atkCenterX - spacingX - 18.0f, arcBaseY + 12.0f, macroW, macroH);
    _btn3Plus4.frame = CGRectMake(atkCenterX - spacingX/2.0f - 8.0f, arcBaseY - 2.0f, macroW, macroH);
    _btn1Plus3.frame = CGRectMake(atkCenterX + 8.0f, arcBaseY - 2.0f, macroW, macroH);
    _btn2Plus4.frame = CGRectMake(atkCenterX + spacingX/2.0f + 18.0f, arcBaseY + 12.0f, macroW, macroH);
    
    _btnRage.frame = CGRectMake(atkCenterX - 28.0f, arcBaseY - 36.0f, 56.0f, 26.0f);
    _btnRage.layer.cornerRadius = 13.0f;
    
    // Logs drawer resizing
    if (_logDrawerView) {
        CGFloat drawerW = MIN(w - 32.0f, 680.0f);
        CGFloat drawerH = MIN(h - 80.0f, 320.0f);
        CGFloat targetY = _isLogsDrawerOpen ? (MAX(insets.top, 16.0f) + 40.0f) : (-drawerH - 30.0f);
        _logDrawerView.frame = CGRectMake((w - drawerW)/2.0f, targetY, drawerW, drawerH);
        _logTextView.frame = CGRectMake(12, 46, drawerW - 24, drawerH - 54);
    }
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
    if (dist < 14.0f) {
        _dpadButtons = 0;
        [self updateDpadVisuals:0];
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
        newDpad = BTN_DPAD_DOWN | BTN_DPAD_RIGHT; // Down-Forward (d/f)
    } else if (angle >= 67.5f && angle <= 112.5f) {
        newDpad = BTN_DPAD_DOWN;
    } else if (angle > 112.5f && angle < 157.5f) {
        newDpad = BTN_DPAD_DOWN | BTN_DPAD_LEFT;  // Down-Back (d/b)
    } else if (angle >= 157.5f || angle <= -157.5f) {
        newDpad = BTN_DPAD_LEFT;
    } else if (angle > -157.5f && angle < -112.5f) {
        newDpad = BTN_DPAD_UP | BTN_DPAD_LEFT;    // Up-Back (u/b)
    } else if (angle >= -112.5f && angle <= -67.5f) {
        newDpad = BTN_DPAD_UP;
    } else if (angle > -67.5f && angle < -22.5f) {
        newDpad = BTN_DPAD_UP | BTN_DPAD_RIGHT;   // Up-Forward (u/f)
    }
    
    if (newDpad != _dpadButtons) {
        [_haptic impactOccurred];
        _dpadButtons = newDpad;
        [self updateDpadVisuals:newDpad];
        [self emitCombinedButtons];
    }
}

- (void)updateDpadVisuals:(uint32_t)buttons {
    UIColor *activeColor = [UIColor colorWithRed:0.0f green:0.95f blue:1.0f alpha:1.0f];
    UIColor *inactiveColor = [UIColor colorWithWhite:0.6f alpha:0.6f];
    
    _lblUp.textColor = (buttons & BTN_DPAD_UP) ? activeColor : inactiveColor;
    _lblDown.textColor = (buttons & BTN_DPAD_DOWN) ? activeColor : inactiveColor;
    _lblLeft.textColor = (buttons & BTN_DPAD_LEFT) ? activeColor : inactiveColor;
    _lblRight.textColor = (buttons & BTN_DPAD_RIGHT) ? activeColor : inactiveColor;
    
    _lblUpRight.textColor = ((buttons & BTN_DPAD_UP) && (buttons & BTN_DPAD_RIGHT)) ? activeColor : inactiveColor;
    _lblDownRight.textColor = ((buttons & BTN_DPAD_DOWN) && (buttons & BTN_DPAD_RIGHT)) ? activeColor : inactiveColor;
    _lblDownLeft.textColor = ((buttons & BTN_DPAD_DOWN) && (buttons & BTN_DPAD_LEFT)) ? activeColor : inactiveColor;
    _lblUpLeft.textColor = ((buttons & BTN_DPAD_UP) && (buttons & BTN_DPAD_LEFT)) ? activeColor : inactiveColor;
}

- (void)resetDpad {
    [UIView animateWithDuration:0.12 animations:^{
        self->_dpadKnob.center = CGPointMake(self->_dpadRadius, self->_dpadRadius);
    }];
    _dpadButtons = 0;
    [self updateDpadVisuals:0];
    [self emitCombinedButtons];
}

#pragma mark - Button Actions

- (void)buttonDown:(UIButton *)sender {
    [_haptic impactOccurred];
    sender.transform = CGAffineTransformMakeScale(0.92f, 0.92f);
    sender.alpha = 0.95f;
    
    _currentButtons |= (uint32_t)sender.tag;
    [self emitCombinedButtons];
}

- (void)buttonUp:(UIButton *)sender {
    sender.transform = CGAffineTransformIdentity;
    sender.alpha = _controlsOpacity;
    
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

- (void)toggleSizeTapped {
    [_haptic impactOccurred];
    switch (_layoutSize) {
        case TouchLayoutSizeNormal:
            _layoutSize = TouchLayoutSizeLarge;
            [_btnSize setTitle:@"LARGE" forState:UIControlStateNormal];
            break;
        case TouchLayoutSizeLarge:
            _layoutSize = TouchLayoutSizeCompact;
            [_btnSize setTitle:@"SMALL" forState:UIControlStateNormal];
            break;
        case TouchLayoutSizeCompact:
        default:
            _layoutSize = TouchLayoutSizeNormal;
            [_btnSize setTitle:@"SIZE" forState:UIControlStateNormal];
            break;
    }
    
    [UIView animateWithDuration:0.25 animations:^{
        [self updateControlLayout];
    }];
}

- (void)toggleOpacityTapped {
    [_haptic impactOccurred];
    _currentOpacityIndex = (_currentOpacityIndex + 1) % _opacityLevels.count;
    _controlsOpacity = _opacityLevels[_currentOpacityIndex].floatValue;
    
    NSString *pct = [NSString stringWithFormat:@"%.0f%%", _controlsOpacity * 100.0f];
    [_btnOpacity setTitle:pct forState:UIControlStateNormal];
    
    [UIView animateWithDuration:0.2 animations:^{
        [self applyOpacityToControls:self->_controlsOpacity];
    }];
}

- (void)applyOpacityToControls:(CGFloat)alpha {
    _dpadBase.alpha = alpha;
    _btnLP.alpha = alpha;
    _btnRP.alpha = alpha;
    _btnLK.alpha = alpha;
    _btnRK.alpha = alpha;
    _btn1Plus2.alpha = alpha;
    _btn3Plus4.alpha = alpha;
    _btn1Plus3.alpha = alpha;
    _btn2Plus4.alpha = alpha;
    _btnRage.alpha = alpha;
}

- (void)toggleControlsTapped {
    [_haptic impactOccurred];
    _userHidden = !_userHidden;
    
    CGFloat targetAlpha = _userHidden ? 0.08f : _controlsOpacity;
    [UIView animateWithDuration:0.25 animations:^{
        [self applyOpacityToControls:targetAlpha];
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
