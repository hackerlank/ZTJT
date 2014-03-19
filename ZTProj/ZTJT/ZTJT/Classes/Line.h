//
//  Line.h
//  ZTJT
//
//  Created by PerryMac on 3/18/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__Line__
#define __ZTJT__Line__

#include "TypeDef.h"
#include "ZTObject.h"

class Line : public ZTObject {
private:
    POINT m_ptStart;
    POINT m_ptEnd;
    BYTE  m_color;
    BYTE  m_width;
    
public:
    Line();
    Line(POINT ptStart, POINT ptEnd);
    ~Line();
    
    typedef enum {
        LineColorWhite,
        LineColorYellow
    }LineColor;
    
    typedef enum {
        LineWidth1,
        LineWidth2,
        LineWidth3,
        LineWidth4
    }LineWidth;
    
    VOID SetStart(POINT start);
    POINT Start() const;
    
    VOID SetEnd(POINT end);
    POINT End() const;
    
    VOID SetColor(BYTE color);
    BYTE Color() const;
    
    VOID SetWidth(BYTE width);
    BYTE Width() const;
};

#endif /* defined(__ZTJT__Line__) */
