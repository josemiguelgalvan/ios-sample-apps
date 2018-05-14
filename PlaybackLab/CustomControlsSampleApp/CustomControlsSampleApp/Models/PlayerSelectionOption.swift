//
//  PlayerSelectionOption.swift
//  CustomControlsSampleApp
//
//  Copyright © 2018 Ooyala. All rights reserved.
//

import UIKit

class PlayerSelectionOption: NSObject {
	
	public private(set) var domain: OOPlayerDomain
	
	public private(set) var pcode: String
	
	public private(set) var embedCode: String
	
	public private(set) var title: String
	
	public private(set) weak var embedTokenGenerator: OOEmbedTokenGenerator?
	
	init(embedCode: String, pcode: String, title: String, domain: OOPlayerDomain) {
		self.embedCode = embedCode
		self.pcode = pcode
		self.title = title
		self.domain = domain
		super.init()
	}
	
	convenience init(embedCode: String, pcode: String, title: String, domain: OOPlayerDomain, embedTokenGenerator: OOEmbedTokenGenerator) {
		self.init(embedCode: embedCode, pcode: pcode, title: title, domain: domain)
		self.embedTokenGenerator = embedTokenGenerator
	}
	
	
}
