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
    list<Line*>::iterator lineIt = m_Lines.begin();
    while (lineIt != m_Lines.end()) {
        delete *lineIt;
        lineIt++;
    }
    
    list<LampGroup*>::iterator lgIt = m_LampGroups.begin();
    while (lgIt != m_LampGroups.end()) {
        delete *lgIt;
        lgIt++;
    }
    
    list<Name*>::iterator nameIt = m_Names.begin();
    while (nameIt != m_Names.end()) {
        delete *nameIt;
        nameIt++;
    }
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
            
            break;
        }
    }
    
    //如果group内没有灯，那么删除这个组
    if (it != m_LampGroups.end()) {
        if ((*it)->IsEmpty() && !(*it)->IsDefaultGroup()) {
            delete *it;
        }
        
        m_LampGroups.erase(it);
    }
}

ZTBOOL  GraphicsManager::SetLampLddout(Lamp *alamp, BYTE lddout)
{
    LampGroup *group = GetGroup(lddout);
    if (!group->CanAddLamp(alamp)) {           //不能加入这个组，灯有冲突
        return ZTFALSE;
    }
    //找到alamp所属的group
    LampGroup *ogroup = findLamp(alamp);
    if (ZTNULL != ogroup) {
        ogroup->RemoveLamp(alamp);
    }
    
    group->AddLamp(alamp);
    
    return ZTTRUE;
}

LampGroup *GraphicsManager::findLamp(Lamp *alamp)const
{
    list<LampGroup*>::const_iterator it = m_LampGroups.begin();
    while (it!=m_LampGroups.end()) {
        if ((*it)->HasLamp(alamp)) {
            return *it;
        }
        
        it++;
    }
    
    return ZTNULL;
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