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

VOID Line::SetColor(BYTE color)
{
    m_color = color;
}

BYTE Line::Color() const
{
    return m_color;
}

VOID Line::SetWidth(BYTE width)
{
    m_width = width;
}

BYTE Line::Width() const
{
    return m_width;
}