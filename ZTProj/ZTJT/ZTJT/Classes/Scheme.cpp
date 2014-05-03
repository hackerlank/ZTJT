//
//  Scheme.cpp
//  ZTJT
//
//  Created by Perry on 14-5-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//


#include "Scheme.h"
#include <iterator>


Scheme::Scheme()
{
    
}

Scheme::~Scheme()
{
    list<Status*>::iterator it = m_statuses.begin();
    while (it != m_statuses.end()) {
        delete *it;
        it++;
    }
}

SYNTHESIZE(Scheme, INT, Type)
SYNTHESIZE(Scheme, INT, Offset)


Status* Scheme::InsertStatusAtIndex(INT index)
{
    Status *status = new Status;
    
    if (index>=0 && index< m_statuses.size())
    {
        list<Status*>::iterator pos = m_statuses.begin();
        std::advance(pos, index);
        m_statuses.insert(pos, status);
    }
    else
    {
        m_statuses.push_back(status);
    }
    
    return status;

}


void Scheme::DeleteStatus(Status *status)
{
    m_statuses.remove(status);
}


Status* Scheme::StatusAtIndex(INT index)
{
    list<Status*>::iterator pos = m_statuses.begin();
    std::advance(pos, index);
    
    return *pos;
}

void Scheme::generateBinary(BYTE *&pByte, INT &length)
{
    
}