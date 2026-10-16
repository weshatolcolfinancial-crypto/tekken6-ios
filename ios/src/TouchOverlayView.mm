#import "TouchOverlayView.h"
#import "TekkenLogger.h"
#import <cmath>

extern "C" {
    extern uint32_t g_tekken_current_buttons;
    extern float g_tekken_stick_x;
    extern float g_tekken_stick_y;
}

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
        _dpadRadius = 68.0f;
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
    
    [attr addAttribute:NSFontAttributeName value:[UIFont boldSystemFontOfSize:14.0f] range:NSMakeRange(0, title.length)];
    [attr addAttribute:NSForegroundColorAttributeName value:[UIColor whiteColor] range:NSMakeRange(0, title.length)];
    
    NSInteger subStart = title.length + 1;
    [attr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:12.0f weight:UIFontWeightHeavy] range:NSMakeRange(subStart, sub.length)];
    [attr addAttribute:NSForegroundColorAttributeName value:color range:NSMakeRange(subStart, sub.length)];
    
    NSInteger xboxStart = subStart + sub.length + 2;
    [attr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:9.0f weight:UIFontWeightRegular] range:NSMakeRange(xboxStart, xbox.length)];
    [attr addAttribute:NSForegroundColorAttributeName value:[UIColor colorWithWhite:0.75f alpha:0.8f] range:NSMakeRange(xboxStart, xbox.length)];
    
    btn.titleLabel.numberOfLines = 2;
    btn.titleLabel.textAlignment = NSTextAlignmentCenter;
    [btn setAttributedTitle:attr forState:UIControlStateNormal];
    
    btn.backgroundColor = [UIColor colorWithRed:0.07f green:0.08f blue:0.12f alpha:0.85f];
    btn.layer.borderWidth = 2.0f;
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
    btn.titleLabel.font = [UIFont boldSystemFontOfSize:11.0f];
    btn.backgroundColor = [UIColor colorWithRed:0.10f green:0.11f blue:0.16f alpha:0.85f];
    btn.layer.cornerRadius = 12.0f;
    btn.layer.borderWidth = 1.5f;
    btn.layer.borderColor = color.CGColor;
    btn.layer.shadowColor = color.CGColor;
    btn.layer.shadowOpacity = 0.5f;
    btn.layer.shadowRadius = 5.0f;
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
    btn.titleLabel.font = [UIFont boldSystemFontOfSize:10.5f];
    btn.backgroundColor = [UIColor colorWithRed:0.08f green:0.09f blue:0.14f alpha:0.88f];
    btn.layer.cornerRadius = 11.0f;
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
    _dpadBase.backgroundColor = [UIColor colorWithRed:0.06f green:0.08f blue:0.12f alpha:0.82f];
    _dpadBase.layer.cornerRadius = _dpadRadius;
    _dpadBase.layer.borderWidth = 2.0f;
    _dpadBase.layer.borderColor = [UIColor colorWithRed:0.0f green:0.8f blue:1.0f alpha:0.6f].CGColor;
    _dpadBase.userInteractionEnabled = NO;
    
    // Direction Indicators
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
    _dpadKnob = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 44.0f, 44.0f)];
    _dpadKnob.backgroundColor = [UIColor colorWithRed:0.25f green:0.28f blue:0.38f alpha:0.92f];
    _dpadKnob.layer.cornerRadius = 22.0f;
    _dpadKnob.layer.borderWidth = 1.5f;
    _dpadKnob.layer.borderColor = [UIColor colorWithRed:0.0f green:0.9f blue:1.0f alpha:0.9f].CGColor;
    _dpadKnob.userInteractionEnabled = NO;
    [_dpadBase addSubview:_dpadKnob];
    
    [self addSubview:_dpadBase];
    
    // 2. Authentic Arcade 2x2 Slanted Fight Matrix
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
    _btnLogs.layer.borderColor = [UIColor colorWithRed:0.0f green:0.85f blue:1.0f alpha:0.85f].CGColor;
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
    lbl.font = [UIFont boldSystemFontOfSize:10.0f];
    lbl.textAlignment = NSTextAlignmentCenter;
    return lbl;
}

#pragma mark - On-Screen Live Log Drawer

