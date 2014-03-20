//
//  Lamp.cpp
//  ZTJT
//
//  Created by PerryMac on 3/18/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Lamp.h"
#include "Config.h"

Lamp::Lamp()
:m_Center({0,0})
,m_Type(LampTypeRound)
,m_State(LampStateRed)
,m_Lddout(0)
{
    
}

Lamp::Lamp(POINT center, LampType type)
:m_Center(center)
,m_Type(type)
,m_State(LampStateRed)
,m_Lddout(0)
{
    
}

Lamp::~Lamp()
{
    
}

SYNTHESIZE(Lamp, POINT, Center)
SYNTHESIZE(Lamp, LampType, Type)
SYNTHESIZE(Lamp, LampState, State)
SYNTHESIZE(Lamp, BYTE, Lddout)
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

UINT Lamp::NextState()
{
    BYTE sel = 0;
    switch (m_Type) {
        case LampTypeWalk:
            sel = Config::GetInstance()->GetLampWalkSelectableStateValue();
            break;
        case LampTypeUp:
        case LampTypeDown:
        case LampTypeLeft:
        case LampTypeRight:
        case LampTypeUpTurnAround:
        case LampTypeDownTurnAround:
        case LampTypeLeftTurnAround:
        case LampTypeRightTurnAround:
            sel = Config::GetInstance()->GetLampCommSelectableStateValue();
            break;
        case LampTypeVDU:
            sel = Config::GetInstance()->GetLampVDUSelectableStateValue();
            break;
        case LampTypeManual:
            sel = Config::GetInstance()->GetLampManualSelectableStateValue();
            break;
            
        default:
            break;
    }
    
    UINT st = (UINT)m_State;
    
    
    BYTE cursor = 0x01;
    cursor = cursor<<st;    //左移st位，
    while (++st!=m_State) {
        cursor=cursor<<1;
        if (0 == cursor) { //如果游标溢出。那么重新赋值为1
            cursor = 1;
        }
        if (8 == st) {     //如果state超过BYTE的位数，那么复位从0开始判断
            st = 0;
        }
        if (cursor&sel) {
            break;
        }
        
    }
    
    m_State = (LampState)st;
    
    return m_State;
    
}

const string* Lamp::LddoutString() const
{
    char buf[10];
    snprintf(buf, 10, "%d.%d", (m_Lddout-1)/2+1,(m_Lddout-1)%2+1);
    
    return new string(buf);
}