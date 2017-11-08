//
//  VPConstants.h
//  Pulse
//
//  Created by Jacques du Toit on 21/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const VPCoreVersion;

extern NSString * const VPCoreErrorDomain;
extern NSString * const VPCoreRequestErrorDomain;

enum {
  VPCoreErrorRequestedPassbackBeforeThirdPartyReady      = 1,
  VPCoreErrorRequestedPassbackAfterError                 = 2,
  VPCoreErrorRequestedPassbackAfterImpression            = 3,
  VPCoreErrorRequestedPassbackWhenNoneAvailable          = 4,
  
  VPCoreErrorRequestedExistingInsertionPointTypes        = 5,
  VPCoreErrorRequestedExistingPlaybackPositions          = 6,

  VPCoreErrorInvalidTrackingError                        = 7,
  VPCoreErrorAlreadyTrackedEvent                         = 8,
  VPCoreErrorCannotTrackAfterError                       = 9,
  VPCoreErrorReportedErrorAfterTrackingImpression        = 10,

  VPCoreErrorInvalidTrackable                            = 12,

  VPCoreErrorReceivedInvalidResponse                     = 13,
  VPCoreErrorReceivedInvalidValue                        = 14,
  VPCoreErrorReceivedInvalidAttributeValue               = 15,
  VPCoreErrorReceivedMalformedXML                        = 16,
  VPCoreErrorReceivedInvalidURL                          = 40,
  
  VPCoreErrorMismatchingTags                             = 88,

  VPCoreErrorInvalidValue                                = 17,
  VPCoreErrorLinearPlaybackPositionsIgnored              = 18,
  VPCoreErrorNonLinearPlaybackPositionsIgnored           = 19,

  VPCoreErrorNoAdResponse                                = 20,
  
  // The object is already waiting for a response from a third party
  VPCoreErrorObjectPartOfOngoingRequest                  = 21,
  VPCoreErrorAdNotReady                                  = 22,
  
  VPCoreErrorIllegalOperation                            = 30
};

enum {
  VPCoreRequestErrorUnknown  = -1,
  VPCoreRequestErrorTimedOut = -1001,
  
  // Positive error values correspond to HTTP status codes
};

extern NSString * const VPCoreInvalidURLKey;

extern NSString * const VPCoreExcludedInsertionPointsKey;
extern NSString * const VPCoreExcludedPlaybackPositionsKey;

extern NSString * const VPCoreTrackerEventTypeKey;
extern NSString * const VPCoreTrackerCustomEventNameKey;
extern NSString * const VPCoreTrackerTrackingErrorKey;

extern NSString * const VPCoreValidationInvalidFieldKey;

extern NSString * const VPCoreInternalErrorException;
extern NSString * const VPCoreIllegalOperationException;
