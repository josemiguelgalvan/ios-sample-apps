//
//  VPPropertyCondition.h
//  Pulse
//
//  Created by Steve on 07/05/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPCondition.h>

/**
 Defines the possible operators which are to be used when
 comparing properties.
 */
typedef NS_ENUM(NSUInteger, VPOperator) {
	/** The property and value should be compared with the equals (==) operator. */
  VPOperatorEquals = 0,
	/**
   The property and value should be compared with the greater than or equals (>=) operator.
   The value in the condition should be on the right hand side in the comparison expression.
   */
  VPOperatorGreaterThanOrEquals
};

/**
 A property condition indicates that an insertion point,
 in order to be triggered, requires that a certain session
 or content playback state is evaluated.
 */
@interface VPPropertyCondition : VPCondition

/**
 The value which the given property, determined by type, should be compared to.
 */
- (NSTimeInterval) value;

/**
 The operator to use when comparing the relevant property and the value.
*/
- (VPOperator) operator;

@end
