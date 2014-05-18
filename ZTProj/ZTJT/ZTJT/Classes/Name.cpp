//
//  Name.cpp
//  ZTJT
//
//  Created by PerryMac on 3/19/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Name.h"


namespace ZTNAMESPACE
{
    
    Name::Name()
    :m_LefttopPt({0,0})
    ,m_NameStr(ZTNULL)
    {
        
    }
    
    Name::Name(POINT pt)
    :m_LefttopPt(pt)
    {
        
    }
    
    Name::~Name()
    {
        
    }
    
    SYNTHESIZE(Name, POINT, LefttopPt)
    SYNTHESIZE(Name, string, NameStr)
    
    
    ZTBOOL Name::HitTest(POINT point)
    {
        return ZTFALSE;
    }
    
    void Name::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 26;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        SHORT *pShort = (SHORT*)pByte;
        *(pShort) = m_LefttopPt.x;
        *(pShort+1) = m_LefttopPt.y;
        *(pShort+2) = m_NameStr.length();
        snprintf((char *)(pByte+6), 20, "%s", m_NameStr.c_str());
    }
    
}