//
//  LampTests.c
//  ZTJT
//
//  Created by PerryMac on 3/20/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include <stdio.h>
#import <XCTest/XCTest.h>
#include "LampGroup.h"
#include "Config.h"

@interface LampGroupTests : XCTestCase {
}

@end

@implementation LampGroupTests

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

- (void)testLddoutString
{
    LampGroup *group1 = new LampGroup;
    const string *lddoutString = nil;
    
    group1->setLddout(1);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="1.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(2);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="1.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(3);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="2.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(4);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="2.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(5);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="3.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(6);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="3.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(7);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="4.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(8);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="4.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(9);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="5.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(10);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="5.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(11);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="6.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(12);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="6.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(13);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="7.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(14);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="7.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(15);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="8.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    group1->setLddout(16);
    lddoutString = group1->LddoutString();
    XCTAssertTrue(*lddoutString=="8.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    delete group1;
}


- (void)testNextState {
    LampGroup *group = new LampGroup;
    Lamp *alamp = new Lamp({0,0}, LampTypeWalk);
    group->AddLamp(alamp);
    /***************测试默认值****************/
    //测试人行灯
    group->setState(LampStateRed);
    
    UINT st = group->NextState();
    XCTAssertTrue(st==(LampState)3, @"st=%d", st);
    
    group->setState((LampState)3);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)4, @"st=%d", st);
    
    group->setState((LampState)4);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)0);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    delete group;
    
    
    group = new LampGroup;
    alamp = new Lamp({0,0}, LampTypeUp);
    group->AddLamp(alamp);
    //测试普通灯
    group->setState(LampStateRed);
    
    st = group->NextState();
    XCTAssertTrue(st==(LampState)3, @"st=%d", st);
    
    group->setState((LampState)3);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)4, @"st=%d", st);
    
    group->setState((LampState)4);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)5, @"st=%d", st);
    
    group->setState((LampState)5);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)0);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)1);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)6);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    delete group;
    
    //测试视频
    group = new LampGroup;
    alamp = new Lamp({0,0}, LampTypeVDU);
    group->AddLamp(alamp);
    //测试VDU
    group->setState(LampStateRed);
    
    st = group->NextState();
    XCTAssertTrue(st==(LampState)0, @"st=%d", st);
    
    group->setState((LampState)0);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)5);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)0, @"st=%d", st);
    
    group->setState((LampState)1);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    //测试灯的可选状态只有一种的情况
    //测试VDU
    Config::GetInstance()->SetLampVDUSelectableState(LampStateBlack, ZTFALSE);
    group->setState(LampStateRed);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)0);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)5);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)1);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    delete group;
    
    /***************测试修改配置值****************/
    Config::GetInstance()->SetLampCommSelectableState(LampStateBlack, ZTTRUE);
    //测试普通灯
    group = new LampGroup;
    alamp = new Lamp({0,0}, LampTypeUp);
    group->AddLamp(alamp);
    
    group->setState(LampStateRed);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)3, @"st=%d", st);
    
    group->setState((LampState)3);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)4, @"st=%d", st);
    
    group->setState((LampState)4);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)5, @"st=%d", st);
    
    group->setState((LampState)5);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)0, @"st=%d", st);
    
    group->setState((LampState)0);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)1);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    group->setState((LampState)6);
    st = group->NextState();
    XCTAssertTrue(st==(LampState)0, @"st=%d", st);
    
    delete group;
}


- (void)testGenerateBinary
{
    //测试普通灯
    LampGroup *group = new LampGroup;
    Lamp *alamp = new Lamp({0,0}, LampTypeWalk);
    group->AddLamp(alamp);
    
    alamp = new Lamp({100,20}, LampTypeDown);
    group->AddLamp(alamp);
    
    alamp = new Lamp({300,50}, LampTypeLeft);
    group->AddLamp(alamp);
    
    BYTE *pByte = ZTNULL;
    INT len = 0;
    group->GenerateBinary(pByte, len);
    
    HexOutput(pByte, len);
}
@end