//
//  VPAdRequester.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Pulse/VPRequest.h>
#import <Pulse/VPContentMetadata.h>
#import <Pulse/VPRequestSettings.h>
#import <Pulse/VPLogItem.h>
#import <Pulse/VPTracker.h>

/**
 Name of the exception thrown for invalid host URLs.
 */
extern NSString *VPAdRequesterInvalidHostException;

/**
 The VPAdRequester is used to make ad requests to Ooyala Pulse; create an instance and
 then use the requestSession method to send information about the ads that you
 want to request.
*/
@interface VPAdRequester : NSObject

/** @name Instantiate */

/** 
 Creates a VPAdRequester with passed settings.

 @param vpHost The Ooyala Pulse hostname for the client account being used.
 @param deviceContainer The Ooyala Pulse device container, if any; can be nil.
 @param persistentId The Ooyala Pulse persistent user id, if any; can be nil.

 @return An instance of VPAdRequester, ready to make ad requests.
 */
+ (VPAdRequester *)adRequesterWithHost:(NSString *)vpHost
                       deviceContainer:(NSString *)deviceContainer
                          persistentId:(NSString *)persistentId;

/** @name Session requests */

/**
 Make a request for an ad session, using the given parameters.

 @param contentMetadata Information about the content along with which the requested ads are to be displayed.
 @param requestSettings Information about the environment in which the ad will play.
 @param onSuccess A VPSessionRequestSuccessBlock which is executed when the ad request succeeds; the resulting VPSession instance will be passed to it.
 @param onFail A VPRequestFailureBlock which is executed if the ad request fails; an NSError instance will be passed to it describing what went wrong.

 @return A VPRequest instance, which allows the user to cancel the request if desired.
 */
- (VPRequest*) requestSessionWithMetadata:(VPContentMetadata *)contentMetadata
                          requestSettings:(VPRequestSettings *)requestSettings
                                  success:(VPSessionRequestSuccessBlock)onSuccess
                                     fail:(VPRequestFailureBlock)onFail;

/**
 Make a request to Ooyala to extending the provided VPSession with additional [insertion points](VPInsertionPoint).
 If the failure callback was called the session will be unchanged, and can still
 be used.
 
 @param session The session to extend with additional [insertion points](VPInsertionPoint).
 @param contentMetadata Information about the content along with which the requested ads are to be displayed.
 @param requestSettings Information about the environment in which the ad will play.
 @param onSuccess A VPSessionRequestSuccessBlock which is executed when the ad request succeeds; the resulting VPSession instance will be passed to it.
 @param onFail A VPRequestFailureBlock which is executed if the ad request fails; an NSError instance will be passed to it describing what went wrong.
 
 @return A VPRequest instance, which allows the user to cancel the request if desired.
 */
- (VPRequest*) requestSessionExtension:(VPSession *)session
                          withMetadata:(VPContentMetadata *)contentMetadata
                       requestSettings:(VPRequestSettings *)requestSettings
                               success:(VPSessionRequestSuccessBlock)onSuccess
                                  fail:(VPRequestFailureBlock)onFail;

/** @name Third party ad requests */

/**
 Start a request to complete loading of an unloaded/'lazy' VPAd or VPInsertionPoint.
 The method only needs to be called when [VPAd ready] or [VPInsertionPoint ready] 
 returns false. The supplied container object will always be in a valid state 
 after this method return; if the failure callback is called the supplied
 container will contain a fallback ad.
 
 @param container The VPAd or VPInsertionPoint for which to request third party ads.
 @param onSuccess A VPRequestSuccessBlock which is executed on success.
 @param onFail A VPRequestFailureBlock which is executed on failure.
 
 @return A VPRequest instance, which allows the user to cancel the request if
         desired. Cancelling a request triggers the failure callback with the 
         supplied error.
 */
- (VPRequest *)requestThirdPartyWithContainer:(id)container
                                      success:(VPRequestSuccessBlock)onSuccess
                                         fail:(VPRequestFailureBlock)onFail;

/**
 If an ad fails playback but has third party (passback) ad sources, request a 
 new ad from the next available third party provider. The supplied ad (or parent 
 ad in case failedItem was an instance of VPCreative) will always be in a valid 
 state after this method returns; if the failure callback is called it will
 contain a fallback ad.

 @param failedItem The VPAd or VPCreative instance which failed playback.
 @param error A VPTrackingError code describing the reason playback failed.
 @param onSuccess A VPRequestSuccessBlock which is executed on success.
 @param onFail A VPRequestFailureBlock which is executed on failure.
 
 @return A VPRequest instance, which allows the user to cancel the request if 
         desired. Cancelling a request triggers the failure callback with the 
         supplied error.
 */
- (VPRequest*) requestPassbackWithAdOrCreative:(id)failedItem
                                         error:(VPTrackingError)error
                                       success:(VPRequestSuccessBlock)onSuccess
                                          fail:(VPRequestFailureBlock)onFail;

/** @name Misc */

/**
 Registers a handler block to be called when important information is
 available.

 @param logListener A VPLogListenerBlock which is executed to give the user information about errors, warnings and the like, which may be dispatched during ad requests.
 */
- (void)addLogListener:(VPLogListenerBlock)logListener;
@end
