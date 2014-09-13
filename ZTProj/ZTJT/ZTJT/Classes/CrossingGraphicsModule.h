//
//  CrossingGraphicsModule.h
//  ZTJT
//  路口图形
//  Created by PerryMac on 3/19/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__CrossingGraphicsModule__
#define __ZTJT__CrossingGraphicsModule__

#include "Line.h"
#include "LampGroup.h"
#include "Name.h"
#include "Lamp.h"
#include "Vertex.h"
#include <list>
using namespace std;

namespace ZTNAMESPACE
{
    
    class CrossingGraphicsModule : public ZTObject
    {
        list<Vertex*> m_Vertexes;           //路口形状顶点图
        list<Line*> m_Lines;                  //路口线条
        list<LampGroup*> m_LampGroups;        //路灯
        list<Name*> m_Names;                  //注释
        
    public:
        CONSTRUCTOR_DECLARE(CrossingGraphicsModule)
        Vertex *AddVertex(POINT point);
        void DelVertex(Vertex *vertex);
        
        Line* AddLine(POINT start, POINT end);
        void  DelLine(Line *aline);
        
        Lamp* AddLamp(POINT center, LampType type);
        void  DelLamp(Lamp *alamp);   //不会delete alamp,需要额外手动清除
        ZTBOOL  SetLampLddout(Lamp *alamp, BYTE lddout);
        LampGroup *findLamp(Lamp *alamp)const;
        
        Name* AddName(POINT point);    //每个路名最多20个字节
        void  DelName(Name *aName);
        
    private:
        void generateVertexBinary(BYTE *&pByte, INT &length);
        void generateLinesBinary(BYTE *&pByte, INT &length);
        void generateLampsBinary(BYTE *&pByte, INT &length);
        void generateNamesBinary(BYTE *&pByte, INT &length);
        
    private:
        LampGroup *GetDefaultGroup();   //获取lddout为0的分组
        LampGroup *GetGroup(BYTE lddout);   //获取lddout的分组，如果没有就创建一个
    };
    
}

#endif /* defined(__ZTJT__InterGraphicsModule__) */
