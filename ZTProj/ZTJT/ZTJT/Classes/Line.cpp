//
//  Line.cpp
//  ZTJT
//
//  Created by PerryMac on 3/18/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "Line.h"

Line::Line()
:m_ptStart({0,0})
,m_ptEnd({0,0})
{
    
}

Line::Line(POINT ptStart, POINT ptEnd)
:m_ptStart(ptStart)
,m_ptEnd(ptEnd)
{
    
}


Line::~Line()
{
    
}


VOID Line::SetStart(POINT start)
{
    m_ptStart = start;
}

POINT Line::Start() const
{
    return m_ptStart;
}

VOID Line::SetEnd(POINT end)
{
    m_ptEnd = end;
}

POINT Line::End() const
{
    return m_ptEnd;
}

VOID Line::SetColor(LineColor color)
{
    m_color = color;
}

LineColor Line::Color() const
{
    return Line::m_color;
}

VOID Line::SetWidth(LineWidth width)
{
    m_width = width;
}

LineWidth Line::Width() const
{
    return m_width;
}


ZTBOOL Line::HitTest(POINT point)
{
    return ZTFALSE;
}

void Line::generateBinary(BYTE *&pByte, INT &length)
{
    pByte = new BYTE[10];
    bzero(pByte, 10);
    length = 10;
    SHORT *pShort = (SHORT*)pByte;
    *(pShort) = m_ptStart.x;
    *(pShort+1) = m_ptStart.y;
    *(pShort+2) = m_ptEnd.x;
    *(pShort+3) = m_ptEnd.y;
    //*(pShort+4) = m_color<<8|m_width;
    *(pShort+4) = MAKESHORT(m_width, m_color);
}