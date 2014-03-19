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

class Lamp : ZTObject {
private:
    POINT m_center;
    UINT m_mode;
    BYTE m_state;
    BYTE m_lddout;
    
public:
    Lamp();
    Lamp(POINT center);
    ~Lamp();
    
    VOID SetCenter(POINT center);
    POINT Center() const;
    
    VOID SetMode(UINT mode);
    UINT Mode() const;
    
    VOID SetState(BYTE state);
    BYTE State() const;
    
    VOID SetLddout(BYTE lddout);
    BYTE Lddout() const;
    
    PROPERTY(BYTE,Pro)
    
};
#endif /* defined(__ZTJT__Lamp__) */
