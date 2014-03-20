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
    Lamp(POINT center, LampType type);
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
    PRIVATE_PROPERTY(LampType,Type)
    PRIVATE_PROPERTY(LampState,State)
    /*
     灯组
     如果灯组值为0，则为无法识别的灯，中间叉的图标
     */
    PRIVATE_PROPERTY(BYTE,Lddout)  //1~16
    
    UINT NextState();
    
    const string* LddoutString() const;
    
};
#endif /* defined(__ZTJT__Lamp__) */
