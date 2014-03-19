//
//  ZTData.h
//  SocketOnBackground
//
//  Created by Perry on 14-2-15.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#ifndef __SocketOnBackground__ZTPacket__
#define __SocketOnBackground__ZTPacket__

#include <iostream>
#include <vector>
#include "ZTObject.h"
#include "TypeDef.h"

class ZTPacketBase : public ZTObject
{
protected:
    UINT32 m_bufsize;
    BYTE m_buf[SOCKET_LEN_MAX];   //字节数组
    
    
public:
    ZTPacketBase();
    /*************************************************
     no: UDP报文的序号
     buf: 报文有效数据的头部
     len: 报文有效数据的长度
     *************************************************/
    ZTPacketBase(const BYTE *buf, UINT32 len);
    ~ZTPacketBase();
    
    const BYTE *GetBuffer() const;
    UINT32 GetBufferSize() const;
    
    //virtual void create();   //创建一个包
};


class ZTVideoPacket : public ZTPacketBase
{
private:
    
public:
    ZTVideoPacket();
    ZTVideoPacket(const BYTE *buf, UINT32 len);
    ~ZTVideoPacket();
    
    void generatePacket();
};



#endif /* defined(__SocketOnBackground__ZTData__) */
