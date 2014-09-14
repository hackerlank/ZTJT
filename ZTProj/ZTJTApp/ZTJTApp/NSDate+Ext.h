//
//  NSDate+Ext.h
//  ZTJTApp
//
//  Created by Perry on 14-9-13.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (Ext)
// 返回形如 “2014-9-13 20:13:45” 的字符串
- (NSString *) stringFormat1;
// 返回形如 "2014-9-13 20:13:45 星期六" 的字符串
- (NSString *) stringFormat2;
@end
