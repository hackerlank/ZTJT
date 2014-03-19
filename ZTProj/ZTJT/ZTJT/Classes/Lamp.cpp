//
//  Lamp.cpp
//  ZTJT
//
//  Created by PerryMac on 3/18/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Lamp.h"


Lamp::Lamp()
:m_center({0,0})
,m_mode(0)
,m_state(0)
,m_lddout(0)
{
    
}

Lamp::Lamp(POINT center)
:m_center(center)
,m_mode(0)
,m_state(0)
,m_lddout(0)
{
    
}

Lamp::~Lamp()
{
    
}

SYNTHESIZE(Lamp, BYTE,Pro)

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