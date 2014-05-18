//
//  Lamp.cpp
//  ZTJT
//
//  Created by PerryMac on 3/20/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Lamp.h"

namespace ZTNAMESPACE
{
    
    Lamp::Lamp()
    {
        
    }
    
    Lamp::Lamp(POINT center, LampType type)
    :m_Center(center)
    ,m_Type(type)
    {
        
    }
    
    Lamp::~Lamp()
    {
        
    }
    
    SYNTHESIZE(Lamp, POINT, Center)
    SYNTHESIZE(Lamp, LampType, Type)
    
    
    ZTBOOL Lamp::CanInSameGroup(const Lamp *lamp1, const Lamp*lamp2)
    {
        UINT t1 = (UINT)lamp1->Type();
        UINT t2 = (UINT)lamp2->Type();
        
        if (t1 == t2)
        {
            return ZTTRUE;
        }
        else if (((t1<5 && t1>0) || t1>6) && ((t2<5 && t2>0) || t2>6))
        {  //都是普通类型的灯
            return ZTTRUE;
        }
        
        return ZTFALSE;
    }
    
    
    ZTBOOL Lamp::HitTest(POINT point)
    {
        return ZTFALSE;
    }
    
    void Lamp::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 6;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        SHORT *pShort = (SHORT*)pByte;
        *(pShort) = m_Center.x;
        *(pShort+1) = m_Center.y;
        *(pShort+2) = m_Type;
    }
    
}