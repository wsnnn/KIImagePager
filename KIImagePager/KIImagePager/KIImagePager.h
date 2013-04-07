//
//  KIImagePager.h
//  KIImagePager
//
//  Created by Marcus Kida on 07.04.13.
//  Copyright (c) 2013 Marcus Kida. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#import "UIImageView+WebCache.h"

@class KIImagePager;

@protocol KIImagePagerDataSource

@required
- (NSArray *) arrayWithImageUrlStrings;
- (UIViewContentMode) contentModeForImage:(NSUInteger)image;

@optional
- (UIImage *) placeHolderImageForImagePager;

@end

@protocol KIImagePagerDelegate

@optional
- (void) imagePager:(KIImagePager *)imagePager didScrollToIndex:(NSUInteger)index;
- (void) imagePager:(KIImagePager *)imagePager didSelectImageAtIndex:(NSUInteger)index;

@end

@interface KIImagePager : UIView

@property (weak) IBOutlet id <KIImagePagerDataSource> dataSource;
@property (weak) IBOutlet id <KIImagePagerDelegate> delegate;

@property (assign) UIViewContentMode contentMode;
@property (nonatomic, retain) UIPageControl *pageControl;

- (void) reloadData;

@end

