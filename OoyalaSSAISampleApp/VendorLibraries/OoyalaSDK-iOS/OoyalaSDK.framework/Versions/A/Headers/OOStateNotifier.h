//
//  OOStateNotifier.h
//  OoyalaSDK
//
// Copyright (c) 2015 Ooyala, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OOAdPodInfo.h"

@class OOSsaiAdsMetadata;

@interface OOStateNotifier : NSObject

@property OOOoyalaPlayerState state;

- (void)notifyPlayheadChange;
- (void)notifyAdsLoaded;
- (void)notifyAdSkipped;
- (void)notifyAdStarted;
- (void)notifyAdCompleted;


/**
 * Notifies the player the ads metadata has been received.
 * Used for SSAI ads.
 * @param duration Total time of the asset, including ads
 * @param adTimilne The raw array of ads returned by the SSAI server
 */
- (void)notifySSAIAdsMetadataReceived:(OOSsaiAdsMetadata *)adsMetadata;

/**
 * Notifies the player a when an SSAI ad break has started
 */
- (void)notifySSAIAdPlaying:(OOAdPodInfo *)adPodInfo;

/**
 * Notifies the player a when an SSAI ad break has ended
 */
- (void)notifySSAIAdPlayed;

@end
