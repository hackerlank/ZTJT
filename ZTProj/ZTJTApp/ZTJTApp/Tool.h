//
//  Tool.h
//  ZTJTApp
//
//  Created by Perry on 14-9-7.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <string>
using namespace std;

@interface Tool : NSObject
// 将std::string转化成NSString
+ (NSString *) OS2SS:(const string *)str;

@end



#define OS2SS(str) [Tool OS2SS:str]