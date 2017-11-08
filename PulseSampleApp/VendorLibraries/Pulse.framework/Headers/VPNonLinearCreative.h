//
//  VPNonLinearCreative.h
//  Pulse
//
//  Created by Jacques du Toit on 04/06/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Pulse/Pulse.h>

/**
 Represents a non-linear creative, which does not interrupt or pause
 the main content while the ad is displayed. Generally used for overlays.
 */
@interface VPNonLinearCreative : VPCreative

/**
 The minimum suggested playback duration of the creative.
 */
- (NSTimeInterval) duration;

/**
 The companion's width.
 */
- (NSInteger) width;

/**
 The companion's height.
 */
- (NSInteger) height;

/**
 The resources used to display the nonlinear creative.
 
 If this array contains multiple resources, the video player should determine
 the most appropriate type to display. The resources can be any of the following
 types:
 - VPIFrameResource, VPHTMLResource, VPStaticResource.
 */
- (NSArray*) resources;

@end
