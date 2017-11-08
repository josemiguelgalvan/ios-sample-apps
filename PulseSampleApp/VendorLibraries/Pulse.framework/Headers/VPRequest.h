//
//  VPRequest.h
//  Pulse
//
//  Created by Jacques du Toit on 24/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VPSession;

/**
 Callback to return requested [session](VPSession).
 */
typedef void(^VPSessionRequestSuccessBlock)(VPSession *session);

/**
 Callback to return requested [ad](VPAd) or [insertion point](VPInsertionPoint).
 */
typedef void(^VPRequestSuccessBlock)(id object);

/**
 Callback to notify of errors in request.
 */
typedef void(^VPRequestFailureBlock)(NSError *error);

/**
 A handle to an ongoing request.
 */
@interface VPRequest : NSObject

/**
 Cancels the request immediately, causing any failure callback (if present) to be called
 with specified error.
 
 @param error An error object describing the reason for cancelling.
 */
- (void)cancelWithError:(NSError *)error;

@end
