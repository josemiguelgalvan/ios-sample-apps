//
//  CustomControlsView.swift
//  CustomControlsSampleApp
//
//  Copyright © 2018 Ooyala. All rights reserved.
//

import UIKit
import MediaPlayer

class CustomControlsView: UIView {
	
	// VARIABLES
	public private(set) var isFullscreen: Bool!
	public private(set) var isAirplay: Bool!
	public private(set) var isCast: Bool!
	
	// NAVIGATION TOP
	private var navigationBarTop: UIToolbar!
	public private(set) var titleLbl: UILabel!
	private var airplayBtn: MPVolumeView!
	
	// NAVIGATION MID
	private var navigationBarMid: UIToolbar!
	public private(set) var playPauseBtn: UIButton!
	
	// NAVIGATION BOTTOM
	private var navigationBarBottom: UIToolbar!
	public private(set) var playheadLbl: UILabel!
	public private(set) var durationLbl: UILabel!
	public private(set) var scrubberSlider: UISlider!
	public private(set) var fullscreenBtn: UIButton!
	
	// AIRPLAY & CAST
	public private(set) var device: String!
	private let keyPathForAirplay = "airplay_alpha"
	
	// Font
	private let ooyalaFont = UIFont(name: "ooyala-slick-type", size: 22)!
	private let robotoBoldFont = UIFont(name: "Roboto-Bold", size: 10)!
	
	init(frame: CGRect, controlType: OOOoyalaPlayerControlType) {
		super.init(frame: frame)
		
		clipsToBounds = true
		translatesAutoresizingMaskIntoConstraints = false
		
		isFullscreen = controlType == .fullScreen ? true : false
		isAirplay = false
		isCast = false
		
		// NAVIGATION TOP
		// NavigationBarTop
		navigationBarTop = UIToolbar(frame: CGRect.zero)
		navigationBarTop.clipsToBounds = true
		navigationBarTop.translatesAutoresizingMaskIntoConstraints = false
		
		// TitleLbl
		titleLbl = UILabel(frame: CGRect.zero)
		titleLbl.clipsToBounds = true
		titleLbl.translatesAutoresizingMaskIntoConstraints = false
		titleLbl.font = robotoBoldFont.withSize(10)
		titleLbl.textColor = .white
		titleLbl.textAlignment = .left

		// AirPlayBtn
		airplayBtn = MPVolumeView(frame: CGRect.zero)
		airplayBtn.clipsToBounds = true
		airplayBtn.translatesAutoresizingMaskIntoConstraints = false
		airplayBtn.showsRouteButton = true
		airplayBtn.showsVolumeSlider = false
		for view: UIView in airplayBtn.subviews {
			if view is UIButton {
				view.addObserver(self,
												 forKeyPath: keyPathForAirplay,
												 options: .new,
												 context: nil)
				break
			}
		}

		// NAVIGATION MID
		// navigationBarMid
		navigationBarMid = UIToolbar(frame: CGRect.zero)
		navigationBarMid.clipsToBounds = true
		navigationBarMid.translatesAutoresizingMaskIntoConstraints = false
		navigationBarMid.setBackgroundImage(UIImage(), forToolbarPosition: .any, barMetrics: .default)
		
		// PlayPauseBtn
		playPauseBtn = UIButton(frame: CGRect.zero)
		playPauseBtn.clipsToBounds = true
		playPauseBtn.translatesAutoresizingMaskIntoConstraints = false
		playPauseBtn.titleLabel?.font = ooyalaFont.withSize(40)
		
		// NAVIGATION BOTTOM
		// NavigationBarBottom
		navigationBarBottom = UIToolbar(frame: CGRect.zero)
		navigationBarBottom.clipsToBounds = true
		navigationBarBottom.translatesAutoresizingMaskIntoConstraints = false
		
		// PlayheadLbl
		playheadLbl = UILabel(frame: CGRect.zero)
		playheadLbl.clipsToBounds = true
		playheadLbl.translatesAutoresizingMaskIntoConstraints = false
		playheadLbl.font = robotoBoldFont
		playheadLbl.textColor = .white
		playheadLbl.textAlignment = .center
		playheadLbl.text = "0:00:00"
		
		// DurationLbl
		durationLbl = UILabel(frame: CGRect.zero)
		durationLbl.clipsToBounds = true
		durationLbl.translatesAutoresizingMaskIntoConstraints = false
		durationLbl.font = robotoBoldFont
		durationLbl.textColor = .white
		durationLbl.textAlignment = .center
		durationLbl.text = "0:00:00"
		
		// ScrubberSlider
		scrubberSlider = UISlider(frame: CGRect.zero)
		scrubberSlider.clipsToBounds = true
		scrubberSlider.translatesAutoresizingMaskIntoConstraints = false
		scrubberSlider.setThumbImage(UIImage(), for: .normal)
		scrubberSlider.isEnabled = false
		scrubberSlider.minimumValue = 0.0
		scrubberSlider.value = 0.0
		
		// FullscreenBtn
		fullscreenBtn = UIButton(frame: CGRect.zero)
		fullscreenBtn.clipsToBounds = true
		fullscreenBtn.translatesAutoresizingMaskIntoConstraints = false
		fullscreenBtn.titleLabel?.font = ooyalaFont
		
		// AIRPLAY & CAST

		
		setNotifications()
		airplayChanged()
	}
	
