//
//  AppSetting.h
//  ZTJTApp
//
//  Created by Perry on 14-9-6.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppSetting : NSObject

+ (AppSetting *) sharedInstance;

- (void) save;

- (void) setLastMapRegion:(MKCoordinateRegion)region;
- (MKCoordinateRegion) lastMapRegion;

@end
