//
//  UIImage.swift
//  CustomControlsSampleApp
//
//  Copyright © 2018 Ooyala. All rights reserved.
//

extension UIImage {
	
	func tintWithColor(color: UIColor, alpha: CGFloat) -> UIImage {
		let colorSpace = CGColorSpaceCreateDeviceRGB()
		let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.premultipliedLast.rawValue)
		let context = CGContext(data: nil, width: 1, height: 1, bitsPerComponent: 8, bytesPerRow: 0, space: colorSpace, bitmapInfo: bitmapInfo.rawValue)!
		context.setFillColor(color.withAlphaComponent(alpha).cgColor)
		context.fill(CGRect(x:0,y: 0, width: 1, height: 1))
		let image = UIImage(cgImage: context.makeImage()!)
		return image
	}
	
	func image(from string: String?, attributes: [AnyHashable: Any]?, size: CGSize) -> UIImage? {
		UIGraphicsBeginImageContextWithOptions(size, false, 0)
		string?.draw(in: CGRect(x: 0, y: 0, width: size.width, height: size.height), withAttributes: (attributes as! [NSAttributedStringKey : Any]))
		let image: UIImage? = UIGraphicsGetImageFromCurrentImageContext()
		UIGraphicsEndImageContext()
		return image
	}
	
}
