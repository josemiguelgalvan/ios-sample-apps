//
//  VPTrackingEvents.h
//  Pulse
//
//  Created by Jacques du Toit on 04/05/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPTracker.h>

/**
  Allows checking whether a [trackable](VPTrackable) object contains some
  given tracking events or not.
*/
@interface VPTrackingEvents : NSObject

/**
 Checks whether this object contains tracking URLs for the given tracking event.
 
 @param type The event type to check
 */
- (BOOL)hasEventWithType:(VPTrackingEventType)type;

/**
 Checks wheter this object contains tracking URLs for a custom tracking
 event with the given name.
 
 @param eventName The custom event name to check
 */
- (BOOL)hasCustomEventWithName:(NSString *)eventName;

/**
 Returns the tracking URLs for the specified event.
 
 @param type The event type to check
 */
- (NSArray *)trackingURLsWithEventType:(VPTrackingEventType)type;

@end
