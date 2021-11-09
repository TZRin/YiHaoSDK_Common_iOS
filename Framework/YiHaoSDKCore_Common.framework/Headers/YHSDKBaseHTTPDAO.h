//
//  YHSDKBaseHTTPDAO.h
//  SDKCore
//
//  Created by 老同志 on 2021/8/25.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>
 
typedef NS_ENUM(NSInteger, DaoErrorInterceptStyle) {
    DaoErrorInterceptStyleBeforeChain,
    DaoErrorInterceptStyleAfterChain,
    DaoErrorInterceptStyleSkip
};

typedef void (^DaoSuccessCallBack)(id data);
typedef void (^DaoErrorCallBack)(NSString * msg,NSInteger code);

@interface YHSDKBaseHTTPDAO : NSObject

+ (void)get:(NSString*)URLString parameters:(id)parameters showHUD:(BOOL)showHUD
successCallBack:(DaoSuccessCallBack)successCallBack
errorCallBack:(DaoErrorCallBack)errorCallBack withStyle:(DaoErrorInterceptStyle)daoErrorInterceptStyle;

+ (void)post:(NSString*)URLString parameters:(id)parameters showHUD:(BOOL)showHUD
successCallBack:(DaoSuccessCallBack)successCallBack
errorCallBack:(DaoErrorCallBack)errorCallBack withStyle:(DaoErrorInterceptStyle)daoErrorInterceptStyle;

+ (void)post_channel:(NSString*)URLString parameters:(id)parameters showHUD:(BOOL)showHUD
successCallBack:(DaoSuccessCallBack)successCallBack
errorCallBack:(DaoErrorCallBack)errorCallBack withStyle:(DaoErrorInterceptStyle)daoErrorInterceptStyle;

@end
 
