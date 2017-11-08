//
//  OOPulseVideoAd.h
//  Pulse
//
//  Created by Jacques du Toit on 11/11/15.
//  Copyright © 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Pulse/VPMediaFile.h>
#import <Pulse/OOPulseAdError.h>
#import <Pulse/OOPulseAd.h>

#import <Pulse/OOPulseCompanionAd.h>

@class VPAd;
@class OOPulse;

/**
 *  This is the protocol for video ads owned by a OOPulseSession.
 *
 *  This protocol is used to notify the session about events
 *  regarding this ad, and provides access to relevant properties.
 *
 *  You must notify this object of the following events:
 *
 *  - The ad has started: [OOPulseVideoAd adStarted]
 *  - The ad playback position has changed: [OOPulseVideoAd adPositionChanged:]
 *  - The ad has played to completion: [OOPulseVideoAd adFinished]
 *  - The ad failed to play: [OOPulseVideoAd adFailedWithError:]
 *
 *  Depending on your application some of the other methods may need to be called
 *  in response to user interaction.
 *
 */
@protocol OOPulseVideoAd <OOPulseAd>

/**  @name Ad event notifications */

/**
 *  Notify the session that the ad has started playing.
 *
 *  This should only be called after your delegate has been instructed to play
 *  the ad through [OOPulseSessionDelegate startAdPlaybackWithAd:timeout:].
 */
- (void)adStarted;

/**
 *  Notify the session that the ad has played to completion.
 *
 *  After this, one of the following delegate methods may be triggered:
 *
 *  - [OOPulseSessionDelegate startAdPlaybackWithAd:timeout:] - if there are more ads in this ad break
 *  - [OOPulseSessionDelegate startContentPlayback] - if there are no more ads and the content has not finished
 *  - [OOPulseSessionDelegate sessionEnded] - otherwise
 */
- (void)adFinished;

/**
 *  Notify the session that the ad was skipped by the user.
 *
 *  After this, one of the following delegate methods may be triggered:
 *
 *  - [OOPulseSessionDelegate startAdPlaybackWithAd:timeout:] - if there are more ads in this ad break
 *  - [OOPulseSessionDelegate startContentPlayback] - if there are no more ads and the content has not finished
 *  - [OOPulseSessionDelegate sessionEnded] - otherwise
 */
- (void)adSkipped;

/**
 *  Notify the session that the ad playback position has changed, either
 *  as a result of seeking or normal playback.
 *
 *  @param position The ad position in seconds since start.
 */
- (void)adPositionChanged:(NSTimeInterval)position;

/**
 *  Notify the session that the ad has paused.
 */
- (void)adPaused;

/**
 *  Notify the session that the ad has resumed playback.
 */
- (void)adResumed;

/**
 *  Notify the session that, due to an error, the ad could not be played or that playback
 *  could not continue.
 *
 *  @param error The OOPulseAdError that best describes the problem.
 */
- (void)adFailedWithError:(OOPulseAdError)error;

/**  @name Ad properties */

/**
 *  Returns an array of media files for this ad.
 *
 *  Your application should choose the best media file to display based on size
 *  bandwidth, and format considerations.
 *
 *  If none of the media files are supported by your video player, you should
 *  call [OOPulseVideoAd adFailedWithError:] with OOPulseAdErrorNoSupportedMediaFile.
 *
 *  @return A NSArray of VPMediaFile instances.
 */
- (NSArray<VPMediaFile*>*)mediaFiles;

/**
 * Determine whether or not a skip button for the ad may be displayed.
 *
 * If true, check the value of [OOPulseVideoAd skipOffset], which is the amount
 * of seconds from the start of the ad at which the button should first be displayed.
 *
 * When the viewer activates this button, call [OOPulseVideoAd adSkipped].
 */
- (BOOL)isSkippable;

/**
 * The amount of seconds from the start of the ad at which the button should first be displayed.
 *
 * If an OOPulseVideoAd is playing, and a call to [OOPulseVideoAd isSkippable] returns YES,
 * show a skip button after this amount of seconds has passed.
 */
-(NSTimeInterval)skipOffset;

/**
 *  Returns the underlying core ad for this OOPulseVideoAd.
 *
 *  In most cases, you do **not** need to access this.
 *
 *  @return the VPAd instance.
 */
- (VPAd *)coreAd;

/**
 *  Returns an array of companion banners for this ad.
 *
 *  Your application should choose the proper companion banner to display based on their
 *  zone identifier.
 *
 *  @return A NSArray of objects conforming to the OOPulseCompanionAd protocol.
 */
- (NSArray<id<OOPulseCompanionAd>>*)companions;

@end
