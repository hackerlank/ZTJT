//
//  ZTAnnotation.h
//  ZTJTApp
//
//  Created by Perry on 14-7-19.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZTAnnotation : NSObject <MKAnnotation>
@property (assign, nonatomic) CLLocationCoordinate2D coordinate;
@property (copy, nonatomic) NSString *title;
@property (copy, nonatomic) NSString *subtitle;
@end
