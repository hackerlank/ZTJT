//
//  Vertex.h
//  ZTJT
//
//  Created by Perry on 14-5-1.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Vertex__
#define __ZTJT__Vertex__

#include "TypeDef.h"
#include "GraphicObject.h"

class Vertex : public GraphicObject
{
    CONSTRUCTOR_DECLARE(Vertex);
    Vertex(POINT pt);

    PRIVATE_PROPERTY(POINT,Point)
    
public:
    ZTBOOL HitTest(POINT point);
    
    void generateBinary(BYTE *&pByte, INT &length);
};

#endif /* defined(__ZTJT__Vertex__) */
