//
//  Name.h
//  ZTJT
//
//  Created by PerryMac on 3/19/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Name__
#define __ZTJT__Name__

#include "TypeDef.h"
#include "GraphicObject.h"
#include <string>

using namespace std;

class Name : GraphicObject
{
    CONSTRUCTOR_DECLARE(Name)
    Name(POINT pt);
    PRIVATE_PROPERTY(POINT, LefttopPt)
    PRIVATE_PROPERTY(string, NameStr)
    
public:
    ZTBOOL HitTest(POINT point);
    
    void generateBinary(BYTE *&pByte, INT &length);
};

#endif /* defined(__ZTJT__Name__) */
