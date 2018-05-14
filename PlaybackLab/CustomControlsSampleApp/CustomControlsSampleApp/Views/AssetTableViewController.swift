//
//  AssetTableViewController.swift
//  CustomControlsSampleApp
//
//  Copyright © 2018 Ooyala. All rights reserved.
//

import UIKit

let PLAYER_SEGUE_IDENTIFIER  = "PlayerViewControllerSegue"

class AssetTableViewController: UITableViewController {
	
	private let options = OptionDataSource.options()
	
	override func viewDidLoad() {
		super.viewDidLoad()
		tableView.tableFooterView = UIView()
		tableView.bounces = false
		tableView.rowHeight = 50.0
	}
	
	override func viewDidAppear(_ animated: Bool) {
		super.viewDidAppear(animated)
	}
	
	override func viewWillAppear(_ animated: Bool) {
		super.viewWillAppear(animated)
		AppUtility.lockOrientation(.portrait, andRotateTo: .portrait)
	}
	
	override func viewWillDisappear(_ animated: Bool) {
		super.viewWillAppear(animated)
		AppUtility.lockOrientation(.all)
	}
	
	// MARK: - Table view data source
	override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
		return options.count
	}
	
	override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
		let cell = tableView.dequeueReusableCell(withIdentifier: CELL_REUSE_IDENTIFIER, for: indexPath) as! OptionTableViewCell
		let option = options[indexPath.row]
		cell.setup(option: option)
		return cell
	}
	
	// MARK: - Navigation
	override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
		// When tapping on a cell, we'll transition to the PlayerViewController.
		// If that's the case set the PlayerSelectionOption for the player.
		if let cell = sender as? OptionTableViewCell,
			let option = cell.option,
			segue.identifier == PLAYER_SEGUE_IDENTIFIER {
			let playerViewController = segue.destination as! PlayerViewController
			playerViewController.option = option
		}
	}
	
}
