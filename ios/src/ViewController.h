#pragma once

#import <UIKit/UIKit.h>
#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>

@interface ViewController : UIViewController

@property (nonatomic, strong, readonly) CAMetalLayer *metalLayer;

- (void)updateInputState:(uint32_t)buttons;

@end
