//
//  RunParam.cpp
//  ZTJT
//
//  Created by Perry on 14-5-11.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "DevConfig.h"


namespace ZTNAMESPACE
{
    
    DevConfig::DevConfig()
    {
        Reset();
    }
    
    DevConfig::~DevConfig()
    {
        
    }
    
    
    SYNTHESIZE(DevConfig, INT, Manual)
    SYNTHESIZE(DevConfig, INT, RedStart)
    SYNTHESIZE(DevConfig, INT, GreenConflict)
    SYNTHESIZE(DevConfig, INT, Network)
    SYNTHESIZE(DevConfig, INT, NetControl)
    
    
    void DevConfig::SetLampModuleExist(INT index, ZTBOOL exist)
    {
        if (index >= 0 && index < 8)
        {
            m_LampModule[index] = exist;
        }
    }
    
    void DevConfig::SetVduModuleExist(INT index, ZTBOOL exist)
    {
        if (index >= 0 && index < 2)
        {
            m_VduModule[index] = exist;
        }
    }
    
    void DevConfig::SetGPSModuleExist(ZTBOOL exist)
    {
        m_GpsModule = exist;
    }
    
    void DevConfig::Reset()
    {
        m_Manual = 0;
        m_RedStart = 0;
        m_GreenConflict = 0;
        m_Network = 0;
        m_NetControl = 0;
        
        m_LampModule[0] = ZTTRUE;
        m_LampModule[1] = ZTTRUE;
        m_LampModule[2] = ZTTRUE;
        m_LampModule[3] = ZTTRUE;
        m_LampModule[4] = ZTFALSE;
        m_LampModule[5] = ZTFALSE;
        m_LampModule[6] = ZTFALSE;
        m_LampModule[7] = ZTFALSE;
        
        m_VduModule[0] = ZTFALSE;
        m_VduModule[1] = ZTFALSE;
        
        m_GpsModule = ZTFALSE;
    }
    
    
    void DevConfig::GenerateBinary(BYTE *&pByte, INT &length)
    {
        length = 8;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        *pByte = 0xA5;
        
        //灯控模块
        if (m_LampModule[0])
        {
            *(pByte+1) |= 0x03;
        }
        if (m_LampModule[1])
        {
            *(pByte+1) |= 0x0C;
        }
        if (m_LampModule[2])
        {
            *(pByte+1) |= 0x30;
        }
        if (m_LampModule[3])
        {
            *(pByte+1) |= 0xC0;
        }
        
        if (m_LampModule[4])
        {
            *(pByte+2) |= 0x03;
        }
        if (m_LampModule[5])
        {
            *(pByte+2) |= 0x0C;
        }
        if (m_LampModule[6])
        {
            *(pByte+2) |= 0x30;
        }
        if (m_LampModule[7])
        {
            *(pByte+2) |= 0xC0;
        }
        
        //
        if (1 == m_Manual)
        {
            *(pByte+3) |= 0x01;
        }
        if (1 == m_RedStart)
        {
            *(pByte+3) |= 0x02;
        }
        if (1 == m_GreenConflict)
        {
            *(pByte+3) |= 0x04;
        }
        if (1 == m_Network)
        {
            *(pByte+3) |= 0x08;
        }
        if (1 == m_NetControl)
        {
            *(pByte+3) |= 0x10;
        }
        
        if (m_VduModule[0])
        {
            *(pByte+4) |= 0x01;
        }
        if (m_VduModule[1])
        {
            *(pByte+4) |= 0x02;
        }
        if (m_GpsModule)
        {
            *(pByte+4) |= 0x04;
        }
        
        //验证码
        for (INT i=0; i<7; i++)
        {
            *(pByte+7) += *(pByte+i);
        }
        
    }
}