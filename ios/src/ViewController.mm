#import "ViewController.h"
#import "TouchOverlayView.h"
#import "GameControllerManager.h"
#import "tekken6_hooks.h"
#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

// Global input state accessed by ReXGlue input system
extern "C" {
    uint32_t g_tekken_current_buttons = 0;
    float g_tekken_stick_x = 0.0f;
    float g_tekken_stick_y = 0.0f;
}

@interface ViewController () <TouchOverlayDelegate, GameControllerDelegate, UIDocumentPickerDelegate> {
    CADisplayLink *_displayLink;
    TouchOverlayView *_touchOverlay;
    BOOL _isProMotionSupported;
    BOOL _proMotionEnabled;
    BOOL _isUltrawideFull;
    
    // Auto-detect & setup UI
    UIView *_setupCardView;
    UILabel *_statusBadge;
    NSString *_detectedGamePath;
    UIImpactFeedbackGenerator *_haptic;
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
    
    _haptic = [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleMedium];
    [_haptic prepare];
    
    // Check ProMotion hardware capability (iPhone 13 Pro+, iPad Pro)
    NSInteger maxFPS = [UIScreen mainScreen].maximumFramesPerSecond;
    _isProMotionSupported = (maxFPS >= 120);
    _proMotionEnabled = _isProMotionSupported;
    _isUltrawideFull = NO; // Default to 16:9 pixel-perfect aspect ratio
    
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
    _touchOverlay.isUltrawideFull = _isUltrawideFull;
    [self.view addSubview:_touchOverlay];
    
    // Setup physical game controller monitoring
    [GameControllerManager sharedManager].delegate = self;
    [[GameControllerManager sharedManager] startMonitoring];
    
    // Ensure ~/Documents/game folder exists and scan for Tekken 6 executable
    [self ensureGameDirectoryStructure];
    [self autoDetectGameAndLaunch];
}

#pragma mark - Game Directory & Auto-Detection

- (NSString *)gameDirectoryPath {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    return [paths.firstObject stringByAppendingPathComponent:@"game"];
}

- (void)ensureGameDirectoryStructure {
    NSString *gameDir = [self gameDirectoryPath];
    NSFileManager *fm = [NSFileManager defaultManager];
    
    if (![fm fileExistsAtPath:gameDir]) {
        [fm createDirectoryAtPath:gameDir withIntermediateDirectories:YES attributes:nil error:nil];
        
        NSString *readmePath = [gameDir stringByAppendingPathComponent:@"README.txt"];
        NSString *readme = @"=== TEKKEN 6 iOS GAME DIRECTORY ===\n\n"
                           @"Place your Tekken 6 Xbox 360 files inside this folder:\n"
                           @"- default.xex (required executable)\n"
                           @"- game data folders and assets\n"
                           @"- or Tekken 6 ISO\n\n"
                           @"How to add files via iOS:\n"
                           @"1. Open the 'Files' app on your iPhone or iPad.\n"
                           @"2. Navigate to: On My iPhone/iPad > Tekken 6 > game\n"
                           @"3. Paste or copy your game files here.\n"
                           @"4. Launch Tekken 6, and it will automatically detect and load your game!\n";
        [readme writeToFile:readmePath atomically:YES encoding:NSUTF8StringEncoding error:nil];
        NSLog(@"[Tekken 6 iOS] Initialized Documents/game directory at: %@", gameDir);
    }
}

- (NSString *)scanForGameExecutable {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *gameDir = [self gameDirectoryPath];
    
    // 1. Direct check: Documents/game/default.xex
    NSString *primaryXex = [gameDir stringByAppendingPathComponent:@"default.xex"];
    if ([fm fileExistsAtPath:primaryXex]) {
        return primaryXex;
    }
    
    // 2. Subfolder check: Documents/game/*/default.xex or .xex / .iso
    NSDirectoryEnumerator *enumerator = [fm enumeratorAtPath:gameDir];
    NSString *relPath;
    while ((relPath = [enumerator nextObject])) {
        NSString *lower = relPath.lastPathComponent.lowercaseString;
        if ([lower isEqualToString:@"default.xex"] || [lower.pathExtension isEqualToString:@"xex"] || [lower.pathExtension isEqualToString:@"iso"]) {
            return [gameDir stringByAppendingPathComponent:relPath];
        }
    }
    
    // 3. Fallback: Documents/ root
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *docsRoot = paths.firstObject;
    NSString *rootXex = [docsRoot stringByAppendingPathComponent:@"default.xex"];
    if ([fm fileExistsAtPath:rootXex]) {
        return rootXex;
    }
    
    return nil;
}

- (void)autoDetectGameAndLaunch {
    _detectedGamePath = [self scanForGameExecutable];
    
    if (_detectedGamePath) {
        NSLog(@"[Tekken 6 iOS] Auto-detected game at: %@", _detectedGamePath);
        if (_setupCardView) {
            [UIView animateWithDuration:0.3 animations:^{
                self->_setupCardView.alpha = 0.0f;
            } completion:^(BOOL finished) {
                [self->_setupCardView removeFromSuperview];
                self->_setupCardView = nil;
            }];
        }
    } else {
        NSLog(@"[Tekken 6 iOS] No game files found in Documents/game. Presenting setup guide card.");
        [self showSetupCard];
    }
}

