//
//  VPSession.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Pulse/VPTrackable.h>
#import <Foundation/Foundation.h>

/**
 The base object containing all information about
 an ad session retrieved from Ooyala Pulse.
 */
@interface VPSession : NSObject <VPTrackable>

/**
 The id for this session.
 */
- (NSString *)identifier;

/**
 Language of the session
 */
- (NSString *)language;

/**
 The insertion points contained in this session,
 as an array of VPInsertionPoint instances.
 */
- (NSArray *)insertionPoints;

/**
 Tracking events that apply to this object.
 */
- (VPTrackingEvents *)trackingEvents;

@end
