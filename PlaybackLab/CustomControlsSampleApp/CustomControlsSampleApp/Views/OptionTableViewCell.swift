//
//  OptionTableViewCell.swift
//  CustomControlsSampleApp
//
//  Copyright © 2018 Ooyala. All rights reserved.
//

import UIKit

let CELL_REUSE_IDENTIFIER = "OptionCellReuseIdentifier"

class OptionTableViewCell: UITableViewCell {
	
	/**
	Shows the title of the asset
	*/
	@IBOutlet weak var titleLabel: UILabel!
	
	/**
	The option contains the info concerning this cell.
	The cell cares a lot about the embed code to know what to do
	when it gets the embed code through a notification, for example.
	*/
	public private(set) var option: PlayerSelectionOption!
	
	func setup(option: PlayerSelectionOption) {
		self.option = option
		titleLabel.text = self.option.title
	}
	
}
