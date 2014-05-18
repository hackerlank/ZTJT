//
//  Period.h
//  ZTJT
//
//  Created by Perry on 14-5-11.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Period__
#define __ZTJT__Period__

#include "BinaryObj.h"

namespace ZTNAMESPACE
{
    class Period : public BinaryObj
    {
        CONSTRUCTOR_DECLARE(Period)
        
        PRIVATE_PROPERTY(INT, Hour)
        PRIVATE_PROPERTY(INT, Minute)
        PRIVATE_PROPERTY(INT, Second)
        
        /*
         * 00:关灯
         * 01:黄闪
         * 02:方案02
         * ..:..
         */
        PRIVATE_PROPERTY(INT, SchemeIndex)
        
    public:
        void GenerateBinary(BYTE *&pByte, INT &length);
    };
    
}

#endif /* defined(__ZTJT__Period__) */
