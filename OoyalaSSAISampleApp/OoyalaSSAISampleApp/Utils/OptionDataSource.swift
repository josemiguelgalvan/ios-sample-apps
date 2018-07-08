//
//  OptionDataSource.swift
//  OoyalaSSAISampleApp
//
//  Copyright © 2018 Ooyala. All rights reserved.
//

import UIKit

class OptionDataSource: NSObject {
  
  class func options() -> [PlayerSelectionOption] {
    return [
      PlayerSelectionOption(embedCode: "ltZ3l5YjE6lUAvBdflvcDQ-zti8q8Urd",
                            pcode: "RpOWUyOq86gFq-STNqpgzhzIcXHV",
                            title: "SSAI VOD - Videoplaza",
                            domain: OOPlayerDomain(string: "http://www.ooyala.com")),
      PlayerSelectionOption(embedCode: "lkb2cyZjE6wp94YSGIEjm6Em1yH0P3zT",
                            pcode: "RpOWUyOq86gFq-STNqpgzhzIcXHV",
                            title: "SSAI Live - Videoplaza",
                            domain: OOPlayerDomain(string: "http://www.ooyala.com")),
      // if required, add more test cases here
    ]
  }
  
}
