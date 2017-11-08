//
//  VPIFrameResource.h
//  Pulse
//
//  Created by Jacques du Toit on 03/06/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPResource.h>

/**
 A resource used by VPCompanion to be displayed within an IFrame.
 */
@interface VPIFrameResource : VPResource

/**
 The URL of the resource that should be loaded within the IFrame.
 */
- (NSURL *)URL;

@end
