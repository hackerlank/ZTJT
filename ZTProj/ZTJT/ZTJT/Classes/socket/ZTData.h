//
//  ZTData.h
//  SocketOnBackground
//
//  Created by Perry on 14-2-16.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#ifndef __SocketOnBackground__ZTData__
#define __SocketOnBackground__ZTData__

#include <iostream>
#include "ZTObject.h"
#include "ZTPacket.h"
#include <list>
#include "ZTThread.h"

typedef std::list<ZTPacketBase*> ZTPacketList;

class ZTDataBase;
typedef void (*DataProparedFunc)(const ZTDataBase &data);

class ZTDataBase : public ZTObject
{
public:
    ZTDataBase();
    ~ZTDataBase();
    //设置一个回调函数，当数据准备好后，将数据回馈过去
    void setPreparedCallback(DataProparedFunc *callbackFunc);
    
    //添加一个packet
    void addPacket(ZTPacketBase *packet);
    
    //清除所有的包
    void clear();
    
    
    //lock
    void lock();
    void unlock();
    
private:
    DataProparedFunc *m_callbackfunc;
    ZTPacketList m_packets;
    
    CMutex m_mutex;
};

#endif /* defined(__SocketOnBackground__ZTData__) */
