//
//  OOPulseVideoAd.h
//  Pulse
//
//  Created by Jacques du Toit on 11/11/15.
//  Copyright © 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Pulse/OOPulseAd.h>
#import <Pulse/VPMediaFile.h>
#import <Pulse/OOPulseAdError.h>

@class VPAd;
@class OOPulse;

/**
 *  This is the protocol for pause ads owned by a OOPulseSession.
 *
 *  This protocol is used to notify the session about events
 *  regarding this ad, and provides access to relevant properties.
 *
 *  You must notify this object of the following events:
 *
 *  - The ad has been displayed: [OOPulsePauseAd adDisplayed]
 *  - The ad has been closed by the user: [OOPulsePauseAd adClosed]
 *  - The ad failed to play: [OOPulsePauseAd adFailedWithError:]
 *
 *  Depending on your application some of the other methods may need to be called
 *  in response to user interaction.
 *
 */
@protocol OOPulsePauseAd <OOPulseAd>

/**  @name Ad event notifications */

/**
 *  Notify the session that the ad has been displayed
 *
 *  This should only be called after your delegate has been instructed to show
 *  the ad through [OOPulseSessionDelegate showPauseAd:].
 */
- (void)adDisplayed;

/**
 *  Notify the session that the pause ad has been closed by the user.
 *
 *  Do not call if the ad was closed because the user resumed playback of the video content.
 */
- (void)adClosed;

/**
 *  Notify the session that, due to an error, the ad could not be played or that playback
 *  could not continue.
 *
 *  @param error The OOPulseAdError that best describes the problem.
 */
- (void)adFailedWithError:(OOPulseAdError)error;

/**  @name Ad properties */

/**
 * The MIME-type of the resource to display.
 */
- (NSString *)resourceType;

/**
 * The URL where the ad's resource is located.
 */
- (NSURL *)resourceURL;

/**
 *  Returns the underlying core ad for this OOPulseAd.
 *
 *  In most cases, you do **not** need to access this.
 *
 *  @return the VPAd instance.
 */
- (VPAd *)coreAd;

@end
