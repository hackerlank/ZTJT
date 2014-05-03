//
//  StatusTests.m
//  ZTJT
//
//  Created by Perry on 14-5-2.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Status.h"
#import "Debug.h"

@interface StatusTests : XCTestCase
{
    Status *_status;
}

@end

@implementation StatusTests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
    _status = new Status;
}

- (void)tearDown
{
    delete _status;
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
    
    
}

- (void)testgenerateBinary
{
    _status->setTime(2);
    _status->setMaxTime(2);
    _status->setMinTime(2);
    _status->setVduPhase(0);
    
    _status->SetLddoutStatus(1,2);
    _status->SetLddoutStatus(2,2);
    
    BYTE *pData = nil;
    INT len = 0;
    _status->generateBinary(pData, len);
    
    HexOutput(pData, len);
}

@end
