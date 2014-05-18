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
#include "GraphicObject.h"


namespace ZTNAMESPACE
{
    
    typedef enum {
        LineColorWhite  = 1,
        LineColorYellow = 2
    }LineColor;
    
    typedef enum {
        LineWidth1 = 1,
        LineWidth2 = 2,
        LineWidth4 = 4,
        LineWidth8 = 8
    }LineWidth;
    
    
    class Line : public GraphicObject
    {
    private:
        POINT m_ptStart;
        POINT m_ptEnd;
        LineColor  m_color;
        LineWidth  m_width;
        
    public:
        Line();
        Line(POINT ptStart, POINT ptEnd);
        ~Line();
        
        
        
        VOID SetStart(POINT start);
        POINT Start() const;
        
        VOID SetEnd(POINT end);
        POINT End() const;
        
        VOID SetColor(LineColor color);
        LineColor Color() const;
        
        VOID SetWidth(LineWidth width);
        LineWidth Width() const;
        
    public:
        ZTBOOL HitTest(POINT point);
        
        void GenerateBinary(BYTE *&pByte, INT &length);
    };
    
}
#endif /* defined(__ZTJT__Line__) */
