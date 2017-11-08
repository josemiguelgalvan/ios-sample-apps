//
//  VPLogItem.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VPLogItem;

/**
 * A block that receives a VPLogItem instance that provides information about a logged event.
 */
typedef void(^VPLogListenerBlock)(VPLogItem* logItem);

/**
 * Indicates which subsystem is the source of a LogItem.
 */
typedef NS_ENUM(NSUInteger, VPLogItemSource) {
  /** Indicates that the LogItem relates to an ad request. */
  VPLogItemSourceAd = 0,
  /** Indicates that the LogItem relates to a session request. */
  VPLogItemSourceSession,
  /** Indicates that the LogItem relates to a tracking request. */
  VPLogItemSourceTracker

};

/**
 * Indicates which event a LogItem instance relates to.
 */
typedef NS_ENUM(NSUInteger, VPLogItemEvent) {
  /** Blank or inventory ad response received. Only dispatched during ad requests. */
  VPLogItemEventNoAdResponse = 0,
  
  /** Unaccepted or missing arguments. Only dispatched during session and tracker requests. */
  VPLogItemEventInvalidArgument,
  /** A request received an empty or malformed response. Potentially dispatched during all types of requests. */
  VPLogItemEventInvalidResponse,
  
  /** Error with no dedicated event type. Potentially dispatched during all types of requests. */
  VPLogItemEventGeneralError,
  /** HTTP request failed. Potentially dispatched during all types of requests. */
  VPLogItemEventRequestFailed,
  /** HTTP request timed out. Potentially dispatched during all types of requests. */
  VPLogItemEventRequestTimeout,
  /** SDK user canceled request. Only dispatched during ad requests. */
  VPLogItemEventRequestCanceled,
  
  /** Non-fatal warning message. Potentially dispatched during all types of requests. */
  VPLogItemEventWarning,
  /** The user tried to perform an operation not allowed in the current state. Only dispatched during tracker requests. */
  VPLogItemEventIllegalOperation

};


/**
 * Object passed to callbacks registered with {@VPAdRequester.addLogListener} and
 * {@link VPTracker.addLogListener} when errors occur.
 */
@interface VPLogItem : NSObject

/**
 * Describes the source of the LogItem. Depending on the source, not all fields might be set.
 */
@property (assign, nonatomic, readonly) VPLogItemSource source;

/**
 * Describes what type of event has occurred.
 */
@property (assign, nonatomic, readonly) VPLogItemEvent event;


/**
 * Associated error message for the log item. Can be nil if message is defined.
 */
@property (nonatomic, readonly) NSError *error;

/**
 * The path of third party ads fetched until an error occurred; only relevant when source is VPLogItemSourceAd.
 * The array will only contain instances of NSURL.
 */
@property (nonatomic, readonly) NSArray *thirdPartySourceURLs;


#pragma mark - String conversion

/**
 * Returns a string representation of the LogItem.
 */
- (NSString *)description;

/**
 * Returns a string representation of the LogItem message and/or error.
 */
- (NSString *)errorMessageDescription;

/**
 * Returns a string representation of the LogItem source.
 */
- (NSString *)sourceDescription;

/**
 * Returns a string representation of the LogItem type.
 */
- (NSString *)eventDescription;
@end
