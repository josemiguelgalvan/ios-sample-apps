//
//  OOPulseAd.h
//  Pulse
//
//  Created by Jacques du Toit on 30/06/16.
//  Copyright © 2016 Ooyala. All rights reserved.
//

@protocol OOPulseAd <NSObject>

/**  @name Ad click-through */

/**
 *  Notify the session that the user has opened the clickthrough link.
 */
- (void)adClickThroughTriggered;

/**
 *  Returns a URL for a web page that should be displayed to the user
 *  when they tap the ad.
 *
 *  @return the URL to be displayed.
 */
- (NSURL *)clickthroughURL;

@end