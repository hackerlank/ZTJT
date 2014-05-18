//
//  Scheme.cpp
//  ZTJT
//
//  Created by Perry on 14-5-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//


#include "Scheme.h"
#include <iterator>


namespace ZTNAMESPACE
{
    
    Scheme::Scheme()
    {
        
    }
    
    Scheme::~Scheme()
    {
        list<Status*>::iterator it = m_statuses.begin();
        while (it != m_statuses.end())
        {
            delete *it;
            it++;
        }
    }
    
    SYNTHESIZE(Scheme, INT, Type)
    SYNTHESIZE(Scheme, INT, Offset)
    
    
    Status* Scheme::InsertStatusAtIndex(INT index)
    {
        Status *status = new Status;
        
        if (index>=0 && index< m_statuses.size())
        {
            list<Status*>::iterator pos = m_statuses.begin();
            std::advance(pos, index);
            m_statuses.insert(pos, status);
        }
        else
        {
            m_statuses.push_back(status);
        }
        
        return status;
        
    }
    
    
    void Scheme::DeleteStatus(Status *status)
    {
        m_statuses.remove(status);
    }
    
    
    Status* Scheme::StatusAtIndex(INT index)
    {
        list<Status*>::iterator pos = m_statuses.begin();
        std::advance(pos, index);
        
        return *pos;
    }
    
    void Scheme::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 0x300;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        BYTE *pTempByte = pByte;
        *pTempByte      = 0xF5;
        *(pTempByte+1)  = m_Type;
        *(pTempByte+2)  = m_Offset;
        *(pTempByte+3)  = m_statuses.size();
        
        SHORT *pShort = (SHORT *)(pTempByte+9);
        
        SHORT standardTime = 0;
        SHORT minTime = 0;
        SHORT maxTime = 0;
        calcCycle(standardTime, minTime, maxTime);
        
        *(pShort)  = standardTime;
        *(pShort+1) = minTime;
        *(pShort+2) = maxTime;
        
        for (INT i = 0; i < 15; i++)
        {
            *(pTempByte + 15) += *(pTempByte + i);
        }
        
        INT offset = 0x10;       //记录当前状态数据的偏移
        list<Status*>::const_iterator it = m_statuses.begin();
        while (it != m_statuses.end())
        {
            BYTE *pStatusBytes = ZTNULL;
            INT iStatusLen = 0;
            
            (*it)->GenerateBinary(pStatusBytes, iStatusLen);
            memcpy(pTempByte+offset, pStatusBytes, iStatusLen);
            
            offset += iStatusLen;
            it++;
        }
    }
    
    
    void Scheme::calcCycle(SHORT &standard, SHORT &min, SHORT &max)
    {
        list<Status*>::const_iterator it = m_statuses.begin();
        
        while (it != m_statuses.end())
        {
            
            standard += (*it)->Time();
            min += (*it)->MinTime();
            max += (*it)->MaxTime();
            
            it++;
        }
    }
}