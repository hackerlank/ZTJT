//
//  Period.cpp
//  ZTJT
//
//  Created by Perry on 14-5-11.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "Period.h"

namespace ZTNAMESPACE
{
    Period::Period()
    {
        m_Hour = 0;
        m_Minute = 0;
        m_Second = 0;
    }
    
    Period::~Period()
    {
        
    }
    
    void Period::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 6;
        pByte = new BYTE(length);
        bzero(pByte, length);
        
        *pByte = 0xA5;
        *(pByte+1) = m_Hour;
        *(pByte+2) = m_Minute;
        *(pByte+3) = m_Second;
        *(pByte+4) = m_SchemeIndex;
        
        for (INT i=0; i<5; i++) {
            *(pByte+5) += *(pByte+i);
        }
    }
    
}