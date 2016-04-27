//
//  ViewController.m
//  CocoaPodsTVSampleApp
//
//  Created by Eric Vargas on 4/27/16.
//  Copyright © 2016 Ooyala. All rights reserved.
//

#import "ViewController.h"
#import <OoyalaTVSDK/OOOoyalaPlayer.h>
#import <OoyalaTVSDK/OOPlayerDomain.h>

@interface ViewController ()

@property (nonatomic, strong) NSString *pcode;
@property (nonatomic, strong) NSString *embedCode;
@property (nonatomic, strong) NSString *playerDomain;

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  self.pcode =@"R2d3I6s06RyB712DN0_2GsQS-R-Y";
  self.embedCode = @"Y1ZHB1ZDqfhCPjYYRbCEOz0GR8IsVRm1";
  self.playerDomain = @"http://www.ooyala.com";
  
  self.player = [[OOOoyalaPlayer alloc] initWithPcode:self.pcode domain:[[OOPlayerDomain alloc] initWithString:self.playerDomain]];
  
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationHandler:) name:nil object:self.player];
  
  // currently, enables seek backward or forward using remote control left and right
  self.showsPlaybackControls = YES;
  
  if ([self.player setEmbedCode:self.embedCode]) {
    [self.player play];
  }
}

- (void)notificationHandler:(NSNotification *)notification
{
  if ([notification.name isEqualToString:OOOoyalaPlayerTimeChangedNotification]) {
    return;
  }
  
  NSLog(@"Notification Received: %@. state: %@. playhead: %f",
        [notification name],
        [OOOoyalaPlayer playerStateToString:[self.player state]],
        [self.player playheadTime]);
}


@end
