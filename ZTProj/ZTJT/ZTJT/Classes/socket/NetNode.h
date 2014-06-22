//
//  ZTServer.h
//  SocketOnBackground
//
//  Created by Perry on 14-2-22.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#ifndef __SocketOnBackground__ZTServer__
#define __SocketOnBackground__ZTServer__

#include <iostream>
#include "ZTObject.h"
#include "TypeDef.h"
#include <string>

using namespace std;

class NetNode : public ZTObject
{
public:
    NetNode();
    NetNode(const string &ipAddrStr, UINT16 port);
    ~NetNode();
    
    in_addr_t getNetAddress();
    const string &getIPAddressString();
    
    in_port_t getNetPort();
    UINT16 getPort();
private:
    string m_ipAddrStr;
    UINT16 m_port;
};


class NetServer : public NetNode
{
public:
    NetServer();
    NetServer(const string &ipAddrStr, UINT16 port);
    ~NetServer();
};

#endif /* defined(__SocketOnBackground__ZTServer__) */