#pragma mark - In-App Setup & Guide Card

- (void)showSetupCard {
    if (_setupCardView) return;
    
    CGFloat cardW = MIN(self.view.bounds.size.width - 64.0f, 480.0f);
    CGFloat cardH = 260.0f;
    
    _setupCardView = [[UIView alloc] initWithFrame:CGRectMake((self.view.bounds.size.width - cardW)/2.0f,
                                                              (self.view.bounds.size.height - cardH)/2.0f,
                                                              cardW, cardH)];
    _setupCardView.backgroundColor = [UIColor colorWithRed:0.07f green:0.08f blue:0.12f alpha:0.92f];
    _setupCardView.layer.cornerRadius = 20.0f;
    _setupCardView.layer.borderWidth = 1.5f;
    _setupCardView.layer.borderColor = [UIColor colorWithRed:0.0f green:0.75f blue:1.0f alpha:0.7f].CGColor;
    _setupCardView.layer.shadowColor = [UIColor colorWithRed:0.0f green:0.75f blue:1.0f alpha:0.5f].CGColor;
    _setupCardView.layer.shadowRadius = 16.0f;
    _setupCardView.layer.shadowOpacity = 0.6f;
    _setupCardView.layer.shadowOffset = CGSizeZero;
    
    // Title
    UILabel *titleLbl = [[UILabel alloc] initWithFrame:CGRectMake(20, 16, cardW - 40, 26)];
    titleLbl.text = @"TEKKEN 6 (XBOX 360)";
    titleLbl.textColor = [UIColor whiteColor];
    titleLbl.font = [UIFont boldSystemFontOfSize:18.0f];
    titleLbl.textAlignment = NSTextAlignmentCenter;
    [_setupCardView addSubview:titleLbl];
    
    // Status Badge
    _statusBadge = [[UILabel alloc] initWithFrame:CGRectMake((cardW - 200)/2.0f, 48, 200, 20)];
    _statusBadge.text = @"AWAITING GAME FILES";
    _statusBadge.textColor = [UIColor colorWithRed:1.0f green:0.75f blue:0.2f alpha:1.0f];
    _statusBadge.font = [UIFont boldSystemFontOfSize:11.0f];
    _statusBadge.textAlignment = NSTextAlignmentCenter;
    _statusBadge.backgroundColor = [[UIColor colorWithRed:1.0f green:0.75f blue:0.2f alpha:0.2f] colorWithAlphaComponent:0.15f];
    _statusBadge.layer.cornerRadius = 10.0f;
    _statusBadge.layer.masksToBounds = YES;
    [_setupCardView addSubview:_statusBadge];
    
    // Step Instructions
    UILabel *guideLbl = [[UILabel alloc] initWithFrame:CGRectMake(24, 78, cardW - 48, 90)];
    guideLbl.numberOfLines = 4;
    guideLbl.textColor = [UIColor colorWithWhite:0.85f alpha:1.0f];
    guideLbl.font = [UIFont systemFontOfSize:13.0f weight:UIFontWeightRegular];
    guideLbl.text = @"1. Open iOS Files app on this device\n"
                    @"2. Navigate to: On My iPhone/iPad > Tekken 6 > game\n"
                    @"3. Copy your default.xex and game assets there\n"
                    @"4. Tap 'Auto-Detect' below to start playing!";
    [_setupCardView addSubview:guideLbl];
    
    // Auto-Detect Button
    UIButton *btnRescan = [UIButton buttonWithType:UIButtonTypeCustom];
    btnRescan.frame = CGRectMake(24, cardH - 64, (cardW - 58)/2.0f, 44);
    btnRescan.backgroundColor = [UIColor colorWithRed:0.0f green:0.75f blue:1.0f alpha:0.9f];
    btnRescan.layer.cornerRadius = 14.0f;
    [btnRescan setTitle:@"Auto-Detect" forState:UIControlStateNormal];
    [btnRescan setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    btnRescan.titleLabel.font = [UIFont boldSystemFontOfSize:14.0f];
    [btnRescan addTarget:self action:@selector(rescanButtonTapped) forControlEvents:UIControlEventTouchUpInside];
    [_setupCardView addSubview:btnRescan];
    
    // Import from Files Button (Direct Fallback)
    UIButton *btnImport = [UIButton buttonWithType:UIButtonTypeCustom];
    btnImport.frame = CGRectMake(CGRectGetMaxX(btnRescan.frame) + 10, cardH - 64, (cardW - 58)/2.0f, 44);
    btnImport.backgroundColor = [UIColor colorWithRed:0.15f green:0.16f blue:0.22f alpha:0.9f];
    btnImport.layer.cornerRadius = 14.0f;
    btnImport.layer.borderWidth = 1.0f;
    btnImport.layer.borderColor = [UIColor colorWithWhite:0.4f alpha:0.8f].CGColor;
    [btnImport setTitle:@"Import from Files" forState:UIControlStateNormal];
    [btnImport setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    btnImport.titleLabel.font = [UIFont boldSystemFontOfSize:13.0f];
    [btnImport addTarget:self action:@selector(importFilesButtonTapped) forControlEvents:UIControlEventTouchUpInside];
    [_setupCardView addSubview:btnImport];
    
    [self.view addSubview:_setupCardView];
}

- (void)rescanButtonTapped {
    [_haptic impactOccurred];
    [self autoDetectGameAndLaunch];
    
    if (!_detectedGamePath) {
        _statusBadge.text = @"NO FILES FOUND IN GAME/";
        _statusBadge.textColor = [UIColor colorWithRed:1.0f green:0.3f blue:0.3f alpha:1.0f];
    }
}

- (void)importFilesButtonTapped {
    [_haptic impactOccurred];
    
    // Use UIDocumentPickerViewController configured with asCopy:YES so files are copied without security-scope freeze
    NSArray *types;
    if (@available(iOS 14.0, *)) {
        types = @[UTTypeFolder, UTTypeItem, UTTypeData];
    } else {
        types = @[@"public.item", @"public.folder"];
    }
    
    UIDocumentPickerViewController *picker;
    if (@available(iOS 14.0, *)) {
        picker = [[UIDocumentPickerViewController alloc] initForOpeningContentTypes:types asCopy:YES];
    } else {
        picker = [[UIDocumentPickerViewController alloc] initWithDocumentTypes:types inMode:UIDocumentPickerModeImport];
    }
    
    picker.delegate = self;
    picker.allowsMultipleSelection = YES;
    [self presentViewController:picker animated:YES completion:nil];
}

#pragma mark - UIDocumentPickerDelegate

- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *gameDir = [self gameDirectoryPath];
    
    for (NSURL *url in urls) {
        BOOL isSecured = [url startAccessingSecurityScopedResource];
        
        NSString *dest = [gameDir stringByAppendingPathComponent:url.lastPathComponent];
        if ([fm fileExistsAtPath:dest]) {
            [fm removeItemAtPath:dest error:nil];
        }
        
        NSError *copyError = nil;
        [fm copyItemAtURL:url toURL:[NSURL fileURLWithPath:dest] error:&copyError];
        if (copyError) {
            NSLog(@"[Tekken 6 Import] Error copying file: %@", copyError.localizedDescription);
        } else {
            NSLog(@"[Tekken 6 Import] Copied %@ into %@", url.lastPathComponent, gameDir);
        }
        
        if (isSecured) {
            [url stopAccessingSecurityScopedResource];
        }
    }
    
    [self autoDetectGameAndLaunch];
}

#pragma mark - Aspect Ratio & Viewport Layout (Modern iPhone 19.5:9 Optimization)

- (CGRect)calculateViewportFrame {
    CGFloat screenW = self.view.bounds.size.width;
    CGFloat screenH = self.view.bounds.size.height;
    if (screenW <= 0 || screenH <= 0) return self.view.bounds;
    
    if (_isUltrawideFull) {
        // Borderless full ultrawide (19.5:9 fill)
        return self.view.bounds;
    }
    
    // Pixel-perfect 16:9 Aspect Fit (Pillarbox on left/right wings)
    CGFloat targetAspect = 16.0f / 9.0f;
    CGFloat screenAspect = screenW / screenH;
    
    CGFloat layerW, layerH, layerX, layerY;
    if (screenAspect > targetAspect) {
        // Display is wider than 16:9 (modern iPhones: 19.5:9)
        layerH = screenH;
        layerW = layerH * targetAspect;
        layerX = (screenW - layerW) / 2.0f;
        layerY = 0.0f;
    } else {
        // Display is taller than 16:9 (iPad 4:3 or 10:7)
        layerW = screenW;
        layerH = layerW / targetAspect;
        layerX = 0.0f;
        layerY = (screenH - layerH) / 2.0f;
    }
    
    return CGRectMake(layerX, layerY, layerW, layerH);
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    
    CGRect viewport = [self calculateViewportFrame];
    _metalLayer.frame = viewport;
    _metalLayer.drawableSize = CGSizeMake(viewport.size.width * [UIScreen mainScreen].nativeScale,
                                         viewport.size.height * [UIScreen mainScreen].nativeScale);
    
    if (_setupCardView) {
        CGFloat cardW = _setupCardView.frame.size.width;
        CGFloat cardH = _setupCardView.frame.size.height;
        _setupCardView.center = CGPointMake(self.view.bounds.size.width / 2.0f, self.view.bounds.size.height / 2.0f);
    }
}

#pragma mark - ProMotion 120Hz & Power State

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

- (void)toggleAspectRatioRequested {
    _isUltrawideFull = !_isUltrawideFull;
    _touchOverlay.isUltrawideFull = _isUltrawideFull;
    NSLog(@"[Tekken 6 iOS] Toggling aspect ratio -> %s", _isUltrawideFull ? "ULTRAWIDE FULL" : "16:9 LETTERBOX");
    
    [UIView animateWithDuration:0.25 animations:^{
        [self.view setNeedsLayout];
        [self.view layoutIfNeeded];
    }];
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
