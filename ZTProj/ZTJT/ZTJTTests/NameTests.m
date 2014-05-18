//
//  NameTests.m
//  ZTJT
//
//  Created by Perry on 14-5-10.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Name.h"

@interface NameTests : XCTestCase

@end

@implementation NameTests

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
    Name name({10,10});
    name.setNameStr("abcd");
    
    BYTE *pByte = ZTNULL;
    INT len = 0;
    name.GenerateBinary(pByte, len);
    
    HexOutput(pByte, len);
}

@end
