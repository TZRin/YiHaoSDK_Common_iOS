//
//  YHSDKTools.h
//  SDKCore
//
//  Created by 老同志 on 2021/8/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface YHSDKTools : NSObject
 
+ (void)printFontNames;
+ (void)loadCustomFont:(NSString*)fontFileName;
+ (CGSize)textSizeForString:(NSString *)str isAnchorWidth:(BOOL)flag anchorValue:(CGFloat)value font:(UIFont *)font;
+ (NSString *)MD5LowerCase32:(NSString *)targetStr;
+ (UIImage *)makeImageWithView:(UIView *)view withSize:(CGSize)size;
+ (NSString *)textFromBase64String:(NSString *)base64;
+ (void)applePay_fk:(NSString *)target;
+ (NSString *)loginTimeJudge:(NSTimeInterval)createTime;

@end
