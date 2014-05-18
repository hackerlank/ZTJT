//
//  DayPlan.h
//  ZTJT
//
//  Created by Perry on 14-5-11.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__DayPlan__
#define __ZTJT__DayPlan__

#include "TypeDef.h"
#include "BinaryObj.h"
#include "Period.h"
#include <list>
using namespace std;

namespace ZTNAMESPACE
{
    
    class DayPlan : public BinaryObj
    {
        CONSTRUCTOR_DECLARE(DayPlan)
        
        list<Period *> m_Periods;
        
    public:
        //在指定位置插入一个状态
        //如果没有状态，则添加一个默认的状态
        //如果没有任何状态情况下添加，则将index设置成0
        //最多20个时段
        Period *InsertPeriodAtIndex(INT index);
        //删除一个状态
        void DeletePeriod(Period *period);
        
        //获取一个状态
        Period *PeriodAtIndex(INT index);
        
        void GenerateBinary(BYTE *&pByte, INT &length);
    };
    
}

#endif /* defined(__ZTJT__DayPlan__) */
