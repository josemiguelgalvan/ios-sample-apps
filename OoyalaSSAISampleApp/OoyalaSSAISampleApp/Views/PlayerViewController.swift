//
//  PlayerViewController.swift
//  OoyalaSSAISampleApp
//
//  Copyright © 2018 Ooyala. All rights reserved.
//

import UIKit

class PlayerViewController: UIViewController {
  
  @IBOutlet weak var playerView: UIView!
  
  @IBOutlet weak var btnSetPlayerParams: MyButton!
  @IBOutlet weak var txtViewPlayerParams: MyTextView!
  @IBOutlet weak var txtViewLog: MyTextView!
  
  public var option: PlayerSelectionOption!
  public var usesSkin: Bool!
  public var qaLogEnabled: Bool!
  
  private var player: OOOoyalaPlayer!
  
  // properties required for a Fairplay asset
  private var apiKey = ""
  private var apiSecret = ""
  
  private var ssaiPlugin: OOSsaiPlugin!
  
  override func viewDidLoad() {
    super.viewDidLoad()
    title = option.title
    qaEnabled()
    var ooyalaPlayerViewController: UIViewController
    if option.embedTokenGenerator != nil {
      if option.embedTokenGenerator is BasicEmbedTokenGenerator {
        let basicEmbedTokenGen = option.embedTokenGenerator as! BasicEmbedTokenGenerator
        apiKey = basicEmbedTokenGen.apiKey
        apiSecret = basicEmbedTokenGen.apiSecret
      }
      else {
        // If you're not using the BasicEmbedTokenGenerator provided in the example,
        // supply your own API_KEY and API_SECRET
        apiKey = "API_KEY"
        apiSecret = "API_SECRET"
      }
      let options = OOOptions()!
      // For this example, we use the OOEmbededSecureURLGenerator to create the signed URL on the client
      // This is not how this should be implemented in production -
      // In production, you should implement your own OOSecureURLGenerator
      // which contacts a server of your own, which will help sign the url with the appropriate API Key and Secret
      options.secureURLGenerator = OOEmbeddedSecureURLGenerator(apiKey: apiKey,
                                                                secret: apiSecret)
      player = OOOoyalaPlayer(pcode: option.pcode,
                              domain: option.domain,
                              embedTokenGenerator: option.embedTokenGenerator,
                              options: options)
      
    }
    else {
      player = OOOoyalaPlayer(pcode: option.pcode,
                              domain: option.domain)
    }
    
    if usesSkin {
      let jsCodeLocation = Bundle.main.url(forResource: "main",
                                           withExtension: "jsbundle")
      
      let skinOptions = OOSkinOptions(discoveryOptions: nil,
                                      jsCodeLocation: jsCodeLocation,
                                      configFileName: "skin",
                                      overrideConfigs: nil)
      
      ooyalaPlayerViewController = OOSkinViewController(player: player,
                                                        skinOptions: skinOptions,
                                                        parent: playerView,
                                                        launchOptions: nil)
    }
    else {
      ooyalaPlayerViewController = OOOoyalaPlayerViewController(player: player)
    }
    
    player.setEmbedCode(option.embedCode)
    
    addChildViewController(ooyalaPlayerViewController)
    playerView.addSubview(ooyalaPlayerViewController.view)
    ooyalaPlayerViewController.view.frame = playerView.bounds
    
    // Ooyala SSAI Plugin
    ssaiPlugin = OOSsaiPlugin()
    ssaiPlugin.register(player)
    
    if qaLogEnabled {
      NotificationCenter.default.addObserver(self,
                                             selector: #selector(notificationHandler(notification:)),
                                             name: nil,
                                             object: player)

    }
  }
  
  // MARK: - QA Log
  @objc
  private func notificationHandler(notification: NSNotification) {
    //"Notification Received: \(notification.name.rawValue). state: \(OOOoyalaPlayer.playerState(toString: player.state())!). playhead: \(player.playheadTime())"
    var message = ""
    
    if ( notification.name == NSNotification.Name.OOOoyalaPlayerTimeChanged ){
      return;
    }
    
    message = "Notification Received: \(notification.name.rawValue). state: \(OOOoyalaPlayer.playerState(toString: player.state())!). playhead: \(String(format: "%.2f", player.playheadTime()))"
    
    if (message.isEmpty) {
      return;
    }
    
    txtViewLog.text  = "\(message)\n\(txtViewLog.text!)"
    
  }
  
  // MARK: - SSAI Plugin
  @objc
  private func setPlayerParams() {
    let params = txtViewPlayerParams.text
    if ( ssaiPlugin.setParams(params) && ssaiPlugin.player().state != .playing ){
      player.setEmbedCode(option.embedCode)
    }
  }
  
  // MARK: - Utils
  private func qaEnabled() {
    if qaLogEnabled {
      btnSetPlayerParams.addTarget(self, action: #selector(setPlayerParams), for: .touchUpInside)
    }
    else {
      let navigationBarHeight = (navigationController?.navigationBar.frame.size.height)! + (navigationController?.navigationBar.frame.origin.y)!
      playerView.frame = CGRect(x: 0,
                                y: navigationBarHeight,
                                width: view.frame.width,
                                height: view.frame.height - navigationBarHeight)
      btnSetPlayerParams.isHidden = true
      txtViewPlayerParams.isHidden = true
      txtViewLog.isHidden = true
    }
  }
  
  // MARK: - Denit
  deinit {
    if qaLogEnabled {
      NotificationCenter.default.removeObserver(self)
    }
    ssaiPlugin.deregister(player)
    print("PlayerViewController: Deinit complete.")
  }
}
