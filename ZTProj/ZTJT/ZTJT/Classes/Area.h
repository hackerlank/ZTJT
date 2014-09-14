//
//  Area.h
//  ZTJT
//
//  Created by Perry on 14-9-14.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#ifndef __ZTJT__Area__
#define __ZTJT__Area__
#include "ZTObject.h"
#include "TypeDef.h"
#include "Crossing.h"

#include <list>
using namespace std;

namespace  ZTNAMESPACE
{
    class Area : public ZTObject
    {
    private:
        Crossing *m_CurrentCrossing;
        
        CONSTRUCTOR_DECLARE(Area)
        
        //属性
        PRIVATE_PROPERTY(list<Crossing *>, CrossingList);      //区域中的所有路口
        
        
    public:
        static Area *sharedInstance();
        
        Crossing *CurrentCrossing();
        
    };
}

#endif /* defined(__ZTJT__CrossingsManager__) */
