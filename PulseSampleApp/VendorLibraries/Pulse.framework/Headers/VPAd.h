//
//  VPAd.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Pulse/VPTrackable.h>

@class VPSlot;
@class VPAdPricing;
@class VPAdSystem;

/**
 Defines the potential types, or ad formats,
 a VPAd instance can describe.
 */
typedef NS_ENUM(NSUInteger, VPAdType) {
	/** Unknown or unspecified ad format, or a lazy ad which has not yet been loaded. */
  VPAdTypeUnknown = 0,
  /** Inventory ad. */
  VPAdTypeInventory = 1,
  /** Standard spot ad. */
  VPAdTypeStandardSpot = 2,
  /** Interactive spot ad. */
  VPAdTypeInteractiveSpot = 3,
  /** Selector ad. */
  VPAdTypeSpotSelector = 4,
  /** Takeover ad. */
  VPAdTypeTakeoverSpot = 5,
  /** Overlay ad. */
  VPAdTypeStandardOverlay = 6,
  /** Video overlay ad. */
  VPAdTypeVideoOverlay = 7,
  /** Imageset overlay ad. */
  VPAdTypeImagesetOverlay = 8,
  /** Splash overlay ad. */
  VPAdTypeSplashOverlay = 9,
  /** Splash ad. */
  VPAdTypeStandardSplash = 10,
  /** Player inskin. */
  VPAdTypeInSkin = 11
};

/**
 Defines the variant of an ad, or, 
 whether or not it is a sponsor ad.
 */
typedef NS_ENUM(NSUInteger, VPAdVariant){

    /** Normal ad. */
    VPAdVariantNormal = 0,
    
    /** Sponsor ad. */
    VPAdVariantSponsor = 1
};

/**
 VPAd contains basic information about an ad, such as ad format, id, et cetera.
 */
@interface VPAd : NSObject <VPTrackable>

/**
 The type, or ad format, of the ad.
 @see VPAdType
 */
- (VPAdType)type;

/**
 The ad variant type.
 @see VPAdVariant
 */
- (VPAdVariant)variant;

/**
 The ad id.
 */
- (NSString *)identifier;

/**
 The creatives for this ad, as an array of VPCreative instances.
 */
- (NSArray *)creatives;

/**
 The companions to show along with this ad, as an array of VPCompanion instances.
 */
- (NSArray *)companions;

/**
 The VPSlot this ad is a part of.
 */
- (VPSlot *)parentSlot;

/**
 Tracking events that apply to this object.
 */
- (VPTrackingEvents *)trackingEvents;

/**
 Indicates whether the ad is ready to be displayed.
 If false, it needs to be retrieved on demand using [VPAdRequester requestThirdPartyWithContainer:success:].
 */
- (BOOL)isReady;

/**
 The maximum time in seconds the SDK waits for a 'lazy' ad to load (including potential passback candidate requests).
 */
- (NSTimeInterval)maximumPreparationTime;

/**
 The maximum time in seconds the end user should be allowed to wait for an ad to load before the ad must be discarded.
 */
- (NSTimeInterval)startTimeout;

/**
 The candidate ad number in the passback chain.
 */
- (NSInteger)candidateNum;

/**
 The custom ad identifier set in the Ooyala Pulse UI.
*/
- (NSString *)customIdentifier;

/**
 The Identifier of the campaign to which the ad belongs; supplied by Ooyala Pulse.
*/
- (NSString *)campaignIdentifier;

/**
 The custom Identifier of the campaign to which the ad belongs; set in the Ooyala Pulse UI.
 */
- (NSString *)customCampaignIdentifier;

/**
  The Identifier of the goal to which the ad belongs; supplied by Ooyala Pulse.
*/
- (NSString *)goalIdentifier;

/**
 The custom Identifier of the goal to which the ad belongs; set in the Ooyala Pulse UI.
*/
- (NSString *)customGoalIdentifier;

/**
 Whether or not the ad can change linearity or not.
*/
- (BOOL)allowLinearityToChange;

/**
 Whether or not the ad is part of an exclusive campaign.
*/
- (BOOL)partOfAnExclusiveCampaign;

/**
 Whether or not to display a remaining time countdown when this ad is being displayed.
*/
- (BOOL)showCountdown;

/**
 Returns YES if this ad has passback ad sources available.
 */
- (BOOL)hasPassback;

/**
 A Boolean value that identifies a conditional ad. A value of true indicates that the ad is conditional and should be used in all cases where the inline executable unit (such as VPAID) is not an ad but is instead a framework for finding an ad; a value of false is the default value and indicates that an ad is available.
 */
- (BOOL)isConditionalAd;

/**
 List of available ads for the user to choose from, when ad type is VPAdTypeSpotSelector.
 */
- (NSArray *)ads;

/**
 A URL to any resource relating to an integrated survey.
 */
- (NSURL *)survey;

/**
 An array containing all the VPSurvey elements, containing any resource relating to an integrated survey.
 */
- (NSArray *)surveys;

/**
 A string that provides a common name for the ad.
 */
- (NSString *)title;

/**
 A string that provides the name of the advertiser as defined by the ad serving party.
 */
- (NSString *)advertiser;

/**
 A string value that describes a longer description of the ad.
 */
- (NSString *)adDescription;

/**
 Used to provide a value that represents a price that can be used by real-time bidding (RTB) systems.
 */
- (VPAdPricing *)adPricing;

/**
 An array of VPAdCategory objects containing the categories of the Ad and their responsible authorities.
 */
- (NSArray *)categories;

/**
 An array containing the VPAdVerification elements, which are used to initiate a controlled container where code can be executed for collecting data to verify ad playback details.
 */
- (NSArray *)adVerifications;

/**
 Information about the system that serves the ad.
 */
- (VPAdSystem *)adSystem;

@end
