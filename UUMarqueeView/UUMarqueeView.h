//
//  UUMarqueeView.h
//  UUMarqueeView
//
//  Created by youyou on 16/12/5.
//  Copyright © 2016年 iceyouyou. All rights reserved.
//

#import <UIKit/UIKit.h>

@class UUMarqueeView;

typedef NS_ENUM(NSUInteger, UUMarqueeViewDirection) {
    UUMarqueeViewDirectionUpward,   // scroll from bottom to top
    UUMarqueeViewDirectionLeftward  // scroll from right to left
};

#pragma mark - UUMarqueeViewDelegate
@protocol UUMarqueeViewDelegate <NSObject>
- (NSUInteger)numberOfDataForMarqueeView:(UUMarqueeView*)marqueeView;
- (void)createItemView:(UIView*)itemView forMarqueeView:(UUMarqueeView*)marqueeView;
- (void)updateItemView:(UIView*)itemView atIndex:(NSUInteger)index forMarqueeView:(UUMarqueeView*)marqueeView;
@optional
- (NSUInteger)numberOfVisibleItemsForMarqueeView:(UUMarqueeView*)marqueeView;   // only for Upward direction
- (CGFloat)itemWidthAtIndex:(NSUInteger)index forMarqueeView:(UUMarqueeView*)marqueeView;   // only for Leftward direction
- (void)didTouchItemViewAtIndex:(NSUInteger)index forMarqueeView:(UUMarqueeView*)marqueeView;
@end

#pragma mark - UUMarqueeView
@interface UUMarqueeView : UIView
@property (nonatomic, weak) id<UUMarqueeViewDelegate> delegate;
@property (nonatomic, assign) NSTimeInterval timeIntervalPerScroll;
@property (nonatomic, assign) NSTimeInterval timeDurationPerScroll; // only for [UUMarqueeViewDirectionUpward]
@property (nonatomic, assign) float scrollSpeed;    // only for [UUMarqueeViewDirectionLeftward]
@property (nonatomic, assign) float itemSpacing;    // only for [UUMarqueeViewDirectionLeftward]
@property (nonatomic, assign) BOOL clipsToBounds;
@property (nonatomic, assign, getter=isTouchEnabled) BOOL touchEnabled;
@property (nonatomic, assign) UUMarqueeViewDirection direction;
- (instancetype)initWithDirection:(UUMarqueeViewDirection)direction;
- (instancetype)initWithFrame:(CGRect)frame direction:(UUMarqueeViewDirection)direction;
- (void)reloadData;
- (void)start;
- (void)pause;
@end

#pragma mark - UUMarqueeViewTouchResponder(Private)
@protocol UUMarqueeViewTouchResponder <NSObject>
- (void)touchAtPoint:(CGPoint)point;
@end

#pragma mark - UUMarqueeViewTouchReceiver(Private)
@interface UUMarqueeViewTouchReceiver : UIView
@property (nonatomic, weak) id<UUMarqueeViewTouchResponder> touchDelegate;
@end
