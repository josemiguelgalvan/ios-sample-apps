//
//  IMAPlayerViewController.m
//  OoyalaSkinSampleApp
//
//  Created by Zhihui Chen on 7/29/15.
//  Copyright (c) 2015 Facebook. All rights reserved.
//

#import "IMAPlayerViewController.h"
#import <OoyalaIMASDK/OOIMAManager.h>
#import <OoyalaSkinSDK/OoyalaSkinSDK.h>
#import <OoyalaSDK/OoyalaSDK.h>
#import "AppDelegate.h"

@interface IMAPlayerViewController ()
@property (nonatomic, retain) OOIMAManager *adsManager;
@property (nonatomic, retain) OOSkinViewController *skinController;
@property NSString *embedCode;
@property NSString *nib;
@property NSString *pcode;
@property NSString *playerDomain;
@end

@implementation IMAPlayerViewController
{
  AppDelegate *appDel;
  
}

- (id)initWithPlayerSelectionOption:(PlayerSelectionOption *)playerSelectionOption qaModeEnabled:(BOOL)qaModeEnabled {
  self = [super initWithPlayerSelectionOption: playerSelectionOption qaModeEnabled:qaModeEnabled];
  if (self.playerSelectionOption) {
    self.nib = self.playerSelectionOption.nib;
    self.embedCode = self.playerSelectionOption.embedCode;
    self.title = self.playerSelectionOption.title;
    self.playerDomain = self.playerSelectionOption.playerDomain;
    self.pcode = playerSelectionOption.pcode;
  }
  return self;
}

- (void)loadView {
  [super loadView];
  [[NSBundle mainBundle] loadNibNamed:self.nib owner:self options:nil];
}

- (void)viewDidLoad {
  [super viewDidLoad];
  appDel = [[UIApplication sharedApplication] delegate];
  // Create Ooyala ViewController
  OOOptions *options = [OOOptions new];
  OOOoyalaPlayer *ooyalaPlayer = [[OOOoyalaPlayer alloc] initWithPcode:self.pcode domain:[[OOPlayerDomain alloc] initWithString:self.playerDomain] options:options];
  OODiscoveryOptions *discoveryOptions = [[OODiscoveryOptions alloc] initWithType:OODiscoveryTypePopular limit:10 timeout:60];
  NSURL *jsCodeLocation = [[NSBundle mainBundle] URLForResource:@"main" withExtension:@"jsbundle"];
  //  NSURL *jsCodeLocation = [NSURL URLWithString:@"http://localhost:8081/index.ios.bundle?platform=ios"];
  ooyalaPlayer.actionAtEnd = OOOoyalaPlayerActionAtEndPause; //This is reccomended to make sure the endscreen shows up as expected
  OOSkinOptions *skinOptions = [[OOSkinOptions alloc] initWithDiscoveryOptions:discoveryOptions jsCodeLocation:jsCodeLocation configFileName:@"skin" overrideConfigs:nil];
  self.skinController = [[OOSkinViewController alloc] initWithPlayer:ooyalaPlayer skinOptions:skinOptions parent:_videoView launchOptions:nil];
  [self addChildViewController:_skinController];
  [_skinController.view setFrame:self.videoView.bounds];
  [ooyalaPlayer setEmbedCode:self.embedCode];
  
  [[NSNotificationCenter defaultCenter] addObserver: self
                                           selector:@selector(notificationHandler:)
                                               name:nil
                                             object:ooyalaPlayer];
  
  [[NSNotificationCenter defaultCenter] addObserver: self
                                           selector:@selector(notificationHandler:)
                                               name:nil
                                             object:self.skinController];
  // In QA Mode , making textView visible
  if (self.qaModeEnabled == YES){
    self.textView.hidden = NO;
  }
  self.adsManager = [[OOIMAManager alloc] initWithOoyalaPlayer:ooyalaPlayer];
  
  
  // Load the video
  [ooyalaPlayer setEmbedCode:self.embedCode];
}

- (void) notificationHandler:(NSNotification*) notification {
  
  // Ignore TimeChangedNotificiations for shorter logs
  if ([notification.name isEqualToString:OOOoyalaPlayerTimeChangedNotification]) {
    return;
  }
  
  NSString *message = [NSString stringWithFormat:@"Notification Received: %@. state: %@. playhead: %f count: %d",
                       [notification name],
                       [OOOoyalaPlayer playerStateToString:[self.skinController.player state]],
                       [self.skinController.player playheadTime], appDel.count];
  NSLog(@"%@",message);
  
  //In QA Mode , adding notifications to the TextView
  if (self.qaModeEnabled == YES) {
    NSString *string = self.textView.text;
    NSString *appendString = [NSString stringWithFormat:@"%@ :::::::::: %@", string, message];
    [self.textView setText:appendString];
  }
  appDel.count++;
}
@end
