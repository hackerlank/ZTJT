//
//  GraphicsManager.cpp
//  ZTJT
//
//  Created by PerryMac on 3/19/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "GraphicsManager.h"


GraphicsManager::GraphicsManager()
{
    
}

GraphicsManager::~GraphicsManager()
{
    
}


Line* GraphicsManager::AddLine(POINT start, POINT end)
{
    Line *newLine = new Line(start, end);
    m_Lines.push_back(newLine);
    
    return newLine;
}

void  GraphicsManager::DelLine(Line *aline)
{
    m_Lines.remove(aline);
}

Lamp* GraphicsManager::AddLamp(POINT center, LampType type)
{
    Lamp *newLamp = new Lamp(center, type);
    
    LampGroup *defaultGroup = GetDefaultGroup();
    defaultGroup->AddLamp(newLamp);
    
    return newLamp;
}

void  GraphicsManager::DelLamp(Lamp *alamp)
{
    list<LampGroup *>::iterator it = m_LampGroups.begin();
    while (it != m_LampGroups.end()) {
        if ((*it)->HasLamp(alamp)) {
            (*it)->RemoveLamp(alamp);
            
            return;
        }
    }
}

Name* GraphicsManager::AddName(POINT point)
{
    Name *newName = new Name(point);
    m_Names.push_back(newName);
    
    return newName;
}

void  GraphicsManager::DelName(Name *aName)
{
    m_Names.remove(aName);
}



LampGroup *GraphicsManager::GetDefaultGroup()
{
    LampGroup *group = ZTNULL;
    
    list<LampGroup*>::const_iterator it = find_if(m_LampGroups.begin(), m_LampGroups.end(), LampGroup_Comparor(0));
    if (m_LampGroups.end() == it) {
        group = GetGroup(0);
    }else {
        group = *it;
    }
    
    return group;
}


LampGroup *GraphicsManager::GetGroup(BYTE lddout)
{
    LampGroup *group = ZTNULL;
    
    list<LampGroup*>::const_iterator it = find_if(m_LampGroups.begin(), m_LampGroups.end(), LampGroup_Comparor(lddout));
    if (m_LampGroups.end() == it) {
        group = new LampGroup;
        group->setLddout(lddout);
        group->setState(LampStateRed);
        
        m_LampGroups.push_back(group);
    }else {
        group = *it;
    }
    
    return group;
}