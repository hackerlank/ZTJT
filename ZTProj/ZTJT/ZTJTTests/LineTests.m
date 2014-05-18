//
//  LineTests.m
//  ZTJT
//
//  Created by Perry on 14-5-3.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Line.h"
#import "Debug.h"

@interface LineTests : XCTestCase

@end

@implementation LineTests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testGenerateBinary
{
    Line l({22,33}, {66,77});
    l.SetColor(LineColorYellow);
    l.SetWidth(LineWidth4);
    
    BYTE *pByte = ZTNULL;
    INT len = 0;
    l.GenerateBinary(pByte, len);
    
    HexOutput(pByte, len);
}

@end
