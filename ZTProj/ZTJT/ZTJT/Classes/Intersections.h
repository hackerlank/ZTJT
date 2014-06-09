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
#include <string>
using namespace std;

namespace ZTNAMESPACE
{
    class Intersections : public GraphicObject
    {
        Intersections();
        Intersections(POINT point);
        ~Intersections();
        
        enum
        {
            IntersectionsStateStoped,
            IntersectionsStateYellowShine,
            IntersectionsStateAllRed,
            IntersectionsStateRunning
        }IntersectionsState;
        
        
        PRIVATE_PROPERTY(string, Name);     //路口名
        PRIVATE_PROPERTY(INT, No);          //路口编号
        PRIVATE_PROPERTY(INT, RunMode);     //运行模式
        PRIVATE_PROPERTY(INT, OldRunMode);  //先前运行模式
        
        PRIVATE_PROPERTY(SHORT, Port);      //端口
        PRIVATE_PROPERTY(IntersectionsState, State);    //路口运行状态
        
    };

}


#endif /* defined(__ZTJT__Intersections__) */
