//
//  PlanManager.h
//  ZTJT
//  计划
//  Created by Perry on 14-5-17.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Module__
#define __ZTJT__Module__
#include "BinaryObj.h"
#include "WeekPlan.h"
#include "DayPlan.h"

namespace ZTNAMESPACE {
    
    class PlanModule : public ZTObject
    {
        CONSTRUCTOR_DECLARE(PlanModule);
        
        
    public:
        ZT::WeekPlan &WeekPlan();
        
        //在指定位置插入一个日计划
        //如果没有计划，则添加一个默认的计划
        //如果没有任何状态情况下添加，则将index设置成0
        //最多12个日计划 0~11
        DayPlan *InsertDayPlanAtIndex(INT index);
        //删除一个状态
        void DeleteDayPlan(DayPlan *dayPlan);
        
        //获取一个状态
        DayPlan *DayPlanAtIndex(INT index);
        
    private:
        void GenerateDayPlansBinary(BYTE *&pByte, INT &length);
    private:
        ZT::WeekPlan m_WeekPlan;
        
        //最多12个日计划 0~11
        list<DayPlan *> m_DayPlans;
    };
    
}

#endif /* defined(__ZTJT__PlanManager__) */
