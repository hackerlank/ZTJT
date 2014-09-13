//
//  Crossing.cpp
//  ZTJT
//
//  Created by Perry on 14-6-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "Crossing.h"

const string kRunModeStopped="停止运行状态";
const string kRunModeRunMonitor="监视运行状态";
const string kRunModeCoordinateMonitor="协调控制状态";
const string kRunModeUrgentOperature="紧急操作状态";
const string kRunModeSimulate="仿真测试状态";

namespace ZTNAMESPACE
{
    Crossing::Crossing()
    :m_Name("未知")
    ,m_No(0)
    ,m_Position({0, 0})
    {
    }
    Crossing::Crossing(POINT point)
    :m_Name("未知")
    ,m_No(0)
    ,m_Position({0, 0})
    {
        
    }
    
    Crossing::~Crossing()
    {
        
    }
    
    //固有属性
    SYNTHESIZE(Crossing, string, Name);     //路口名
    SYNTHESIZE(Crossing, INT, No);          //路口编号
    SYNTHESIZE(Crossing, POINT, Position);  //路口位置
    
    SYNTHESIZE(Crossing, NetNode, Node);    //网络地址
    
    SYNTHESIZE(Crossing, Crossing::CrossingRunMode, RunMode);     //运行模式
    SYNTHESIZE(Crossing, INT, OldRunMode);  //先前运行模式
    
    SYNTHESIZE(Crossing, SHORT, Port);      //端口
    SYNTHESIZE(Crossing, Crossing::CrossingState, State);    //路口运行状态
    
    SYNTHESIZE(Crossing, ZTBOOL, connected);    //是否正在连接状态
    
    ZTBOOL Crossing::HitTest(POINT point)
    {
        return ZTFALSE;
    }
    
    void Crossing::GenerateBinary(BYTE *&pByte, INT &length)
    {
        
    }
    
    string Crossing::RunModeString()
    {
        return Crossing::RunModeDescription(m_RunMode);
    }
    
    string Crossing::RunModeDescription(CrossingRunMode runMode)
    {
        switch (runMode)
        {
            case CrossingRunModeStopped:
                return kRunModeStopped;
            case CrossingRunModeRunMonitor:
                return kRunModeRunMonitor;
            case CrossingRunModeCoordinateMonitor:
                return kRunModeCoordinateMonitor;
            case CrossingRunModeUrgentOperature:
                return kRunModeUrgentOperature;
            case CrossingRunModeSimulate:
                return kRunModeSimulate;
            case CrossingRunModeMax:
                return NULL;
            default:
                break;
        }
    }
    
    vector< pair<Crossing::CrossingRunMode, string> > Crossing::GetRunModes()
    {
        vector< pair<Crossing::CrossingRunMode, string> > runmodes;
        runmodes.push_back(pair<Crossing::CrossingRunMode, string>(Crossing::CrossingRunModeStopped, kRunModeStopped));
        runmodes.push_back(pair<Crossing::CrossingRunMode, string>(Crossing::CrossingRunModeRunMonitor, kRunModeRunMonitor));
        runmodes.push_back(pair<Crossing::CrossingRunMode, string>(Crossing::CrossingRunModeCoordinateMonitor, kRunModeCoordinateMonitor));
        runmodes.push_back(pair<Crossing::CrossingRunMode, string>(Crossing::CrossingRunModeUrgentOperature, kRunModeUrgentOperature));
        runmodes.push_back(pair<Crossing::CrossingRunMode, string>(Crossing::CrossingRunModeSimulate, kRunModeSimulate));
        
        return runmodes;
    }
    
}