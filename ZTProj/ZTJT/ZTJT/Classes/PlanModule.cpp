//
//  PlanManager.cpp
//  ZTJT
//
//  Created by Perry on 14-5-17.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "PlanModule.h"

namespace ZTNAMESPACE
{
    
    PlanModule::PlanModule()
    {
        
    }
    
    PlanModule::~PlanModule()
    {
        list<DayPlan*>::iterator it = m_DayPlans.begin();
        while (it != m_DayPlans.end())
        {
            delete *it;
            it++;
        }
    }
    
    
    WeekPlan &PlanModule::WeekPlan()
    {
        return m_WeekPlan;
    }
    
    
    DayPlan *PlanModule::InsertDayPlanAtIndex(INT index)
    {
        if (m_DayPlans.size() > 12) {
            return ZTNULL;
        }
        
        DayPlan *dayPlan = new DayPlan;
        
        if (index>=0 && index< m_DayPlans.size())
        {
            list<DayPlan*>::iterator pos = m_DayPlans.begin();
            std::advance(pos, index);
            m_DayPlans.insert(pos, dayPlan);
        }
        else
        {
            m_DayPlans.push_back(dayPlan);
        }
        
        return dayPlan;
    }
    
    void PlanModule::DeleteDayPlan(DayPlan *dayPlan)
    {
        m_DayPlans.remove(dayPlan);
    }
    
    DayPlan *PlanModule::DayPlanAtIndex(INT index)
    {
        list<DayPlan*>::iterator pos = m_DayPlans.begin();
        std::advance(pos, index);
        
        return *pos;
    }
    
    void PlanModule::GenerateDayPlansBinary(BYTE *&pByte, INT &length)
    {
        length = 0x600;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        INT offset = 0;
        list<DayPlan *>::const_iterator it = m_DayPlans.begin();
        while (it != m_DayPlans.end())
        {
            BYTE *dayPlanBytes = ZTNULL;
            INT iDayPlanLen = 0;
            
            (*it)->GenerateBinary(dayPlanBytes, iDayPlanLen);
            memcpy(pByte + offset, dayPlanBytes, iDayPlanLen);
            
            it++;
            offset += iDayPlanLen;
        }
    }
    
    
}