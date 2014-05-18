//
//  Status.cpp
//  ZTJT
//
//  Created by Perry on 14-5-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "Status.h"


namespace ZTNAMESPACE
{
    
    Status::Status()
    {
        
    }
    
    Status::~Status()
    {
        
    }
    
    
    SYNTHESIZE(Status, INT, Time)
    SYNTHESIZE(Status, INT, MaxTime)
    SYNTHESIZE(Status, INT, MinTime)
    SYNTHESIZE(Status, INT, VduPhase)
    
    
    void Status::SetLddoutStatus(BYTE lddout, BYTE status)
    {
        m_LddoutStatus[lddout] = status;
    }
    
    void Status::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 16;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        BYTE *pTempByte = pByte;
        *pTempByte      = 0xA5;
        *(pTempByte+1)  = m_Time;
        *(pTempByte+2)  = m_MaxTime;
        *(pTempByte+3)  = m_MinTime;
        *(pTempByte+4)  = m_VduPhase;
        
        map<BYTE, BYTE>::iterator it = m_LddoutStatus.begin();
        while (it != m_LddoutStatus.end())
        {
            BYTE lddout = it->first;
            INT offset = (lddout-1)/2;
            INT remainder = (lddout-1)%2;
            
            if (0 == remainder)    //放到低位
            {
                *(pTempByte+6+offset) |= it->second;
            }
            else                   //放到高位
            {
                *(pTempByte+6+offset) |= (it->second<<4);
            }
            
            it++;
        }
        
        for (INT i = 0; i < 15; i++)
        {
            *(pTempByte + 15) += *(pTempByte + i);
        }
    }
}