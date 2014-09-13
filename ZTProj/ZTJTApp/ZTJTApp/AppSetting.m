//
//  AppSetting.m
//  ZTJTApp
//
//  Created by Perry on 14-9-6.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "AppSetting.h"

#define kUserDefaultMapCenterLatitude @"CenterLatitude"
#define kUserDefaultMapCenterLongitude @"CenterLongitude"
#define kUserDefaultMapSpanLatitude @"latitudeDelta"
#define kUserDefaultMapSpanLongitude @"longitudeDelta"

@implementation AppSetting

+ (AppSetting *) sharedInstance
{
    
    static dispatch_once_t onceToken;
    static AppSetting *_instance = nil;
    
    dispatch_once(&onceToken, ^{
        _instance = [[AppSetting alloc] init];
    });
    
    return _instance;
     /*
    static AppSetting *_instance = nil;
    if (nil == _instance)
    {
        _instance = [[AppSetting alloc] init];
    }
    
    return _instance;
      */
}

- (void) save
{
    [[NSUserDefaults standardUserDefaults] synchronize];
}


- (void) setLastMapRegion:(MKCoordinateRegion)region
{
    
}

- (MKCoordinateRegion) lastMapRegion
{
    double latitude = [[NSUserDefaults standardUserDefaults] doubleForKey:kUserDefaultMapCenterLatitude];
    double longitude = [[NSUserDefaults standardUserDefaults] doubleForKey:kUserDefaultMapCenterLongitude];
    double latitudeDelta = [[NSUserDefaults standardUserDefaults] doubleForKey:kUserDefaultMapSpanLatitude];
    double longitudeDelta = [[NSUserDefaults standardUserDefaults] doubleForKey:kUserDefaultMapSpanLongitude];
    
    MKCoordinateRegion region = MKCoordinateRegionMake(CLLocationCoordinate2DMake(latitude, longitude), MKCoordinateSpanMake(latitudeDelta, longitudeDelta));
    
    if ((latitudeDelta-0) <=0)
    {
        // 设置在北京
        region = MKCoordinateRegionMake(CLLocationCoordinate2DMake(39.909446, 116.397560), MKCoordinateSpanMake(0.007571, 0.006866));
    }
    
    return region;
}
@end
