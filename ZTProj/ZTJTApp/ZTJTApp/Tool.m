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
@end
