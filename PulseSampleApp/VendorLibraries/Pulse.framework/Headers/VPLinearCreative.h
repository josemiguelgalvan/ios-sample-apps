//
//  VPLinearCreative.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPCreative.h>

/**
 Determines when to show a skip button for a linear creative.
 */
typedef NS_ENUM(NSUInteger, VPSkipButtonMode) {
  /** Skip button mode was not provided. */
  VPSkipButtonModeUnset = 0,
  /** Never show the skip button. */
  VPSkipButtonModeNever,
  /** Always show the skip button. */
  VPSkipButtonModeAlways,
  /** Show the skip button after the creative's first completion. */
  VPSkipButtonModeAfterFirstCompletion
 };

/**
 Represents a linear creative, or a linear visual element of an ad,
 which always interrupts or pauses the main content while the ad is displayed.
 */
@interface VPLinearCreative : VPCreative

/**
 The playback duration, of the creative.
 */
- (NSTimeInterval) duration;

/**
 The media files to actually display for this creative, as an
 array of VPMediaFile instances.
 */
- (NSArray*) mediaFiles;

/**
 The URL to open when the user clicks or taps the ad.
 */
- (NSURL*) clickThroughURL;

/**
 If and when to show a skip button for the linear creative.
*/
- (VPSkipButtonMode) skipButtonMode;

/**
 Time in seconds the creative has to play for before the skip button can be shown.
*/
- (NSTimeInterval) skipOffset;

/**
 If lastCompletion is older than this, it should be ignored. 
 */
- (NSTimeInterval) skipResetTime;

/**
 The last time this creative was completed, as a UNIX timestamp (number of milliseconds since 00:00:00 UTC, 1 January 1970).
*/
- (long long) lastCompletion;

@end
