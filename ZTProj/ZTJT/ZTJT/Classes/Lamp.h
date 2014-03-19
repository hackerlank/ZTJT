//
//  Lamp.h
//  ZTJT
//
//  Created by PerryMac on 3/18/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Lamp__
#define __ZTJT__Lamp__

#include "TypeDef.h"
#include "ZTObject.h"
#include <string>
using namespace std;

class Lamp : ZTObject {
public:
    Lamp();
    Lamp(POINT center, UINT type);
    ~Lamp();
    
    /*
    VOID SetCenter(POINT center);
    POINT Center() const;
    
    VOID SetMode(UINT mode);
    UINT Mode() const;
    
    VOID SetState(BYTE state);
    BYTE State() const;
    
    VOID SetLddout(BYTE lddout);
    BYTE Lddout() const;
     */
    
    PRIVATE_PROPERTY(POINT,Center)
    /*  灯的形状
     0:人形
     1:上行
     2:下行
     3:左行
     4:右行
     5:视频
     6:手动控制
     7:圆
     8:上掉头
     9:下掉头
     10:左掉头
     11:右掉头
     12:非机动车(自行车图标)
     */
    PRIVATE_PROPERTY(UINT,Type)
    /*  灯的状态
     1:黄闪
     ***************下面几种常用
     *************人形灯
     2:红
     3:绿
     4:绿闪
     *************
     5:黄
     ***************
     6:黄红
     其他:黑
     
     */
    PRIVATE_PROPERTY(BYTE,State)
    /*
     灯组
     如果灯组值为0，则为无法识别的灯，中间叉的图标
     */
    PRIVATE_PROPERTY(BYTE,Lddout)  //1~16
    PRIVATE_PROPERTY(BYTE,Pro)
    
    UINT NextMode();
    
    const string* LddoutString() const;
    
};
#endif /* defined(__ZTJT__Lamp__) */