- (void)setupLogsDrawer {
    CGFloat w = self.bounds.size.width;
    CGFloat h = self.bounds.size.height;
    CGFloat drawerW = MIN(w - 24.0f, 660.0f);
    CGFloat drawerH = MIN(h - 50.0f, 300.0f);
    
    _logDrawerView = [[UIView alloc] initWithFrame:CGRectMake((w - drawerW)/2.0f, -drawerH - 30.0f, drawerW, drawerH)];
    _logDrawerView.backgroundColor = [UIColor colorWithRed:0.05f green:0.06f blue:0.09f alpha:0.96f];
    _logDrawerView.layer.cornerRadius = 16.0f;
    _logDrawerView.layer.borderWidth = 1.5f;
    _logDrawerView.layer.borderColor = [UIColor colorWithRed:0.0f green:0.8f blue:1.0f alpha:0.8f].CGColor;
    _logDrawerView.clipsToBounds = YES;
    
    // Header Bar
    UIView *header = [[UIView alloc] initWithFrame:CGRectMake(0, 0, drawerW, 38)];
    header.backgroundColor = [UIColor colorWithRed:0.08f green:0.10f blue:0.16f alpha:1.0f];
    [_logDrawerView addSubview:header];
    
    _logTitleLabel = [[UILabel alloc] initWithFrame:CGRectMake(14, 8, 200, 22)];
    _logTitleLabel.text = @"TEKKEN 6 LOG CONSOLE";
    _logTitleLabel.textColor = [UIColor whiteColor];
    _logTitleLabel.font = [UIFont boldSystemFontOfSize:11.5f];
    [header addSubview:_logTitleLabel];
    
    _logStatusBadge = [[UILabel alloc] initWithFrame:CGRectMake(220, 9, 100, 20)];
    _logStatusBadge.text = @"ACTIVE";
    _logStatusBadge.textColor = [UIColor colorWithRed:0.0f green:1.0f blue:0.5f alpha:1.0f];
    _logStatusBadge.font = [UIFont boldSystemFontOfSize:9.5f];
    _logStatusBadge.textAlignment = NSTextAlignmentCenter;
    _logStatusBadge.backgroundColor = [[UIColor colorWithRed:0.0f green:1.0f blue:0.5f alpha:0.15f] colorWithAlphaComponent:0.15f];
    _logStatusBadge.layer.cornerRadius = 8.0f;
    _logStatusBadge.layer.masksToBounds = YES;
    [header addSubview:_logStatusBadge];
    
    CGFloat btnW = 50.0f;
    CGFloat btnH = 24.0f;
    CGFloat curX = drawerW - 10.0f - btnW;
    
    _btnCloseLogs = [UIButton buttonWithType:UIButtonTypeCustom];
    _btnCloseLogs.frame = CGRectMake(curX, 7, btnW, btnH);
    _btnCloseLogs.backgroundColor = [UIColor colorWithRed:0.8f green:0.1f blue:0.2f alpha:0.85f];
    _btnCloseLogs.layer.cornerRadius = 7.0f;
    [_btnCloseLogs setTitle:@"CLOSE" forState:UIControlStateNormal];
    _btnCloseLogs.titleLabel.font = [UIFont boldSystemFontOfSize:9.5f];
    [_btnCloseLogs addTarget:self action:@selector(toggleLogsDrawer) forControlEvents:UIControlEventTouchUpInside];
    [header addSubview:_btnCloseLogs];
    
    curX -= (btnW + 6.0f);
    _btnCopyLogs = [UIButton buttonWithType:UIButtonTypeCustom];
    _btnCopyLogs.frame = CGRectMake(curX, 7, btnW, btnH);
    _btnCopyLogs.backgroundColor = [UIColor colorWithRed:0.15f green:0.18f blue:0.25f alpha:0.85f];
    _btnCopyLogs.layer.cornerRadius = 7.0f;
    [_btnCopyLogs setTitle:@"COPY" forState:UIControlStateNormal];
    _btnCopyLogs.titleLabel.font = [UIFont boldSystemFontOfSize:9.5f];
    [_btnCopyLogs addTarget:self action:@selector(copyLogsTapped) forControlEvents:UIControlEventTouchUpInside];
    [header addSubview:_btnCopyLogs];
    
    curX -= (btnW + 6.0f);
    _btnClearLogs = [UIButton buttonWithType:UIButtonTypeCustom];
    _btnClearLogs.frame = CGRectMake(curX, 7, btnW, btnH);
    _btnClearLogs.backgroundColor = [UIColor colorWithRed:0.15f green:0.18f blue:0.25f alpha:0.85f];
    _btnClearLogs.layer.cornerRadius = 7.0f;
    [_btnClearLogs setTitle:@"CLEAR" forState:UIControlStateNormal];
    _btnClearLogs.titleLabel.font = [UIFont boldSystemFontOfSize:9.5f];
    [_btnClearLogs addTarget:self action:@selector(clearLogsTapped) forControlEvents:UIControlEventTouchUpInside];
    [header addSubview:_btnClearLogs];
    
    curX -= (btnW + 6.0f);
    _btnRefreshLogs = [UIButton buttonWithType:UIButtonTypeCustom];
    _btnRefreshLogs.frame = CGRectMake(curX, 7, btnW, btnH);
    _btnRefreshLogs.backgroundColor = [UIColor colorWithRed:0.0f green:0.6f blue:0.8f alpha:0.85f];
    _btnRefreshLogs.layer.cornerRadius = 7.0f;
    [_btnRefreshLogs setTitle:@"RELOAD" forState:UIControlStateNormal];
    _btnRefreshLogs.titleLabel.font = [UIFont boldSystemFontOfSize:9.5f];
    [_btnRefreshLogs addTarget:self action:@selector(refreshLogsTapped) forControlEvents:UIControlEventTouchUpInside];
    [header addSubview:_btnRefreshLogs];
    
    // Log TextView
    _logTextView = [[UITextView alloc] initWithFrame:CGRectMake(10, 42, drawerW - 20, drawerH - 48)];
    _logTextView.backgroundColor = [UIColor clearColor];
    _logTextView.textColor = [UIColor colorWithRed:0.2f green:0.95f blue:0.5f alpha:1.0f];
    _logTextView.font = [UIFont fontWithName:@"Courier" size:10.5f] ?: [UIFont monospacedSystemFontOfSize:10.5f weight:UIFontWeightRegular];
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
    
    CGFloat targetY = show ? (MAX(insets.top, 14.0f) + 38.0f) : (-drawerH - 30.0f);
    
    if (show) {
        [self refreshLogsContent];
    }
    
    [UIView animateWithDuration:0.35 delay:0 usingSpringWithDamping:0.85 initialSpringVelocity:0.5 options:UIViewAnimationOptionCurveEaseInOut animations:^{
        self->_logDrawerView.frame = CGRectMake((w - drawerW)/2.0f, targetY, drawerW, drawerH);
        self->_btnLogs.backgroundColor = show ? [UIColor colorWithRed:0.0f green:0.75f blue:1.0f alpha:0.9f] : [UIColor colorWithRed:0.08f green:0.09f blue:0.14f alpha:0.88f];
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

#pragma mark - Responsive Adaptive Layout (Prevents Any Overlap)

- (void)updateControlLayout {
    CGFloat w = self.bounds.size.width;
    CGFloat h = self.bounds.size.height;
    if (w <= 0 || h <= 0) return;
    
    UIEdgeInsets insets = UIEdgeInsetsZero;
    if (@available(iOS 11.0, *)) {
        insets = self.safeAreaInsets;
    }
    
    // Scale factor based on standard landscape resolution (852 x 393)
    CGFloat scale = MIN(w / 852.0f, h / 393.0f);
    scale = MAX(0.68f, MIN(scale, 1.25f));
    
    // Top Bar (Safely under notch/island)
    CGFloat topY = MAX(insets.top, 10.0f);
    CGFloat sysBtnW = 50.0f * scale;
    CGFloat sysBtnH = 25.0f;
    CGFloat sysSpacing = 5.0f;
    
    // Left cluster: [LOGS] and SIZE
    CGFloat leftX = MAX(insets.left, 14.0f);
    _btnLogs.frame = CGRectMake(leftX, topY, sysBtnW + 6.0f, sysBtnH);
    _btnSize.frame = CGRectMake(CGRectGetMaxX(_btnLogs.frame) + sysSpacing, topY, sysBtnW, sysBtnH);
    
    // Center cluster: SELECT & START
    CGFloat centerX = w / 2.0f;
    _btnBack.frame = CGRectMake(centerX - sysBtnW - sysSpacing/2.0f, topY, sysBtnW, sysBtnH);
    _btnStart.frame = CGRectMake(centerX + sysSpacing/2.0f, topY, sysBtnW, sysBtnH);
    
    // Right cluster: 120Hz, 16:9, OPAC, HIDE
    CGFloat rightX = w - MAX(insets.right, 14.0f);
    _btnToggleControls.frame = CGRectMake(rightX - sysBtnW, topY, sysBtnW, sysBtnH);
    _btnOpacity.frame = CGRectMake(rightX - sysBtnW * 2.0f - sysSpacing, topY, sysBtnW, sysBtnH);
    _btnAspect.frame = CGRectMake(rightX - sysBtnW * 3.0f - sysSpacing * 2.0f, topY, sysBtnW, sysBtnH);
    _btnProMotion.frame = CGRectMake(rightX - sysBtnW * 4.0f - sysSpacing * 3.0f, topY, sysBtnW, sysBtnH);
    
    // Scaling adjustments according to layout size preset
    CGFloat sizeMultiplier = 1.0f;
    switch (_layoutSize) {
        case TouchLayoutSizeLarge:
            sizeMultiplier = 1.15f;
            break;
        case TouchLayoutSizeCompact:
            sizeMultiplier = 0.85f;
            break;
        case TouchLayoutSizeNormal:
        default:
            sizeMultiplier = 1.0f;
            break;
    }
    
    CGFloat effectiveScale = scale * sizeMultiplier;
    CGFloat btnSize = 64.0f * effectiveScale;
    CGFloat spacingX = 72.0f * effectiveScale;
    CGFloat spacingY = 68.0f * effectiveScale;
    CGFloat macroW = 46.0f * effectiveScale;
    CGFloat macroH = 30.0f * effectiveScale;
    _dpadRadius = 66.0f * effectiveScale;
    
    // Left D-Pad positioning
    CGFloat dpadMarginLeft = MAX(insets.left + 35.0f * scale, 85.0f * scale);
    CGFloat dpadMarginBottom = MAX(insets.bottom + 40.0f * scale, 75.0f * scale);
    _dpadCenter = CGPointMake(dpadMarginLeft + _dpadRadius, h - dpadMarginBottom);
    
    _dpadBase.frame = CGRectMake(0, 0, _dpadRadius * 2, _dpadRadius * 2);
    _dpadBase.center = _dpadCenter;
    _dpadBase.layer.cornerRadius = _dpadRadius;
    
    CGFloat knobSize = 44.0f * effectiveScale;
    _dpadKnob.frame = CGRectMake(0, 0, knobSize, knobSize);
    _dpadKnob.layer.cornerRadius = knobSize / 2.0f;
    _dpadKnob.center = CGPointMake(_dpadRadius, _dpadRadius);
    
    // Direction indicators placement
    CGFloat padOffset = 12.0f * effectiveScale;
    _lblUp.frame = CGRectMake(_dpadRadius - 12.0f, padOffset, 24.0f, 18.0f);
    _lblDown.frame = CGRectMake(_dpadRadius - 12.0f, _dpadRadius * 2 - padOffset - 18.0f, 24.0f, 18.0f);
    _lblLeft.frame = CGRectMake(padOffset, _dpadRadius - 9.0f, 18.0f, 18.0f);
    _lblRight.frame = CGRectMake(_dpadRadius * 2 - padOffset - 18.0f, _dpadRadius - 9.0f, 18.0f, 18.0f);
    
    CGFloat diagOffset = _dpadRadius * 0.30f;
    _lblUpLeft.frame = CGRectMake(_dpadRadius - diagOffset - 9.0f, _dpadRadius - diagOffset - 9.0f, 18.0f, 18.0f);
    _lblUpRight.frame = CGRectMake(_dpadRadius + diagOffset - 9.0f, _dpadRadius - diagOffset - 9.0f, 18.0f, 18.0f);
    _lblDownLeft.frame = CGRectMake(_dpadRadius - diagOffset - 9.0f, _dpadRadius + diagOffset - 9.0f, 18.0f, 18.0f);
    _lblDownRight.frame = CGRectMake(_dpadRadius + diagOffset - 9.0f, _dpadRadius + diagOffset - 9.0f, 18.0f, 18.0f);
    
    // Right Attack Cluster: Slanted 2x2 Matrix
    CGFloat atkCenterX = w - MAX(insets.right + 45.0f * scale, 110.0f * scale) - spacingX/2.0f;
    CGFloat atkCenterY = h - MAX(insets.bottom + 45.0f * scale, 85.0f * scale);
    
    // Collision guard: Ensure right edge of DPad and left edge of attack cluster never overlap
    CGFloat dpadRightEdge = _dpadCenter.x + _dpadRadius + 20.0f;
    CGFloat atkLeftEdge = atkCenterX - spacingX - btnSize/2.0f;
    if (atkLeftEdge < dpadRightEdge) {
        CGFloat shift = dpadRightEdge - atkLeftEdge + 10.0f;
        atkCenterX += shift;
    }
    
    // Slant angle (16 degrees upwards to right)
    CGFloat angle = 16.0f * (M_PI / 180.0f);
    CGFloat cosA = cosf(angle);
    CGFloat sinA = sinf(angle);
    
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
    
    // Macro Buttons Arc (Comfortably above the attack buttons with no overlap)
    CGFloat macroY = MIN(ptLP.y, ptRP.y) - btnSize/2.0f - macroH - 12.0f;
    _btn1Plus2.frame = CGRectMake(atkCenterX - spacingX - 10.0f, macroY + 8.0f, macroW, macroH);
    _btn3Plus4.frame = CGRectMake(atkCenterX - spacingX/2.0f + 2.0f, macroY - 2.0f, macroW, macroH);
    _btn1Plus3.frame = CGRectMake(atkCenterX + 6.0f, macroY - 2.0f, macroW, macroH);
    _btn2Plus4.frame = CGRectMake(atkCenterX + spacingX/2.0f + 18.0f, macroY + 8.0f, macroW, macroH);
    
    _btnRage.frame = CGRectMake(atkCenterX - 24.0f * scale, macroY - 32.0f * scale, 48.0f * scale, 24.0f * scale);
    _btnRage.layer.cornerRadius = 12.0f * scale;
    
    // Logs drawer resizing
    if (_logDrawerView) {
        CGFloat drawerW = MIN(w - 24.0f, 660.0f);
        CGFloat drawerH = MIN(h - 50.0f, 300.0f);
        CGFloat targetY = _isLogsDrawerOpen ? (MAX(insets.top, 14.0f) + 38.0f) : (-drawerH - 30.0f);
        _logDrawerView.frame = CGRectMake((w - drawerW)/2.0f, targetY, drawerW, drawerH);
        _logTextView.frame = CGRectMake(10, 42, drawerW - 20, drawerH - 48);
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
        g_tekken_stick_x = 0.0f;
        g_tekken_stick_y = 0.0f;
        [self updateDpadVisuals:0];
        [self emitCombinedButtons];
        return;
    }
    
    // Analog stick values normalized between -1.0 and 1.0
    g_tekken_stick_x = std::clamp((float)(dx / _dpadRadius), -1.0f, 1.0f);
    g_tekken_stick_y = std::clamp((float)(-dy / _dpadRadius), -1.0f, 1.0f);
    
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
    g_tekken_stick_x = 0.0f;
    g_tekken_stick_y = 0.0f;
    [self updateDpadVisuals:0];
    [self emitCombinedButtons];
}

#pragma mark - Button Actions

- (void)buttonDown:(UIButton *)sender {
    [_haptic impactOccurred];
    sender.transform = CGAffineTransformMakeScale(0.92f, 0.92f);
    sender.alpha = 0.95f;
    
    _currentButtons |= (uint32_t)sender.tag;
    g_tekken_current_buttons = (_currentButtons | _dpadButtons);
    [self emitCombinedButtons];
}

- (void)buttonUp:(UIButton *)sender {
    sender.transform = CGAffineTransformIdentity;
    sender.alpha = _controlsOpacity;
    
    _currentButtons &= ~(uint32_t)sender.tag;
    g_tekken_current_buttons = (_currentButtons | _dpadButtons);
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
