//
//  VPTracker.h
//  Pulse
//
//  Created by Jacques du Toit on 04/05/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPLogItem.h>
#import <Pulse/VPTrackable.h>
#import <Pulse/VPLinearCreative.h>

/// Error types that can be tracked
typedef NS_ENUM(NSUInteger, VPTrackingError) {
  /// Indicates that an unsupported ad type was received
  VPTrackingErrorAdTypeNotSupported,
  /// Indicates that an ad response without an ad, or an inventory response, was received
  VPTrackingErrorAdNoAd,
  /// Indicates that an unspecified error occured with the ad or ad request
  VPTrackingErrorAdGeneralError,
  
  /// Indicates that a request for the given media file or resource file resulted in a 404 response
  VPTrackingErrorCreativeMediaFileNotFound,
  /// Indicates that a request for the given media file or resource timed out before completing
  VPTrackingErrorCreativeMediaFileTimeout,
  /// Indicates that no media file or resource supported by the player could be found
  VPTrackingErrorCreativeNoSupportedMediaFileFound,
  /// Indicates that the media file loaded could not be displayed
  VPTrackingErrorCreativeMediaFileDisplayError
};

typedef NS_ENUM (NSUInteger, VPTrackingPulseError) {
  
  VPTrackingPulseErrorStartAdTimeout,
  VPTrackingPulseErrorPassbackTimeout,
  VPTrackingPulseErrorXmlParsingError,
  VPTrackingPulseErrorVastValidation,
  VPTrackingPulseErrorVastResponseError,
  VPTrackingPulseErrorAdTypeNotSupported,
  VPTrackingPulseErrorAdLinearityError,
  VPTrackingPulseErrorWrapperError,
  VPTrackingPulseErrorWrapperTimeout,
  VPTrackingPulseErrorNoVastResponseError,
  VPTrackingPulseErrorGeneralLinearError,
  VPTrackingPulseErrorLinearMediaFileNotFound,
  VPTrackingPulseErrorMediaFileTimout,
  VPTrackingPulseErrorNoSupportedMediaFileFound,
  VPTrackingPulseErrorMediaFileDisplayError,
  VPTrackingPulseErrorUndefinedError
};

/// Event types that can be tracked
typedef NS_ENUM(NSInteger, VPTrackingEventType) {
  /// Ad impression, i.e. the first frame of an Ad has been displayed
  VPTrackingEventAdImpression = 0,

  /// Indicates that an individual creative of an ad was viewed.
  VPTrackingEventCreativeView = 100,
  /// Indicates that a creative has begun playing
  VPTrackingEventCreativeStart,
  /// Indicates that a creative has played for at least 25% of its duration
  VPTrackingEventCreativeFirstQuartile,
  /// Indicates that a creative has played for at least 50% of its duration
  VPTrackingEventCreativeMidPoint,
  /// Indicates that a creative has played for at least 75% of its duration
  VPTrackingEventCreativeThirdQuartile,
  /// Indicates that a creative has played until completion
  VPTrackingEventCreativeComplete,
  /// Indicates that the user clicked a creative and loaded its associated landing page
  VPTrackingEventCreativeClickThrough,
  /// Indicates that the user muted a creative
  VPTrackingEventCreativeMute,
  /// Indicates that the user unmuted a creative
  VPTrackingEventCreativeUnmute,
  /// Indicates that the user paused playback of a creative
  VPTrackingEventCreativePause,
  /// Indicates that the user rewinded playback a creative
  VPTrackingEventCreativeRewind,
  /// Indicates that the user resumed playback of a creative after having previously paused or stopped it
  VPTrackingEventCreativeResume,
  /// Indicates that the user entered fullscreen mode for a creative
  VPTrackingEventCreativeFullscreen,
  /// Indicates that the user exited fullscreen mode for a creative
  VPTrackingEventCreativeExitFullscreen,
  /// Indicates that the user expanded a creative
  VPTrackingEventCreativeExpand,
  /// Indicates that the user collapsed an expanded creative
  VPTrackingEventCreativeCollapse,
  /// Indicates that the user chose one ad out of several, or chose to move to an additional portion of a creative
  VPTrackingEventCreativeAcceptInvitation,
  /// Indicates that the user closed the video player or player page
  VPTrackingEventCreativeClose,
  /// Indicates that the user chose to skip a creative
  VPTrackingEventCreativeSkip,
  // Indicates that the ad was viewed
  VPTrackingEventAdImpressionViewable,
  // Indicates that the ad was not viewed
  VPTrackingEventAdImpressionNotViewable,
  // Indicates that the viewing of the ad couldn't be determined
  VPTrackingEventAdImpressionViewUndetermined,
  /// Indicates that the video content has started playback.
  VPTrackingEventSessionContentStart = 200
};


/**
 The Tracker is used to send tracking information to Ooyala Pulse and third parties when various events happen,
 such as impression, ad completion, and so on. For a list of possible events, see VPTrackingEventType.
*/
@interface VPTracker : NSObject

/** @name Instantiate */

/**
 Creates a VPTracker
 */
+ (instancetype)tracker;


/** @name Tracking */

/**
 Report error on a object of class VPAd or VPCreative.
 
 @param error The tracking error to report
 @param trackable The trackable object to report the error on. Objects of class VPAd and VPCreative are allowed.
 */
- (void)reportError:(VPTrackingError)error withTrackable:(id<VPTrackable>)trackable;

/**
 Report pulse error on a object of class VPAd.
 
 @param pulseError The tracking pulse error to report
 @param ad The VPAd object to report the error on.
 @param candidateNum The number of the candidate ad in the passback chain.  
 */
- (void)reportPulseError:(VPTrackingPulseError)pulseError withAd:(VPAd *)ad candidateNum:(NSInteger)candidateNum;


/**
 Track event for a object of class VPSession, VPAd or VPCreative.
 
 @param eventType The type of the standard tracking event to track
 @param trackable The trackable to track the event on. Objects of class VPSession, VPAd and VPCreative are allowed.
 */
- (void)trackEvent:(VPTrackingEventType)eventType withTrackable:(id<VPTrackable>)trackable;

/**
 Track custom event for an object of class VPAd or VPCreative.
 
 @param eventName The name of the custom event to track
 @param trackable The trackable to track the event on. Objects of class VPAd and VPCreative are allowed.

 */
- (void)trackCustomEvent:(NSString*)eventName withTrackable:(id<VPTrackable>)trackable;

/**
 Track progress on a creative. 
 
 @param time The time in seconds since the start of playback.
 @param creative The linear creative for which to track progress.
 */
- (void)trackProgressEvent:(NSTimeInterval)time withLinearCreative:(VPLinearCreative *)creative;

/**
 Track time spent on a creative.
 
 @param timeSpent The time spent in seconds
 @param creative The creative for which to track progress.
 */
- (void)trackTimeSpentEvent:(NSTimeInterval)timeSpent withCreative:(VPCreative *)creative;

/** @name Misc */

/**
 Registers a handler block to be called when important information is
 available.
 
 @param logListener A block which is executed to give the user information about errors, warnings and the like, which may be dispatched during ad or tracking requests.
 */
- (void)addLogListener:(VPLogListenerBlock)logListener;

/**
 Returns a string description of passed event type.
 
 @param eventType The VPTrackingEventType for which a description is requested.
 */
+ (NSString *)descriptionForEventType:(VPTrackingEventType)eventType;

@end
