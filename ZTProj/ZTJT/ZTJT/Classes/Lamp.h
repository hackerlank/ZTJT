//
//  Lamp.h
//  ZTJT
//
//  Created by PerryMac on 3/20/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Lamp__
#define __ZTJT__Lamp__
#include "TypeDef.h"
#include "ZTObject.h"

class Lamp : public ZTObject {
public:
    Lamp();
    Lamp(POINT center, LampType type);
    ~Lamp();
    
    PRIVATE_PROPERTY(POINT,Center)
    PRIVATE_PROPERTY(LampType,Type)
    
};

#endif /* defined(__ZTJT__Lamp__) */
