//
//  VPTrackable.h
//  Pulse
//
//  Created by Jacques du Toit on 04/05/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VPTrackingEvents;

/**
 A trackable object contains tracking events.
 */
@protocol VPTrackable <NSObject>

@required
/**
 Returns the tracking events for the current object.
 */
- (VPTrackingEvents *)trackingEvents;

@end
