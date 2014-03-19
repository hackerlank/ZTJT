//
//  ZTData.cpp
//  SocketOnBackground
//
//  Created by Perry on 14-2-16.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#include "ZTData.h"
#include "ZTThread.h"


ZTDataBase::ZTDataBase()
{
}

ZTDataBase::~ZTDataBase()
{
    ZTPacketList::iterator it = m_packets.begin();
    while (it != m_packets.end()) {
        delete *it;
        it++;
    }
}


//设置一个回调函数，当数据准备好后，将数据回馈过去
void ZTDataBase::setPreparedCallback(DataProparedFunc *callbackFunc){
    CMutex mutex;
    mutex.Lock();
    
    m_callbackfunc = callbackFunc;
    
    mutex.Unlock();
}


//添加一个packet
void ZTDataBase::addPacket(ZTPacketBase *packet)
{
    m_mutex.Lock();
    m_packets.push_back(packet);
    m_mutex.Unlock();
}

void ZTDataBase::clear()
{
    m_mutex.Lock();
    ZTPacketList::iterator it = m_packets.begin();
    while (it != m_packets.end()) {
        delete *it;
        it++;
    }
    
    m_packets.clear();
    
    m_mutex.Unlock();
}

void ZTDataBase::lock()
{
    m_mutex.Lock();
}

void ZTDataBase::unlock()
{
    m_mutex.Unlock();
}

