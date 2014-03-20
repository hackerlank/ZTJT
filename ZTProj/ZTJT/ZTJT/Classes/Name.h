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
#include "ZTObject.h"
#include <string>
using namespace std;

class Name : ZTObject {
    CONSTRUCTOR_DECLARE(Name)
    Name(POINT pt);
    PRIVATE_PROPERTY(POINT, LefttopPt)
    PRIVATE_PROPERTY(string, NameStr)
};

#endif /* defined(__ZTJT__Name__) */
