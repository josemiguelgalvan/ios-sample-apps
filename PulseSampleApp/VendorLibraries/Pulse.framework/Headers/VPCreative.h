//
//  VPCreative.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPTrackable.h>

@class VPAd;
@class VPUniversalAdId;

/**
 The base class for VPLinearCreative. Describes fields common
 to both linear and nonlinear creatives.
 */
@interface VPCreative : NSObject <VPTrackable>

/**
 The sequence number of the creative, indicating the order in
 which creatives should be displayed. Creatives from the same ad,
 sharing the same sequence, are to be displayed together.
 */
- (NSInteger)sequence;

/**
 The creative type; generally indicates which role
 this creative plays in complex ad formats.
 */
- (NSString *)type;

/**
 The VPAd this creative belongs to.
 */
- (VPAd *)parentAd;

/**
 Tracking events that apply to this object.
 */
- (VPTrackingEvents *)trackingEvents;

/**
  The UniversalAdId is used to provide a unique creative identifier that is maintained across systems.
 */
- (VPUniversalAdId *)universalAdId;

@end
