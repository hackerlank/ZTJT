//
//  GraphicsManager.h
//  ZTJT
//
//  Created by PerryMac on 3/19/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__GraphicsManager__
#define __ZTJT__GraphicsManager__

#include "Line.h"
#include "LampGroup.h"
#include "Name.h"
#include "Lamp.h"
#include <list>
using namespace std;

class GraphicsManager : public ZTObject {
    PRIVATE_PROPERTY(list<Line*>, Lines)    //路口线条
    PRIVATE_PROPERTY(list<LampGroup*>, LampGroups)    //路灯
    PRIVATE_PROPERTY(list<Name*>, Names)    //注释
    
    
public:
    CONSTRUCTOR_DECLARE(GraphicsManager)
    
    Line* AddLine(POINT start, POINT end);
    void  DelLine(Line *aline);
    
    Lamp* AddLamp(POINT center, LampType type);
    void  DelLamp(Lamp *alamp);
    
    Name* AddName(POINT point);
    void  DelName(Name *aName);
    
    
private:
    LampGroup *GetDefaultGroup();   //获取lddout为0的分组
    LampGroup * GetGroup(BYTE lddout);   //获取lddout的分组，如果没有就创建一个
};

#endif /* defined(__ZTJT__GraphicsManager__) */
