//
//  BinaryObj.h
//  ZTJT
//
//  Created by Perry on 14-5-2.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__BinaryObj__
#define __ZTJT__BinaryObj__

#include "ZTObject.h"

class BinaryObj : public ZTObject
{
    PROTECTED_CONSTRUCTOR_DECLARE(BinaryObj)
    
private:
    virtual void generateBinary(BYTE *&pByte, INT &length) = 0;
};

#endif /* defined(__ZTJT__BinaryObj__) */
