//
//  Config.h
//  ZTJT
//
//  Created by PerryMac on 3/20/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Config__
#define __ZTJT__Config__

#include "TypeDef.h"
#include <map>
#include <string>
using namespace std;



/*
 此类用来配置一些选项
 1:灯的可用状态，(人行灯、普通灯）
 */
class Config {
public:
    Config();
    ~Config();
    
    static Config *GetInstance();
    /*
     LampStateBlack,                 bit0
     LampStateYellowShine = 1,       bit1
     LampStateRed,                   bit2
     LampStateGreen,                 bit3
     LampStateGreenShine,            bit4
     LampStateYellow,                bit5
     LampStateYellowRed,             bit6
     */
    static const string KConfigKeyLampWalkSelectableState;   //人行灯可选状态
    static const string KConfigKeyLampCommSelectableState;   //普通灯可选状态
    static const string KConfigKeyLampVDUSelectableState;    //视频可选状态
    static const string KConfigKeyLampManualSelectableState; //手动可选状态
    
    //获取整个BYTE
    BYTE GetLampWalkSelectableStateValue();
    BYTE GetLampCommSelectableStateValue();
    BYTE GetLampVDUSelectableStateValue();
    BYTE GetLampManualSelectableStateValue();
    //设置灯的可选值
    VOID SetLampWalkSelectableState(LampState st, ZTBOOL selectable);
    VOID SetLampCommSelectableState(LampState st, ZTBOOL selectable);
    VOID SetLampVDUSelectableState(LampState st, ZTBOOL selectable);
    VOID SetLampManualSelectableState(LampState st, ZTBOOL selectable);
    //判断灯状态是否可选
    ZTBOOL GetLampWalkSelectableState(LampState st);
    ZTBOOL GetLampCommSelectableState(LampState st);
    ZTBOOL GetLampVDUSelectableState(LampState st);
    ZTBOOL GetLampManualSelectableState(LampState st);
private:
    map<string, BYTE> m_Configs;
};

#endif /* defined(__ZTJT__Config__) */