	required init?(coder aDecoder: NSCoder) {
		fatalError("init(coder:) has not been implemented")
	}
	
	public override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
		if let airplay = object as? UIButton, let value = change?[.newKey] as? Int, keyPath == keyPathForAirplay, value != 1 {
			airplay.alpha = 1.0
		}
	}
	
	private func setNotifications() {
		// Airplay
		NotificationCenter.default.addObserver(self,
																					 selector: #selector(CustomControlsView.airplayChanged),
																					 name: NSNotification.Name.AVAudioSessionRouteChange,
																					 object: AVAudioSession.sharedInstance())
		
		/*NotificationCenter.default.addObserver(self,
																					 selector: #selector(CustomControlsView.syncUI),
																					 name: NSNotification.Name.OO,
																					 object: nil)
		*/
	}
	
	@objc
	private func syncUI() {
		navigationBarTop.subviews.forEach({ $0.removeFromSuperview() })
		navigationBarMid.subviews.forEach({ $0.removeFromSuperview() })
		navigationBarBottom.subviews.forEach({ $0.removeFromSuperview() })
		
		subviews.forEach({ $0.removeFromSuperview() })
	
		// NAVIGATION TOP
		addSubview(navigationBarTop)
		navigationBarTop.heightAnchor.constraint(equalToConstant: 40).isActive = true
		navigationBarTop.topAnchor.constraint(equalTo: navigationBarTop.superview!.topAnchor).isActive = true
		navigationBarTop.leftAnchor.constraint(equalTo: navigationBarTop.superview!.leftAnchor).isActive = true
		navigationBarTop.rightAnchor.constraint(equalTo: navigationBarTop.superview!.rightAnchor).isActive = true
		navigationBarTop.setBackgroundImage(UIImage().tintWithColor(color: .red, alpha: 0.2), forToolbarPosition: .any, barMetrics: .default)
		
		navigationBarTop.addSubview(titleLbl)
		titleLbl.centerYAnchor.constraint(equalTo: navigationBarTop.centerYAnchor).isActive = true
		titleLbl.leftAnchor.constraint(equalTo: navigationBarTop.leftAnchor, constant: 10).isActive = true
		titleLbl.rightAnchor.constraint(equalTo: navigationBarTop.centerXAnchor).isActive = true
		
		navigationBarTop.addSubview(airplayBtn)
		airplayBtn.heightAnchor.constraint(equalToConstant: 34).isActive = true
		airplayBtn.widthAnchor.constraint(equalToConstant: 34).isActive = true
		airplayBtn.topAnchor.constraint(equalTo: navigationBarTop.topAnchor, constant: 3).isActive = true
		airplayBtn.rightAnchor.constraint(equalTo: navigationBarTop.rightAnchor, constant: -10).isActive = true
		
		
		
		if isAirplay {
			// NAVIGATION TOP
			navigationBarTop.setBackgroundImage(UIImage(), forToolbarPosition: .any, barMetrics: .default)
			
			// NAVIGATION BOTTOM
			addSubview(navigationBarBottom)
			navigationBarBottom.setBackgroundImage(UIImage(), forToolbarPosition: .any, barMetrics: .default)
			navigationBarBottom.heightAnchor.constraint(equalToConstant: 40).isActive = true
			navigationBarBottom.bottomAnchor.constraint(equalTo: navigationBarBottom.superview!.bottomAnchor).isActive = true
			navigationBarBottom.leftAnchor.constraint(equalTo: navigationBarBottom.superview!.leftAnchor).isActive = true
			navigationBarBottom.rightAnchor.constraint(equalTo: navigationBarBottom.superview!.rightAnchor).isActive = true
		}
		else if isCast {
			
		}
		else {
			// NAVIGATION MID
			addSubview(navigationBarMid)
			navigationBarMid.heightAnchor.constraint(equalToConstant: 50).isActive = true
			navigationBarMid.widthAnchor.constraint(equalToConstant: 50).isActive = true
			navigationBarMid.centerXAnchor.constraint(equalTo: navigationBarMid.superview!.centerXAnchor).isActive = true
			navigationBarMid.centerYAnchor.constraint(equalTo: navigationBarMid.superview!.centerYAnchor).isActive = true
			
			navigationBarMid.addSubview(playPauseBtn)
			playPauseBtn.centerXAnchor.constraint(equalTo: navigationBarMid.centerXAnchor).isActive = true
			playPauseBtn.centerYAnchor.constraint(equalTo: navigationBarMid.centerYAnchor).isActive = true
			
			// NAVIGATION BOTTOM
			addSubview(navigationBarBottom)
			navigationBarBottom.setBackgroundImage(UIImage().tintWithColor(color: .red, alpha: 0.2), forToolbarPosition: .any, barMetrics: .default)
			navigationBarBottom.heightAnchor.constraint(equalToConstant: 60).isActive = true
			navigationBarBottom.bottomAnchor.constraint(equalTo: navigationBarBottom.superview!.bottomAnchor).isActive = true
			navigationBarBottom.leftAnchor.constraint(equalTo: navigationBarBottom.superview!.leftAnchor).isActive = true
			navigationBarBottom.rightAnchor.constraint(equalTo: navigationBarBottom.superview!.rightAnchor).isActive = true
			
			navigationBarBottom.addSubview(playheadLbl)
			playheadLbl.heightAnchor.constraint(equalToConstant: 20).isActive = true
			playheadLbl.widthAnchor.constraint(equalToConstant: 50).isActive = true
			playheadLbl.topAnchor.constraint(equalTo: navigationBarBottom.topAnchor, constant: 3).isActive = true
			playheadLbl.leftAnchor.constraint(equalTo: navigationBarBottom.leftAnchor, constant: 10).isActive = true
			
			navigationBarBottom.addSubview(durationLbl)
			durationLbl.heightAnchor.constraint(equalToConstant: 20).isActive = true
			durationLbl.widthAnchor.constraint(equalToConstant: 50).isActive = true
			durationLbl.topAnchor.constraint(equalTo: navigationBarBottom.topAnchor, constant: 3).isActive = true
			durationLbl.rightAnchor.constraint(equalTo: navigationBarBottom.rightAnchor, constant: -10).isActive = true
			
			navigationBarBottom.addSubview(scrubberSlider)
			scrubberSlider.heightAnchor.constraint(equalToConstant: 20).isActive = true
			scrubberSlider.topAnchor.constraint(equalTo: navigationBarBottom.topAnchor, constant: 3).isActive = true
			scrubberSlider.leftAnchor.constraint(equalTo: navigationBarBottom.leftAnchor, constant: 70).isActive = true
			scrubberSlider.rightAnchor.constraint(equalTo: navigationBarBottom.rightAnchor, constant: -70).isActive = true
			
			navigationBarBottom.addSubview(fullscreenBtn)
			fullscreenBtn.topAnchor.constraint(equalTo: durationLbl.bottomAnchor, constant: 3).isActive = true
			fullscreenBtn.rightAnchor.constraint(equalTo: navigationBarBottom.rightAnchor, constant: -10).isActive = true
			if isFullscreen {
				fullscreenBtn.setTitle("j", for: .normal)
			}
			else {
				fullscreenBtn.setTitle("i", for: .normal)
			}
		}
		
	}
	
	@objc
	private func airplayChanged() {
		isAirplay = false
		let currentRoute = AVAudioSession.sharedInstance().currentRoute
		for output in currentRoute.outputs {
			if output.portType == AVAudioSessionPortAirPlay {
				device = output.portName
				// We need to verify if AirPlay is streaming or mirroring the device
				isAirplay = UIScreen.screens.count < 2 ? true : false
			}
		}
		syncUI()
	}
	
	deinit {
		print("CustomControlsView is destroyed")
		NotificationCenter.default.removeObserver(self)
		for view: UIView in airplayBtn.subviews {
			if view is UIButton {
				view.removeObserver(self, forKeyPath: keyPathForAirplay)
				break
			}
		}
	}
	
}
