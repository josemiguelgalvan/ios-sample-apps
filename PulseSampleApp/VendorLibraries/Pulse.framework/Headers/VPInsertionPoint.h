//
//  VPInsertionPoint.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VPSession;

/**
 A VPInsertionPoint contains a number of ad slots, and the conditions
 for when those slots should be triggered.

 @see VPSlot
 @see VPCondition
 */
@interface VPInsertionPoint : NSObject

/**
 The conditions for this insertion point,
 at least one of these must be met before this
 insertion point can be triggered,
 as an array of VPCondition instances.
 */
- (NSArray *)conditions;

/**
 The slots contained in this session,
 as an array of VPSlot instances.
 */
- (NSArray *)slots;

/**
 The VPSession this insertion point is a part of.
 */
- (VPSession *)parentSession;

/**
 Indicates whether all ads in this insertion point are ready to be displayed.
 If false, they need to be retrieved on demand using [VPAdRequester requestThirdPartyWithContainer:success:].
 */
- (BOOL)isReady;

@end