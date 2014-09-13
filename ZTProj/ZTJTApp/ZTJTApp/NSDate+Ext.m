//
//  NSDate+Ext.m
//  ZTJTApp
//
//  Created by Perry on 14-9-13.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "NSDate+Ext.h"

@implementation NSDate (Ext)
- (NSString *) stringFormat1
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    
    return [formatter stringFromDate:self];
}

- (NSString *) stringFormat2
{
    return nil;
}
@end
