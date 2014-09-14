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
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    NSLocale *locale = [[NSLocale alloc] initWithLocaleIdentifier:@"zh"];
    [formatter setLocale:locale];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss cccc"];
    
    return [formatter stringFromDate:self];;
}
@end
