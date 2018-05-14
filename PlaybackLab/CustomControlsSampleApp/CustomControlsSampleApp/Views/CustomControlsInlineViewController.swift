//
//  CustomControlsInlineViewController.swift
//  CustomControlsSampleApp
//
//  Copyright © 2018 Ooyala. All rights reserved.
//

import UIKit

class CustomControlsInlineViewController: OOControlsViewController {
	
	override func viewDidLoad() {
		if player == nil {
			return
		}
		
		controls = CustomControlsView(frame: player.view.bounds,
																	controlType: .inline)
		
		(controls as! CustomControlsView).playPauseBtn.addTarget(self,
																														 action: #selector(CustomControlsInlineViewController.playPause),
																														 for: .touchUpInside)
		
		(controls as! CustomControlsView).fullscreenBtn.addTarget(self,
																															action: #selector(CustomControlsInlineViewController.fullscreen),
																															for: .touchUpInside)
		super.viewDidLoad()
	}
	
	override func viewWillAppear(_ animated: Bool) {
		NotificationCenter.default.addObserver(self,
																					 selector: #selector(CustomControlsInlineViewController.playerStateChanged),
																					 name: NSNotification.Name.OOOoyalaPlayerStateChanged,
																					 object: nil)
		
		NotificationCenter.default.addObserver(self,
																					 selector: #selector(CustomControlsInlineViewController.playerTimeChanged),
																					 name: NSNotification.Name.OOOoyalaPlayerTimeChanged,
																					 object: nil)
		
			
		playerStateChanged()
		super.viewWillAppear(animated)
	}
	
	override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
		if controls != nil && !(controls as! CustomControlsView).isAirplay {
			super.touchesEnded(touches, with: event)
		}
	}
	
	@objc
	private func fullscreen() {
		delegate.setFullScreen(CustomControlsFullscreenViewController(controlsType: .fullScreen,
																																	player: player,
																																	overlay: overlay,
																																	delegate: delegate))
		delegate.setFullscreen(true)
	}
	
	@objc
	private func playPause() {
		if player != nil {
			if player.isPlaying() {
				player.pause()
			}
			else {
				player.play()
			}
		}
	}
	
	@objc
	private func playerStateChanged() {
		if player != nil && controls != nil {
			switch (player.state()) {
			case .ready:
				(controls as! CustomControlsView).titleLbl.text = player.currentItem?.title
				(controls as! CustomControlsView).playPauseBtn.setTitle("h", for: .normal)
				(controls as! CustomControlsView).playheadLbl.text = Utils.stringFromTimeInterval(interval: player.playheadTime())
				(controls as! CustomControlsView).durationLbl.text = "-\(Utils.stringFromTimeInterval(interval: player.duration() - player.playheadTime()))"
				(controls as! CustomControlsView).scrubberSlider.minimumValue = Float(0.0)
				(controls as! CustomControlsView).scrubberSlider.maximumValue = Float(player.duration())
				(controls as! CustomControlsView).scrubberSlider.value = Float(player.playheadTime())
			case .playing:
				(controls as! CustomControlsView).playPauseBtn.setTitle("g", for: .normal)
			case .loading, .paused:
				(controls as! CustomControlsView).playPauseBtn.setTitle("h", for: .normal)
			case .completed:
				(controls as! CustomControlsView).playPauseBtn.setTitle("h", for: .normal)
				(controls as! CustomControlsView).scrubberSlider.value = Float(player.duration())
			default:
				break
			}
		}
	}
	
	@objc
	private func playerTimeChanged() {
		if player != nil && controls != nil {
			(controls as! CustomControlsView).scrubberSlider.minimumValue = Float(0.0)
			(controls as! CustomControlsView).scrubberSlider.maximumValue = Float(player.duration())
			(controls as! CustomControlsView).scrubberSlider.value = Float(player.playheadTime())
			(controls as! CustomControlsView).playheadLbl.text = Utils.stringFromTimeInterval(interval: player.playheadTime())
			(controls as! CustomControlsView).durationLbl.text = "-\(Utils.stringFromTimeInterval(interval: player.duration() - player.playheadTime()))"
		}
	}
	
	deinit {
		print("CustomControlsInlineViewController is destroyed")
	}
	
}
