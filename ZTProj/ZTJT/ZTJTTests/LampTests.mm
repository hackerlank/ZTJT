//
//  LampTests.c
//  ZTJT
//
//  Created by PerryMac on 3/20/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include <stdio.h>
#import <XCTest/XCTest.h>
#include "Lamp.h"
#include "Config.h"

@interface LampTests : XCTestCase {
    Lamp *_lamp;
}

@end

@implementation LampTests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
    _lamp = new Lamp;
    _lamp->setCenter({0,0});
    _lamp->setType(LampTypeUp);
    _lamp->setLddout(1);
    _lamp->setState(LampStateRed);
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    delete _lamp;
    
    [super tearDown];
}

- (void)testLddoutString
{
    const string *lddoutString = nil;
    
    _lamp->setLddout(1);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="1.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(2);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="1.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(3);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="2.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(4);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="2.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(5);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="3.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(6);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="3.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(7);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="4.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(8);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="4.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(9);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="5.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(10);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="5.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(11);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="6.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(12);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="6.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(13);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="7.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(14);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="7.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(15);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="8.1", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
    
    _lamp->setLddout(16);
    lddoutString = _lamp->LddoutString();
    XCTAssertTrue(*lddoutString=="8.2", @"%@",[NSString stringWithUTF8String:lddoutString->c_str()]);
}


- (void)testNextState {
    /***************测试默认值****************/
    //测试人行灯
    _lamp->setType(LampTypeWalk);
    _lamp->setState(LampStateRed);
    
    UINT st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)3, @"st=%d", st);
    
    _lamp->setState((LampState)3);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)4, @"st=%d", st);
    
    _lamp->setState((LampState)4);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    _lamp->setState((LampState)0);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    //测试普通灯
    _lamp->setType(LampTypeUp);
    _lamp->setState(LampStateRed);
    
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)3, @"st=%d", st);
    
    _lamp->setState((LampState)3);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)4, @"st=%d", st);
    
    _lamp->setState((LampState)4);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)5, @"st=%d", st);
    
    _lamp->setState((LampState)5);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    _lamp->setState((LampState)0);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    _lamp->setState((LampState)1);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    _lamp->setState((LampState)6);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    //测试VDU
    _lamp->setType(LampTypeVDU);
    _lamp->setState(LampStateRed);
    
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)0, @"st=%d", st);
    
    _lamp->setState((LampState)0);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    _lamp->setState((LampState)5);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)0, @"st=%d", st);
    
    _lamp->setState((LampState)1);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    
    
    /***************测试修改配置值****************/
    Config::GetInstance()->SetLampCommSelectableState(LampStateBlack, ZTTRUE);
    //测试普通灯
    _lamp->setType(LampTypeUp);
    _lamp->setState(LampStateRed);
    
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)3, @"st=%d", st);
    
    _lamp->setState((LampState)3);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)4, @"st=%d", st);
    
    _lamp->setState((LampState)4);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)5, @"st=%d", st);
    
    _lamp->setState((LampState)5);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)0, @"st=%d", st);
    
    _lamp->setState((LampState)0);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    _lamp->setState((LampState)1);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)2, @"st=%d", st);
    
    _lamp->setState((LampState)6);
    st = _lamp->NextState();
    XCTAssertTrue(st==(LampState)0, @"st=%d", st);
}

@end