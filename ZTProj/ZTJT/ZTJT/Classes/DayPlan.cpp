//
//  DayPlan.cpp
//  ZTJT
//
//  Created by Perry on 14-5-11.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "DayPlan.h"

namespace ZTNAMESPACE
{
    
    DayPlan::DayPlan()
    {
        
    }
    
    DayPlan::~DayPlan()
    {
        list<Period*>::iterator it = m_Periods.begin();
        while (it != m_Periods.end())
        {
            delete *it;
            it++;
        }
    }
    
    Period *DayPlan::InsertPeriodAtIndex(INT index)
    {
        if (m_Periods.size() > 20) {
            return ZTNULL;
        }
        
        Period *period = new Period;
        
        if (index>=0 && index< m_Periods.size())
        {
            list<Period*>::iterator pos = m_Periods.begin();
            std::advance(pos, index);
            m_Periods.insert(pos, period);
        }
        else
        {
            m_Periods.push_back(period);
        }
        
        return period;
        
    }
    
    
    void DayPlan::DeletePeriod(Period *period)
    {
        m_Periods.remove(period);
    }
    
    Period *DayPlan::PeriodAtIndex(INT index)
    {
        list<Period*>::iterator pos = m_Periods.begin();
        std::advance(pos, index);
        
        return *pos;
    }
    
    void DayPlan::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 0x80;
        pByte = new BYTE(length);
        bzero(pByte, length);
        
        INT offset = 0;
        list<Period *>::const_iterator it = m_Periods.begin();
        while (it != m_Periods.end()) {
            BYTE *pPeriodBytes = ZTNULL;
            INT iPeriodLen = 0;
            
            (*it)->GenerateBinary(pPeriodBytes, iPeriodLen);
            memcpy(pByte+offset, pPeriodBytes, iPeriodLen);
            
            offset += iPeriodLen;
            it++;
        }
    }
    
}