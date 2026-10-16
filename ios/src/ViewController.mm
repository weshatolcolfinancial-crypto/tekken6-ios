#import "ViewController.h"
#import "TouchOverlayView.h"
#import "GameControllerManager.h"
#import "tekken6_hooks.h"
#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>

// Global input state accessed by ReXGlue input system
extern "C" {
    uint32_t g_tekken_current_buttons = 0;
    float g_tekken_stick_x = 0.0f;
    float g_tekken_stick_y = 0.0f;
}

@interface ViewController () <TouchOverlayDelegate, GameControllerDelegate> {
    CADisplayLink *_displayLink;
    TouchOverlayView *_touchOverlay;
    BOOL _isProMotionSupported;
    BOOL _proMotionEnabled;
}
@end

@implementation ViewController

- (void)loadView {
    UIView *containerView = [[UIView alloc] initWithFrame:[UIScreen mainScreen].bounds];
    containerView.backgroundColor = [UIColor blackColor];
    
    // Configure CAMetalLayer for maximum 120Hz ProMotion responsiveness
    _metalLayer = [CAMetalLayer layer];
    _metalLayer.device = MTLCreateSystemDefaultDevice();
    _metalLayer.pixelFormat = MTLPixelFormatBGRA8Unorm;
    _metalLayer.framebufferOnly = YES;
    _metalLayer.frame = containerView.bounds;
    
    // Triple buffering eliminates pipeline stalls when rendering at 8.33ms (120Hz)
    _metalLayer.maximumDrawableCount = 3;
    _metalLayer.presentsWithTransaction = NO;
    
    // In iOS 16+, disable extended dynamic range overhead for standard rendering
    if (@available(iOS 16.0, *)) {
        _metalLayer.wantsExtendedDynamicRangeContent = NO;
    }
    
    [containerView.layer addSublayer:_metalLayer];
    self.view = containerView;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Check ProMotion hardware capability (iPhone 13 Pro+, iPad Pro)
    NSInteger maxFPS = [UIScreen mainScreen].maximumFramesPerSecond;
    _isProMotionSupported = (maxFPS >= 120);
    _proMotionEnabled = _isProMotionSupported;
    
    // Check if device is currently in Low Power Mode
    if ([[NSProcessInfo processInfo] isLowPowerModeEnabled]) {
        _proMotionEnabled = NO;
        NSLog(@"[Tekken 6 iOS] Low Power Mode is active. Clamping refresh rate to 60Hz.");
    }
    
    g_tekken_enable_promotion_120hz = _proMotionEnabled;
    
    NSLog(@"[Tekken 6 iOS] Screen maximum FPS: %ld, ProMotion Supported: %s, Initial: %s",
          (long)maxFPS, _isProMotionSupported ? "YES" : "NO", _proMotionEnabled ? "120Hz" : "60Hz");
    
    // Register for power state changes (automatically adapt if user activates Low Power Mode)
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(powerStateDidChange:)
                                                 name:NSProcessInfoPowerStateDidChangeNotification
                                               object:nil];
    
    // Configure Display Link with ProMotion Frame Rate Range
    [self setupDisplayLink];
    
    // Setup fighting touch overlay
    _touchOverlay = [[TouchOverlayView alloc] initWithFrame:self.view.bounds];
    _touchOverlay.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    _touchOverlay.delegate = self;
    _touchOverlay.isPromotion120Hz = _proMotionEnabled;
    [self.view addSubview:_touchOverlay];
    
    // Setup physical game controller monitoring
    [GameControllerManager sharedManager].delegate = self;
    [[GameControllerManager sharedManager] startMonitoring];
}

- (void)powerStateDidChange:(NSNotification *)notification {
    dispatch_async(dispatch_get_main_queue(), ^{
        BOOL isLowPower = [[NSProcessInfo processInfo] isLowPowerModeEnabled];
        if (isLowPower) {
            NSLog(@"[Tekken 6 iOS] Low Power Mode enabled: Setting display to 60Hz.");
            self->_proMotionEnabled = NO;
        } else {
            self->_proMotionEnabled = self->_isProMotionSupported;
            NSLog(@"[Tekken 6 iOS] Low Power Mode disabled: Restoring ProMotion %s.", self->_proMotionEnabled ? "120Hz" : "60Hz");
        }
        g_tekken_enable_promotion_120hz = self->_proMotionEnabled;
        self->_touchOverlay.isPromotion120Hz = self->_proMotionEnabled;
        [self setupDisplayLink];
    });
}

- (void)setupDisplayLink {
    if (_displayLink) {
        [_displayLink invalidate];
        _displayLink = nil;
    }
    
    _displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(renderFrame:)];
    
    if (@available(iOS 15.0, *)) {
        if (_proMotionEnabled) {
            // Lock to 120Hz: Prevents iOS from dropping frames during combat animations
            _displayLink.preferredFrameRateRange = CAFrameRateRangeMake(120.0f, 120.0f, 120.0f);
        } else {
            // Standard 60Hz rate
            _displayLink.preferredFrameRateRange = CAFrameRateRangeMake(60.0f, 60.0f, 60.0f);
        }
    } else {
        _displayLink.preferredFramesPerSecond = _proMotionEnabled ? 120 : 60;
    }
    
    [_displayLink addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSRunLoopCommonModes];
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    _metalLayer.frame = self.view.bounds;
    _metalLayer.drawableSize = CGSizeMake(self.view.bounds.size.width * [UIScreen mainScreen].nativeScale,
                                         self.view.bounds.size.height * [UIScreen mainScreen].nativeScale);
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (BOOL)prefersHomeIndicatorAutoHidden {
    return YES;
}

- (void)renderFrame:(CADisplayLink *)link {
    // Main render callback driving the host presenter pump if required by ReXGlue
}

#pragma mark - TouchOverlayDelegate

- (void)touchInputChanged:(uint32_t)pressedButtons {
    g_tekken_current_buttons = pressedButtons;
}

- (void)togglePromotionRequested {
    if (!_isProMotionSupported) {
        NSLog(@"[Tekken 6 iOS] Device does not support ProMotion 120Hz hardware.");
        return;
    }
    
    _proMotionEnabled = !_proMotionEnabled;
    g_tekken_enable_promotion_120hz = _proMotionEnabled;
    NSLog(@"[Tekken 6 iOS] Toggling ProMotion mode -> %s", _proMotionEnabled ? "120Hz" : "60Hz");
    [self setupDisplayLink];
}

#pragma mark - GameControllerDelegate

- (void)gamepadInputChanged:(uint32_t)pressedButtons leftStickX:(float)lx leftStickY:(float)ly {
    g_tekken_current_buttons = pressedButtons;
    g_tekken_stick_x = lx;
    g_tekken_stick_y = ly;
}

- (void)gamepadConnectionStatusChanged:(BOOL)isConnected {
    [_touchOverlay setControllerConnected:isConnected];
}

- (void)updateInputState:(uint32_t)buttons {
    g_tekken_current_buttons = buttons;
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    [_displayLink invalidate];
    [[GameControllerManager sharedManager] stopMonitoring];
}

@end
