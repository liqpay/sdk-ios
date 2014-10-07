//
//  OneClickPay.h
//  OneClickPay
//
//  Created by Serg Cyclone on 08.04.14.
//  Copyright (c) 2014 PrivatBank. All rights reserved.
//


@protocol OneClickPayDelegate;
@protocol OneClickPayDataSource;

@interface OneClickPay : NSObject

-(void)setDelegate:(id<OneClickPayDelegate>)delegate;
-(void)setDataSource:(id<OneClickPayDataSource>)dataSource;

- (void)pay;

- (void)cardList;
- (void)history;

+ (instancetype)sharedInstance;
+ (instancetype)sharedInstanceWithDataSource:(id<OneClickPayDataSource>)dataSource andDelegate:(id<OneClickPayDelegate>)delegate;

@end


@protocol OneClickPayDataSource <NSObject>

- (NSString *)oneClickPayMerchantID;
- (NSString *)oneClickPayPhoneNumber;
- (NSString *)oneClickPayAmount;
- (NSString *)oneClickPayCurrency;
- (NSString *)oneClickPayDescription;

@optional
- (NSString *)oneClickPayCardID;

- (BOOL)oneClickPaySuppressHUD;
- (BOOL)oneClickPayShouldRotate;
@end


@protocol OneClickPayDelegate <NSObject>

- (void)oneClickFailedWithError:(NSError *)error;
- (void)oneClickPaySuccessWithID:(NSString *)payment_id;

- (void)oneClickPayCardList:(NSArray *)cardList;
- (void)oneClickPayHistory:(NSArray *)history;

@end