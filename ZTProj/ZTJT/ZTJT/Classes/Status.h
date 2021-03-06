//
//  Status.h
//  ZTJT
//  方案中的状态
//  Created by Perry on 14-5-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Status__
#define __ZTJT__Status__

#include "BinaryObj.h"
#include <map>
using namespace std;

namespace ZTNAMESPACE
{
    // 方案中的状态
    class Status : public BinaryObj
    {
        CONSTRUCTOR_DECLARE(Status);
        
        PRIVATE_PROPERTY(INT, Time)
        PRIVATE_PROPERTY(INT, MaxTime)
        PRIVATE_PROPERTY(INT, MinTime)
        PRIVATE_PROPERTY(INT, VduPhase)
        
        map<BYTE, BYTE> m_LddoutStatus;
        
    public:
        void SetLddoutStatus(BYTE lddout, BYTE status);
        
        void GenerateBinary(BYTE *&pByte, INT &length);
    };
    
}

#endif /* defined(__ZTJT__Status__) */
