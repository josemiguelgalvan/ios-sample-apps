//
//  VPCondition.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Defines the possible conditions when an insertion point
 is to be triggered.
 @see VPEventCondition
 @see VPPropertyCondition
 */
typedef NS_ENUM(NSUInteger, VPConditionType) {
  /** Condition is met before video content has begun playback. */
  VPConditionTypeOnBeforeContent = 0,
  /** Condition is met after video content has completed playback. */
  VPConditionTypeOnContentEnd,
  /** Condition is met when the user has paused the ad. */
  VPConditionTypeOnPause,
  /** Condition is met if the content playback position equals the provided value. */
  VPConditionTypePlaybackPosition,
  /** Condition is met if the content has been playing for the given amount of time, regardless of position. */  
  VPConditionTypePlaybackTime,
  /** Condition is met only if the given amount of time has passed since the last time the user was shown a linear ad. */
  VPConditionTypeTimeSinceLinear
};

/**
 One or more VPConditions describe the conditions for when
 a particular VPInsertionPoint should be triggered.
 */
@interface VPCondition : NSObject

/**
 Describes the event or property that needs to be evaluated
 to determine whether the condition is met or not.
 For a list of potential conditions, see VPConditionType.
 */
- (VPConditionType)type;

/**
 Sub-conditions, at least one of which must be met
 before this condition can be considered met,
 as an array of VPCondition instances.
 */
- (NSArray *)conditions;

@end