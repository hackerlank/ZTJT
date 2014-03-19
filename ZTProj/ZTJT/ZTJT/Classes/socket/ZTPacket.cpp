//
//  ZTData.cpp
//  SocketOnBackground
//
//  Created by Perry on 14-2-15.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#include "ZTPacket.h"

/*******ZTDataBase*****/
ZTPacketBase::ZTPacketBase()
:m_bufsize(0)
{
    
}

ZTPacketBase::ZTPacketBase(const BYTE *buf, UINT32 len)
:m_bufsize(len)
{
    memcpy(m_buf, buf, len);
}

ZTPacketBase::~ZTPacketBase()
{
    
}


const BYTE* ZTPacketBase::GetBuffer() const
{
    return m_buf;
}

UINT32 ZTPacketBase::GetBufferSize() const
{
    return m_bufsize;
}




/********ZTVideoBase********/
ZTVideoPacket::ZTVideoPacket()
:ZTPacketBase()
{
    
}

ZTVideoPacket::ZTVideoPacket(const BYTE *buf, UINT32 len)
:ZTPacketBase(buf, len)
{
    
}

ZTVideoPacket::~ZTVideoPacket()
{
    
}

void ZTVideoPacket::generatePacket()
{
    memset(m_buf, 0x00, SOCKET_LEN_MAX);
    m_buf[0] = 0x88;
    m_buf[1] = 0x88;
    m_buf[2] = 0x02;
    m_buf[3] = 0x04;
    m_buf[4] = 0x00;
    //m_buf[5] = 0x02;
    
    m_bufsize = 520;
}


