//
//  Vertex.cpp
//  ZTJT
//
//  Created by Perry on 14-5-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "Vertex.h"


namespace ZTNAMESPACE
{
    
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
    
    void Vertex::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 4;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        SHORT *pShort = (SHORT*)pByte;
        *(pShort) = m_Point.x;
        *(pShort+1) = m_Point.y;
    }
    
}