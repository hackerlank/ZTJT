//
//  ZTSocket.h
//  SocketOnBackground
//
//  Created by Perry on 14-2-15.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#ifndef __SocketOnBackground__ZTSocket__
#define __SocketOnBackground__ZTSocket__

#include <iostream>
#include <string>
#include <vector>
#include "ZTObject.h"
#include "TypeDef.h"
#include "ZTPacket.h"
#include "ZTThread.h"
#include "ZTServer.h"



using namespace std;

class ZTSocket : public ZTObject {
public:
    ZTSocket();
    ZTSocket(string &ipaddress, UINT32 uPort);
    ~ZTSocket();
    
    ZTBOOL start();
    ZTBOOL stop();
    
    ZTBOOL send(const ZTPacketBase &packet);
private:
    void run();
    
private:
    ZTBOOL m_running;
    ZTServer m_server;
    
    int m_socketfd;
    vector<ZTPacketBase*> m_recvData;
    
    CThread<ZTSocket> *m_thread;
};

#endif /* defined(__SocketOnBackground__ZTSocket__) */
