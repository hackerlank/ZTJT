//
//  DrawObject.h
//  ZTJT
//  需要描绘的元素基类
//  Created by PerryMac on 3/19/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__GraphicObject__
#define __ZTJT__GraphicObject__

#include "TypeDef.h"
#include "BinaryObj.h"

namespace ZTNAMESPACE
{
    
    class GraphicObject : public BinaryObj
    {
        PROTECTED_CONSTRUCTOR_DECLARE(GraphicObject)
        PROTECTED_PROPERTY(ZTBOOL, Focus)
        PROTECTED_PROPERTY(ZTBOOL, Drawing)
        
    protected:
        virtual ZTBOOL HitTest(POINT point) = 0;
    };
    
}

#endif /* defined(__ZTJT__DrawObject__) */
