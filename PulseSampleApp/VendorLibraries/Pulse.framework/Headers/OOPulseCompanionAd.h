//
//  OOPulseCompanionAd.h
//  Pulse
//
//  Created by Joao Sampaio on 12/04/17.
//  Copyright © 2017 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Pulse/OOPulseAd.h>
#import <Pulse/VPMediaFile.h>
#import <Pulse/OOPulseAdError.h>

@class VPAd;
@class OOPulse;

/**
 *  This protocol is used to handle companion banners, and notify
 *  the [OOPulseSession] about events regarding the companion banner.
 *
 *  As a minimum, the session object must be notified that the
 *  companion banner was displayed: [OOPulseCompanionAd adDisplayed].
 * 
 *  Depending on your application, you may also need the clickthrough
 *  URL ([OOPulseCompanionAd clickthroughURL]) to respond to viewers
 *  tapping a companion banner.
 */
@protocol OOPulseCompanionAd <OOPulseAd>

/**
 *  Notify the session that the ad has been displayed
 */
- (void)adDisplayed;

/**
 *  The URL where the ad's resource is located.
 */
- (NSURL *)resourceURL;

/**
 *  The MIME type of the resource to be displayed.
 */
- (NSString *)resourceType;

/**
 *  Returns a URL for a web page that should be displayed to the user
 *  when they tap the ad.
 *
 *  @return the URL to be displayed.
 */
- (NSURL *)clickthroughURL;

/**
 *  Returns the zone identifier assigned to this companion ad.
 */
- (NSString *) zoneIdentifier;

@end
