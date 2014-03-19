//
//  ZTServer.cpp
//  SocketOnBackground
//
//  Created by Perry on 14-2-22.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#include "ZTServer.h"
#include <arpa/inet.h>

ZTServer::ZTServer()
:m_ipAddrStr("")
,m_port(0)
{
    
}

ZTServer::ZTServer(const string &ipAddrStr, UINT16 port)
:m_ipAddrStr(ipAddrStr)
,m_port(port)
{
    
}


ZTServer::~ZTServer()
{
    
}


in_addr_t ZTServer::getNetAddress()
{
    return inet_addr(m_ipAddrStr.c_str());
}

const string& ZTServer::getIPAddressString()
{
    return m_ipAddrStr;
}

UINT16 ZTServer::getPort()
{
    return m_port;
}

in_port_t ZTServer::getNetPort()
{
    return htons(m_port);
}