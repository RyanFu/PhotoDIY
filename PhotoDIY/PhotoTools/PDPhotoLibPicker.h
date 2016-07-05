//
//  PDPhotoLibPicker.h
//  多选相册照片
//
//  Created by long on 15/11/30.
//  Copyright © 2015年 long. All rights reserved.
//

#import <UIKit/UIKit.h>
#include <AssetsLibrary/AssetsLibrary.h>

@protocol PDPhotoPickerProtocol<NSObject>

- (void)allPhotosCollected:(NSDictionary *)photoDict;
- (void)allPhotoURLsCollected:(NSArray *)photoURLs;
-(void)loadPhoto:(UIImage *)image;

@end

@interface PDPhotoLibPicker : NSObject {
    ALAssetsLibrary *library;
    NSMutableDictionary *photoDict;
    NSMutableArray *photoURLs;
}

@property (nonatomic, weak) id<PDPhotoPickerProtocol> delegate;

@property(nonatomic) CGSize itemSize;

- (instancetype)initWithDelegate:(id<PDPhotoPickerProtocol>) delegate itemSize:(CGSize)size;
+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;

- (void)getAllPictures;
-(void)pictureWithURL:(NSURL *)url;

@end