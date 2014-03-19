//
//  ZTSocket.cpp
//  SocketOnBackground
//
//  Created by Perry on 14-2-15.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#include "ZTSocket.h"
#include "ZTThread.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

using namespace std;

ZTSocket::ZTSocket()
:m_running(ZTFALSE)
,m_socketfd(-1)
{
    
}

ZTSocket::ZTSocket(std::string &ipaddress, UINT32 uPort)
:m_running(ZTFALSE)
,m_server(ZTServer(ipaddress, uPort))
,m_socketfd(-1)
{
    //
}


ZTSocket::~ZTSocket()
{
    m_running = ZTFALSE;
    close(m_socketfd);
    
    delete m_thread;
}

ZTBOOL ZTSocket::start()
{
    m_thread = CreateThread(this, &ZTSocket::run);
    if (ZTNULL != m_thread) {
        m_thread->Start();
        return ZTTRUE;
    }
    
    return ZTFALSE;
}

void ZTSocket::run()
{
    struct sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    
    socklen_t sin_len;
 
    m_running = ZTTRUE;
    cout<<"+++thread is running+++"<<endl;
    
    while (1) {
        if (ZTFALSE == m_running)
        {
            return;
        }
        
        BYTE message[SOCKET_LEN_MAX];  //15k buffer
        cout<<"+++receiving data+++"<<endl;
        ssize_t rt = recvfrom(m_socketfd, message, SOCKET_LEN_MAX, 0, (struct sockaddr *)&sin, &sin_len);
        if (0 < rt) {
            //received data
            cout<<"+++received data+++"<<endl;
        }else {
            cout << "***receive data failed***" <<endl;
            perror("error msg: ");
        }
    }
}


ZTBOOL ZTSocket::send(const ZTPacketBase &packet)
{
    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_len = sizeof(server);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = m_server.getNetAddress();
    server.sin_port = m_server.getNetPort();
    
    if (-1 == m_socketfd) {
        m_socketfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (0 > m_socketfd) {
            cout << "***create socket failed***"<<endl;
            return ZTFALSE;
        }
        
        if (!m_running) {
            start();
        }
    }
    
    ssize_t rt = sendto(m_socketfd, packet.GetBuffer(), packet.GetBufferSize(), 0, (struct sockaddr *)(&server), sizeof(struct sockaddr_in));
    if (0 > rt) {
        cout << "***send packet failed***"<<endl;
        return ZTFALSE;
    }
    
    cout<<"+++send data success+++"<<endl;
    
    return ZTTRUE;
}

ZTBOOL ZTSocket::stop()
{
    //m_running = ZTFALSE;
    m_thread->Stop();
    cout<<"+++thread stopped+++"<<endl;
    delete m_thread;
    close(m_socketfd);
    m_socketfd = -1;
    m_running = ZTFALSE;
    return  ZTTRUE;
}