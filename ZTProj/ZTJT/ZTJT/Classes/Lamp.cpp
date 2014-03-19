//
//  Lamp.cpp
//  ZTJT
//
//  Created by PerryMac on 3/18/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Lamp.h"


Lamp::Lamp()
:m_Center({0,0})
,m_Type(0)
,m_State(2)
,m_Lddout(0)
{
    
}

Lamp::Lamp(POINT center, UINT type)
:m_Center(center)
,m_Type(7)
,m_State(2)
,m_Lddout(0)
{
    
}

Lamp::~Lamp()
{
    
}

SYNTHESIZE(Lamp, POINT, Center)
SYNTHESIZE(Lamp, UINT, Type)
SYNTHESIZE(Lamp, BYTE, State)
SYNTHESIZE(Lamp, BYTE, Lddout)
SYNTHESIZE(Lamp, BYTE, Pro)
/*
VOID Lamp::SetCenter(POINT center)
{
    m_center = center;
}

POINT Lamp::Center() const
{
    return m_center;
}

VOID Lamp::SetMode(UINT mode)
{
    m_mode = mode;
}

UINT Lamp::Mode() const
{
    return m_mode;
}

VOID Lamp::SetState(BYTE state)
{
    m_state = state;
}

BYTE Lamp::State() const
{
    return m_state;
}

VOID Lamp::SetLddout(BYTE lddout)
{
    m_lddout = lddout;
}

BYTE Lamp::Lddout() const
{
    return m_lddout;
}
*/

UINT Lamp::NextMode()
{
    return 0;
    
}

const string* Lamp::LddoutString() const
{
    char buf[10];
    snprintf(buf, 10, "%d.%d", (m_Lddout-1)/2,(m_Lddout-1)%2+1);
    
    return new string(buf);
}