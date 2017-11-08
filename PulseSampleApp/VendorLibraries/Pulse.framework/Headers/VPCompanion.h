//
//  VPCompanion.h
//  Pulse
//
//  Created by Jacques du Toit on 03/06/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPCreative.h>

/**
 Companion are used to display additional banner ads along with a main ad.
 */
@interface VPCompanion : VPCreative

/**
 The companion ad id assigned by Ooyala Pulse.
 */
- (NSString *) identifier;

/**
 The custom companion ad id set in the Ooyala Pulse UI.
 */
- (NSString *) customIdentifier;

/**
 The companion's width.
 */
- (NSInteger) width;

/**
 The companion's height.
 */
- (NSInteger) height;


/**
 The resources used to display the ad companion. 
 
 If this array contains multiple resources, the video player should determine 
 the most appropriate type to display. The resources can be any of the following 
 types: 
 - VPIFrameResource, VPHtmlResource, VPStaticResource.
*/
- (NSArray *) resources;


/**
 The placement zone ID of the companion set in the Ooyala Pulse UI.
 */
- (NSString *) zoneIdentifier;

@end
