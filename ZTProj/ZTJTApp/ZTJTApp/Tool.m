//
//  Tool.m
//  ZTJTApp
//
//  Created by Perry on 14-9-7.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "Tool.h"



@implementation Tool

+ (NSString *) OS2SS:(const string *)str
{
    return [NSString stringWithCString:str->c_str() encoding:NSUTF8StringEncoding];
}

+ (NSString *) dayOfWeek:(NSInteger)index
{
    switch (index)
    {
        case 0:
            return @"星期日";
            break;
        case 1:
            return @"星期一";
            break;
        case 2:
            return @"星期二";
            break;
        case 3:
            return @"星期三";
            break;
        case 4:
            return @"星期四";
            break;
        case 5:
            return @"星期五";
            break;
        case 6:
            return @"星期六";
            break;
        default:
            return nil;
            break;
    }
}
@end
