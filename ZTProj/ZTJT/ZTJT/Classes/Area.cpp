//
//  Area.cpp
//  ZTJT
//
//  Created by Perry on 14-9-14.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#include "Area.h"


namespace ZTNAMESPACE
{
    SYNTHESIZE(Area, list<Crossing *>, CrossingList);     //区域中的所有路口
    
    Area::Area()
    {
        m_CurrentCrossing = new Crossing;
        m_CurrentCrossing->setName("天安门");
    }
    Area::~Area()
    {
        list<Crossing *>::iterator it = m_CrossingList.begin();
        while (it != m_CrossingList.end())
        {
            delete *it;
            it++;
        }
    }
    
    
    Area *Area::sharedInstance()
    {
        static Area *s_instance;
        if (NULL == s_instance)
        {
            s_instance = new Area;
        }
        
        return s_instance;
    }
    
    
    Crossing *Area::CurrentCrossing()
    {
        return m_CurrentCrossing;
    }

}
