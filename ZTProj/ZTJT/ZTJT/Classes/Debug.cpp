//
//  Debug.cpp
//  ZTJT
//
//  Created by Perry on 14-5-2.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#include "Debug.h"
#include "stdio.h"

void HexOutput(const BYTE* buf, INT len)
{
    printf("The Hex output of data :\n\t0x");
    for(size_t i=0; i<len; ++i)
    {
        unsigned char c = buf[i]; // must use unsigned char to print >128 value
        if( c< 16)
        {
            printf("0%x", c);
        }
        else
        {
            printf("%x", c);
        }
    }
    printf("\n");
}