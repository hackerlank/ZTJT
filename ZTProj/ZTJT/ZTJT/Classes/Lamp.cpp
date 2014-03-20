//
//  Lamp.cpp
//  ZTJT
//
//  Created by PerryMac on 3/20/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Lamp.h"

Lamp::Lamp()
{
    
}

Lamp::Lamp(POINT center, LampType type)
:m_Center(center)
,m_Type(type)
{
    
}

Lamp::~Lamp()
{
    
}

SYNTHESIZE(Lamp, POINT, Center)
SYNTHESIZE(Lamp, LampType, Type)
