//
//  Plan.cpp
//  ZTJT
//
//  Created by Perry on 14-5-11.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "WeekPlan.h"

namespace ZTNAMESPACE
{
    
    
    WeekPlan::WeekPlan()
    {
        for (INT i=0; i<7; i++)
        {
            m_WeekPlan[i] = 0;
        }
    }
    
    WeekPlan::~WeekPlan()
    {
        
    }
    
    
    void WeekPlan::SetDayPlan(INT dayIndex, INT planIndex)
    {
        if ((dayIndex >= 0 && dayIndex < 7) && (planIndex >= 0 && planIndex < 12))
        {
            m_WeekPlan[dayIndex] = planIndex;
        }
    }
    
    void WeekPlan::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 8;
        pByte = new BYTE(length);
        bzero(pByte, length);
        
        *pByte = 0xA5;
        
        for (INT i=0; i<7; i++)
        {
            *(pByte+1+i) = m_WeekPlan[i];
        }
    }
    
    
}