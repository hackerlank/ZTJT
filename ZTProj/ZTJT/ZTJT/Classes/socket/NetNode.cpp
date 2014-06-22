//
//  ZTServer.cpp
//  SocketOnBackground
//
//  Created by Perry on 14-2-22.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#include "NetNode.h"
#include <arpa/inet.h>

NetNode::NetNode()
:m_ipAddrStr("")
,m_port(0)
{
    
}

NetNode::NetNode(const string &ipAddrStr, UINT16 port)
:m_ipAddrStr(ipAddrStr)
,m_port(port)
{
    
}


NetNode::~NetNode()
{
    
}


in_addr_t NetNode::getNetAddress()
{
    return inet_addr(m_ipAddrStr.c_str());
}

const string& NetNode::getIPAddressString()
{
    return m_ipAddrStr;
}

UINT16 NetNode::getPort()
{
    return m_port;
}

in_port_t NetNode::getNetPort()
{
    return htons(m_port);
}



NetServer::NetServer()
{
    
}

NetServer::NetServer(const string &ipAddrStr, UINT16 port)
{
    NetNode(ipAddrStr, port);
}

NetServer::~NetServer()
{
    
}