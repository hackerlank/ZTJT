//
//  Intersections.h
//  ZTJT
//
//  Created by Perry on 14-6-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Intersections__
#define __ZTJT__Intersections__

#include "TypeDef.h"
#include "GraphicObject.h"
#include "NetNode.h"
#include <string>
using namespace std;

namespace ZTNAMESPACE
{
    class Intersections : public GraphicObject
    {
        Intersections();
        Intersections(POINT point);
        ~Intersections();
        
        enum IntersectionsState
        {
            IntersectionsStateStoped,
            IntersectionsStateYellowShine,
            IntersectionsStateAllRed,
            IntersectionsStateRunning
        };
        
        
        //固有属性
        PRIVATE_PROPERTY(string, Name);     //路口名
        PRIVATE_PROPERTY(INT, No);          //路口编号
        PRIVATE_PROPERTY(POINT, Position);  //路口位置
        
        //图形，方案，计划。临时从文件读取
        
        // 网络属性
        PRIVATE_PROPERTY(NetNode, Node);    //网络地址
        
        PRIVATE_PROPERTY(INT, RunMode);     //运行模式
        PRIVATE_PROPERTY(INT, OldRunMode);  //先前运行模式
        
        PRIVATE_PROPERTY(SHORT, Port);      //端口
        PRIVATE_PROPERTY(IntersectionsState, State);    //路口运行状态
        
        PRIVATE_PROPERTY(ZTBOOL, connected);    //是否正在连接状态
        
        
    };

}


#endif /* defined(__ZTJT__Intersections__) */
