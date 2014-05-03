//
//  Vertex.cpp
//  ZTJT
//
//  Created by Perry on 14-5-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "Vertex.h"

Vertex::Vertex()
{
    
}

Vertex::Vertex(POINT pt)
:m_Point(pt)
{
    
}

Vertex::~Vertex()
{
    
}

SYNTHESIZE(Vertex, POINT, Point)


ZTBOOL Vertex::HitTest(POINT point)
{
    return ZTFALSE;
}

void Vertex::generateBinary(BYTE *&pByte, INT &length)
{
    pByte = new BYTE[4];
    bzero(pByte, 4);
    length = 4;
    SHORT *pShort = (SHORT*)pByte;
    *(pShort) = m_Point.x;
    *(pShort+1) = m_Point.y;
}