//
//  Config.cpp
//  ZTJT
//
//  Created by PerryMac on 3/20/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Config.h"


const string Config::KConfigKeyLampWalkSelectableState = "KConfigKeyLampWalkSelectableState";
const string Config::KConfigKeyLampCommSelectableState = "KConfigKeyLampCommSelectableState";
const string Config::KConfigKeyLampVDUSelectableState = "KConfigKeyLampVDUSelectableState";
const string Config::KConfigKeyLampManualSelectableState = "KConfigKeyLampManualSelectableState";

Config::Config()
{
    m_Configs[KConfigKeyLampWalkSelectableState] = 0x1C;
    m_Configs[KConfigKeyLampCommSelectableState] = 0x3C;
    m_Configs[KConfigKeyLampVDUSelectableState] = 0x05;
    m_Configs[KConfigKeyLampManualSelectableState] = 0x05;
}

Config::~Config()
{
    
}

Config *Config::GetInstance()
{
    static Config *_instance = ZTNULL;
    if (ZTNULL == _instance) {
        _instance = new Config;
    }
    
    return _instance;
}


BYTE Config::GetLampWalkSelectableStateValue()
{
    return m_Configs[KConfigKeyLampWalkSelectableState];
}

BYTE Config::GetLampCommSelectableStateValue()
{
    return m_Configs[KConfigKeyLampCommSelectableState];
}

BYTE Config::GetLampVDUSelectableStateValue()
{
    return m_Configs[KConfigKeyLampVDUSelectableState];
}

BYTE Config::GetLampManualSelectableStateValue()
{
    return m_Configs[KConfigKeyLampManualSelectableState];
}


//设置灯的可选值
VOID Config::SetLampWalkSelectableState(LampState st, ZTBOOL selectable)
{
    BYTE sel = m_Configs[KConfigKeyLampWalkSelectableState];
    
    BYTE cur = 1;
    cur<<=(UINT)st;
    
    sel |= cur;
    m_Configs[KConfigKeyLampWalkSelectableState] = sel;
}

VOID Config::SetLampCommSelectableState(LampState st, ZTBOOL selectable)
{
    BYTE sel = m_Configs[KConfigKeyLampCommSelectableState];
    
    BYTE cur = 1;
    cur<<=(UINT)st;
    
    sel |= cur;
    m_Configs[KConfigKeyLampCommSelectableState] = sel;
}

VOID Config::SetLampVDUSelectableState(LampState st, ZTBOOL selectable)
{
    BYTE sel = m_Configs[KConfigKeyLampVDUSelectableState];
    
    BYTE cur = 1;
    cur<<=(UINT)st;
    
    if (selectable) {
        sel |= cur;
    }else {
        sel &= ~cur;
    }
    
    m_Configs[KConfigKeyLampVDUSelectableState] = sel;
}

VOID Config::SetLampManualSelectableState(LampState st, ZTBOOL selectable)
{
    BYTE sel = m_Configs[KConfigKeyLampManualSelectableState];
    
    BYTE cur = 1;
    cur<<=(UINT)st;
    
    sel |= cur;
    m_Configs[KConfigKeyLampManualSelectableState] = sel;
}

//判断灯状态是否可选
ZTBOOL Config::GetLampWalkSelectableState(LampState st)
{
    BYTE sel = m_Configs[KConfigKeyLampWalkSelectableState];
    
    BYTE cur = 1;
    cur<<=(UINT)st;
    
    return sel&cur;
}

ZTBOOL Config::GetLampCommSelectableState(LampState st)
{
    BYTE sel = m_Configs[KConfigKeyLampCommSelectableState];
    
    BYTE cur = 1;
    cur<<=(UINT)st;
    
    return sel&cur;
}

ZTBOOL Config::GetLampVDUSelectableState(LampState st)
{
    BYTE sel = m_Configs[KConfigKeyLampVDUSelectableState];
    
    BYTE cur = 1;
    cur<<=(UINT)st;
    
    return sel&cur;
}

ZTBOOL Config::GetLampManualSelectableState(LampState st)
{
    BYTE sel = m_Configs[KConfigKeyLampManualSelectableState];
    
    BYTE cur = 1;
    cur<<=(UINT)st;
    
    return sel&cur;
}