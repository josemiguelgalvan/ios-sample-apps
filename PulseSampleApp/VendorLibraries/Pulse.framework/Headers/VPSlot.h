//
//  VPSlot.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPTrackable.h>

@class VPInsertionPoint;

/**
 Contains the actual ads to be displayed, in the form of VPAd instances.
 */
@interface VPSlot : NSObject

/**
 The ads contained in this slot, as an array of VPAd instances.
 */
- (NSArray *)ads;

/**
 The VPInsertionPoint this slot is a part of.
 */
- (VPInsertionPoint *)parentInsertionPoint;

@end
