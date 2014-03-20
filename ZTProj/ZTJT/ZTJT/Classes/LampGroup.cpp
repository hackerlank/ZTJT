//
//  Lamp.cpp
//  ZTJT
//
//  Created by PerryMac on 3/18/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "LampGroup.h"
#include "Config.h"

SYNTHESIZE(LampGroup, LampState, State)
SYNTHESIZE(LampGroup, BYTE, Lddout)

LampGroup::LampGroup()
:m_State(LampStateRed)
,m_Lddout(0)
{
    
}


LampGroup::~LampGroup()
{
    list<Lamp*>::iterator it = m_Lamps.begin();
    while (it != m_Lamps.end()) {
        delete *it;
        it++;
    }
}


UINT LampGroup::NextState()
{
    Lamp *aLamp = GetALamp();
    if (ZTNULL == aLamp) {
        return 0;
    }
    
    BYTE sel = 0;
    
    switch (aLamp->Type()) {
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

const string* LampGroup::LddoutString() const
{
    char buf[10];
    snprintf(buf, 10, "%d.%d", (m_Lddout-1)/2+1,(m_Lddout-1)%2+1);
    
    return new string(buf);
}




#pragma mark -
Lamp *LampGroup::GetALamp()const
{
    if (m_Lamps.size() > 0) {
        return m_Lamps.front();
    }
    
    return ZTNULL;
}


ZTBOOL LampGroup::AddLamp(Lamp *aLamp)
{
    m_Lamps.push_back(aLamp);
    
    return ZTTRUE;
}

void LampGroup::RemoveLamp(Lamp *aLamp)
{
    m_Lamps.remove(aLamp);
}

ZTBOOL LampGroup::HasLamp(const Lamp *aLamp)const
{
    list<Lamp *>::const_iterator it = std::find(m_Lamps.begin(), m_Lamps.end(), aLamp);
    if (m_Lamps.end() != it) {
        return ZTTRUE;
    }
    
    return ZTFALSE;
}
