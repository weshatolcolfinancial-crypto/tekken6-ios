#pragma once

#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

// Thread-safe C log function for hooks and C++ files
void TekkenLog(const char *format, ...) __attribute__((format(printf, 1, 2)));

#ifdef __cplusplus
}
#endif

extern NSString * const TekkenLogUpdatedNotification;

@interface TekkenLogger : NSObject

+ (instancetype)sharedLogger;

// Initialize logging file streams (redirects stdout/stderr to ~/Documents/tekken6.log)
- (void)setupLogging;

// Append a formatted message
- (void)logMessage:(NSString *)message;

// Get path to ~/Documents/tekken6.log
- (NSString *)logFilePath;

// Get path to ~/Documents/crash.log
- (NSString *)crashFilePath;

// Read recent log lines (for live on-screen viewer)
- (NSArray<NSString *> *)recentLogs;

// Full log text content
- (NSString *)fullLogText;

// Clear log file & memory buffer
- (void)clearLogs;

@end
