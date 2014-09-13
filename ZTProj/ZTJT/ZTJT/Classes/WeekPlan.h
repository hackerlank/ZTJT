//
//  WeekPlan.h
//  ZTJT
//  周计划
//  Created by Perry on 14-5-11.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Plan__
#define __ZTJT__Plan__

#include "BinaryObj.h"
#include "DayPlan.h"
#include <list>
using namespace std;

namespace ZTNAMESPACE
{
    
    class WeekPlan : public BinaryObj
    {
        CONSTRUCTOR_DECLARE(WeekPlan);
    public:
        /*
         * @param dayIndex:  星期天为0 星期六为6
         * @param planIndex: 日计划index, 从0~12
         */
        void SetDayPlan(INT dayIndex, INT planIndex);
        
        void GenerateBinary(BYTE *&pByte, INT &length);
        
    private:
        INT m_WeekPlan[7];
        
    };
}

#endif /* defined(__ZTJT__Plan__) */
