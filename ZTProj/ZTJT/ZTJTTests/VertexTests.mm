//
//  VertexTests.m
//  ZTJT
//
//  Created by Perry on 14-5-3.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Vertex.h"
#import "Debug.h"

@interface VertexTests : XCTestCase

@end

@implementation VertexTests

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
    Vertex v({22,33});
    BYTE *pByte = ZTNULL;
    INT len = 0;
    v.generateBinary(pByte, len);
    
    HexOutput(pByte, len);
}

@end
