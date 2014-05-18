//
//  Scheme.h
//  ZTJT
//
//  Created by Perry on 14-5-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Scheme__
#define __ZTJT__Scheme__

#include "BinaryObj.h"
#include "Status.h"
#include <list>
using namespace std;

namespace ZTNAMESPACE
{
    
    // 方案
    class Scheme : public BinaryObj
    {
        CONSTRUCTOR_DECLARE(Scheme);
        
        PRIVATE_PROPERTY(INT, Type)
        PRIVATE_PROPERTY(INT, Offset)
        
    private:
        list<Status*> m_statuses;
        
    public:
        //在指定位置插入一个状态
        //如果没有状态，则添加一个默认的状态
        //如果没有任何状态情况下添加，则将index设置成0
        Status *InsertStatusAtIndex(INT index);
        //删除一个状态
        void DeleteStatus(Status *status);
        
        //获取一个状态
        Status *StatusAtIndex(INT index);
        
        
        void GenerateBinary(BYTE *&pByte, INT &length);
        
    private:
        //计算正常周期，最小周期，最大周期
        void calcCycle(SHORT &standard, SHORT &min, SHORT &max);
    };
    
}

#endif /* defined(__ZTJT__Scheme__) */
