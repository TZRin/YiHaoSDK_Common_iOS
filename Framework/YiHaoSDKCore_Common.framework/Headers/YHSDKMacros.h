//
//  YiHaoGamesSDKMacros.h
//  SDKCore
//
//  Created by 老同志 on 2021/8/24.
//

#ifndef YiHaoGamesSDKMacros_h
#define YiHaoGamesSDKMacros_h
  
// ===============         ===============
// =============== Network ===============
// ===============         ===============
#define HTTPHOST @"https://sdk-server-songwogz.yihao.com"

// ===============        ===============
// =============== System ===============
// ===============        ===============

#define DidInstallReportingKey @"DidInstallReportingString"

#define YHSDKLogSwitch(l) ({\
    BOOL isOpenLog = l==0?NO:YES; \
    [[NSUserDefaults standardUserDefaults] setBool:isOpenLog forKey:@"yhsdklogswkey"]; \
})
 
#define SDKLog(FORMAT, ...) {\
NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];\
[dateFormatter setDateStyle:NSDateFormatterMediumStyle];\
[dateFormatter setTimeStyle:NSDateFormatterShortStyle];\
NSTimeZone* timeZone = [NSTimeZone timeZoneWithName:@"Asia/Beijing"];\
[dateFormatter setTimeZone:timeZone];\
[dateFormatter setDateFormat:@"HH:mm:ss.SSSSSSZ"];\
NSString *str = [dateFormatter stringFromDate:[NSDate date]];\
if ([[NSUserDefaults standardUserDefaults] boolForKey:@"yhsdklogswkey"])\
fprintf(stderr,"--TIME：%s【FILE：%s--LINE：%d】FUNCTION：%s\n%s\n",[str UTF8String],[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__,__PRETTY_FUNCTION__,[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);\
}


// ===============    ===============
// =============== UI ===============
// ===============    ===============

//font
#define kFontAliPHRegular(num) [UIFont fontWithName:@"AlibabaPuHuiTi_2_55_Regular" size:(num)]
#define kFontAliPHMedium(num)  [UIFont fontWithName:@"AlibabaPuHuiTi_2_65_Medium" size:(num)]

#define isiPAD ({\
    BOOL isiPAD = NO; \
    isiPAD = (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad); \
    isiPAD; \
})

// size
#define kUIRefereWidth  (isiPAD?1600.0:1080.0)  // 手机参考宽度
#define kUIRefereHeight (isiPAD?2560.0:1920.0)  // 手机参考高度

#define kOrientationScreenWidth ({\
    CGFloat w = 0.f; \
    if ([[UIScreen mainScreen] bounds].size.width>[[UIScreen mainScreen] bounds].size.height) { \
        w = [[UIScreen mainScreen] bounds].size.height;\
    } else { \
        w = [[UIScreen mainScreen] bounds].size.width;\
    }\
    w; \
})

#define kOrientationScreenHeight ({\
    CGFloat h = 0.f; \
    if ([[UIScreen mainScreen] bounds].size.width>[[UIScreen mainScreen] bounds].size.height) { \
        h = [[UIScreen mainScreen] bounds].size.width;\
    } else { \
        h = [[UIScreen mainScreen] bounds].size.height;\
    }\
    h; \
})

//  (设计图的值/设计图屏幕尺寸) * 当前屏幕尺寸 = 返回的值
#define kAdaptX(x,padx) (((isiPAD?padx:x)/kUIRefereWidth)*kOrientationScreenWidth)
#define kAdaptY(y,pady) (((isiPAD?pady:y)/kUIRefereHeight)*kOrientationScreenHeight)

#define kAdaptW(w,padw) (((isiPAD?padw:w)/kUIRefereWidth)*kOrientationScreenWidth)
#define kAdaptH(h,padh) (((isiPAD?padh:h)/kUIRefereHeight)*kOrientationScreenHeight)

#define kAdaptFont(s) (((s)/kUIRefereWidth)*kOrientationScreenWidth)

#define kScreenW ([UIScreen mainScreen].bounds.size.width)
#define kScreenH ([UIScreen mainScreen].bounds.size.height)

//colors
#define kHexColorAlpha(rgbValue,a)   [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]
#define kHexColor(rgbValue)          [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define kRGBColor(r, g, b)             [UIColor colorWithRed:((r) / 255.0) green:((g) / 255.0) blue:((b) / 255.0) alpha:1.0]
#define kRGBColorAlpha(r, g, b, a)     [UIColor colorWithRed:((r) / 255.0) green:((g) / 255.0) blue:((b) / 255.0) alpha:(a)]

//images
#define kSDKImage(name) [UIImage imageNamed:[NSString stringWithFormat:@"SDKResources.bundle/%@",name]]

#define isHaveSafeArea ({\
    BOOL isBangsScreen = NO; \
    if (@available(iOS 11.0, *)) { \
    UIWindow *window = [[UIApplication sharedApplication].windows firstObject]; \
    isBangsScreen = window.safeAreaInsets.bottom > 0; \
    } \
    isBangsScreen; \
})

#define TopSafeAreaHeight ({\
    CGFloat height = 0.f; \
    if (@available(iOS 11.0, *)) { \
    UIWindow *window = [[UIApplication sharedApplication].windows firstObject]; \
    height = window.safeAreaInsets.top; \
    } \
    height; \
})

#define BottomSafeAreaHeight ({\
    CGFloat height = 0.f; \
    if (@available(iOS 11.0, *)) { \
    UIWindow *window = [[UIApplication sharedApplication].windows firstObject]; \
    height = window.safeAreaInsets.bottom; \
    } \
    height; \
})

#define LeftSafeAreaWidth ({\
    CGFloat width = 0.f; \
    if (@available(iOS 11.0, *)) { \
    UIWindow *window = [[UIApplication sharedApplication].windows firstObject]; \
    width = window.safeAreaInsets.left; \
    } \
    width; \
})

#define RightSafeAreaWidth ({\
    CGFloat width = 0.f; \
    if (@available(iOS 11.0, *)) { \
    UIWindow *window = [[UIApplication sharedApplication].windows firstObject]; \
    width = window.safeAreaInsets.right; \
    } \
    width; \
})

#define kStatusBarHeight ({\
    CGFloat height = 0.f; \
    if (@available(iOS 13.0, *)) { \
    height = [UIApplication sharedApplication].keyWindow.windowScene.statusBarManager.statusBarFrame.size.height; \
    } else { \
    height = [[UIApplication sharedApplication] statusBarFrame].size.height; \
    } \
    height; \
})

// ===============       ===============
// =============== Tools ===============
// ===============       ===============
#define WeakObj(o) try{}@finally{} __weak typeof(o) o##Weak = o;
#define StrongObj(o) autoreleasepool{} __strong typeof(o) o = o##Weak;
#define kUserDefaults [NSUserDefaults standardUserDefaults]
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )

#endif /* YiHaoGamesSDKMacros_h */
