//
//  Crossing.h
//  ZTJT
//  路口
//  Created by Perry on 14-6-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Crossing__
#define __ZTJT__Crossing__

#include "TypeDef.h"
#include "GraphicObject.h"
#include "NetNode.h"
#include <string>
#include <vector>
using namespace std;


//extern const string kRunModeStopped;
//extern const string kRunModeRunMonitor;
//extern const string kRunModeCoordinateMonitor;
//extern const string kRunModeUrgentOperature;
//extern const string kRunModeSimulate;

namespace ZTNAMESPACE
{
    class Crossing : public GraphicObject
    {
    public:
        Crossing();
        Crossing(POINT point);
        ~Crossing();
        
        enum CrossingState
        {
            CrossingStateStopped,
            CrossingStateYellowShine,
            CrossingStateAllRed,
            CrossingStateRunning,
            CrossingStateMax
        };
        
        enum CrossingRunMode
        {
            CrossingRunModeStopped, // 停止运行状态
            CrossingRunModeRunMonitor,  // 监视运行状态
            CrossingRunModeCoordinateMonitor,  // 协调控制状态
            CrossingRunModeUrgentOperature,     // 紧急操作状态
            CrossingRunModeSimulate,            // 仿真状态
            CrossingRunModeMax
        };
        
        
        //固有属性
        PRIVATE_PROPERTY(string, Name);     //路口名
        PRIVATE_PROPERTY(INT, No);          //路口编号
        PRIVATE_PROPERTY(POINT, Position);  //路口位置
        
        //图形，方案，计划。临时从文件读取
        
        // 网络属性
        PRIVATE_PROPERTY(NetNode, Node);    //网络地址
        
        PRIVATE_PROPERTY(CrossingRunMode, RunMode);     //运行模式
        PRIVATE_PROPERTY(INT, OldRunMode);              //先前运行模式
        
        PRIVATE_PROPERTY(SHORT, Port);              //端口
        PRIVATE_PROPERTY(CrossingState, State);     //路口运行状态
        
        PRIVATE_PROPERTY(ZTBOOL, Connected);        //是否正在连接状态
        
        PRIVATE_PROPERTY(DEVICETIME, DeviceTime);   //设备时间
        
    public:
        // 重写父类方法
        virtual ZTBOOL HitTest(POINT point);
        virtual void GenerateBinary(BYTE *&pByte, INT &length);
        
        string RunModeString();
        
        // 根据运行模式枚举值获取描述
        static string RunModeDescription(CrossingRunMode runMode);
        // 获取所有的模式以及描述
        static vector< pair<Crossing::CrossingRunMode, string> > GetRunModes();
    };

}


#endif /* defined(__ZTJT__Intersections__) */
