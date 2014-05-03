//
//  Name.cpp
//  ZTJT
//
//  Created by PerryMac on 3/19/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Name.h"

Name::Name()
:m_LefttopPt({0,0})
,m_NameStr(ZTNULL)
{
    
}

Name::Name(POINT pt)
:m_LefttopPt(pt)
,m_NameStr(ZTNULL)
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

void Name::generateBinary(BYTE *&pByte, INT &length)
{
    
}