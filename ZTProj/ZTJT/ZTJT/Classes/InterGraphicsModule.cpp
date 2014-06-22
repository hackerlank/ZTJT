//
//  InterGraphicsModule.cpp
//  ZTJT
//
//  Created by PerryMac on 3/19/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#include "InterGraphicsModule.h"


namespace ZTNAMESPACE
{
    
    InterGraphicsModule::InterGraphicsModule()
    {
        
    }
    
    InterGraphicsModule::~InterGraphicsModule()
    {
        list<Vertex*>::iterator vertexIt = m_Vertexes.begin();
        while (vertexIt != m_Vertexes.end())
        {
            delete *vertexIt;
            vertexIt++;
        }
        
        
        list<Line*>::iterator lineIt = m_Lines.begin();
        while (lineIt != m_Lines.end())
        {
            delete *lineIt;
            lineIt++;
        }
        
        list<LampGroup*>::iterator lgIt = m_LampGroups.begin();
        while (lgIt != m_LampGroups.end())
        {
            delete *lgIt;
            lgIt++;
        }
        
        list<Name*>::iterator nameIt = m_Names.begin();
        while (nameIt != m_Names.end())
        {
            delete *nameIt;
            nameIt++;
        }
    }
    
    Vertex* InterGraphicsModule::AddVertex(POINT point)
    {
        Vertex *vertex = new Vertex(point);
        m_Vertexes.push_back(vertex);
        
        return vertex;
    }
    
    void InterGraphicsModule::DelVertex(Vertex *vertex)
    {
        m_Vertexes.remove(vertex);
    }
    
    Line* InterGraphicsModule::AddLine(POINT start, POINT end)
    {
        Line *newLine = new Line(start, end);
        m_Lines.push_back(newLine);
        
        return newLine;
    }
    
    void  InterGraphicsModule::DelLine(Line *aline)
    {
        m_Lines.remove(aline);
    }
    
    Lamp* InterGraphicsModule::AddLamp(POINT center, LampType type)
    {
        Lamp *newLamp = new Lamp(center, type);
        
        LampGroup *defaultGroup = GetDefaultGroup();
        defaultGroup->AddLamp(newLamp);
        
        return newLamp;
    }
    
    void  InterGraphicsModule::DelLamp(Lamp *alamp)
    {
        list<LampGroup *>::iterator it = m_LampGroups.begin();
        while (it != m_LampGroups.end())
        {
            if ((*it)->HasLamp(alamp))
            {
                (*it)->RemoveLamp(alamp);
                
                break;
            }
        }
        
        //如果group内没有灯，那么删除这个组
        if (it != m_LampGroups.end())
        {
            if ((*it)->IsEmpty() && !(*it)->IsDefaultGroup())
            {
                delete *it;
            }
            
            m_LampGroups.erase(it);
        }
    }
    
    ZTBOOL  InterGraphicsModule::SetLampLddout(Lamp *alamp, BYTE lddout)
    {
        LampGroup *group = GetGroup(lddout);
        if (!group->CanAddLamp(alamp))
        {           //不能加入这个组，灯有冲突
            return ZTFALSE;
        }
        //找到alamp所属的group
        LampGroup *ogroup = findLamp(alamp);
        if (ZTNULL != ogroup)
        {
            ogroup->RemoveLamp(alamp);
        }
        
        group->AddLamp(alamp);
        
        return ZTTRUE;
    }
    
    LampGroup *InterGraphicsModule::findLamp(Lamp *alamp)const
    {
        list<LampGroup*>::const_iterator it = m_LampGroups.begin();
        while (it!=m_LampGroups.end())
        {
            if ((*it)->HasLamp(alamp))
            {
                return *it;
            }
            
            it++;
        }
        
        return ZTNULL;
    }
    
    Name* InterGraphicsModule::AddName(POINT point)
    {
        Name *newName = new Name(point);
        m_Names.push_back(newName);
        
        return newName;
    }
    
    void  InterGraphicsModule::DelName(Name *aName)
    {
        m_Names.remove(aName);
    }
    
    
    
    LampGroup *InterGraphicsModule::GetDefaultGroup()
    {
        LampGroup *group = ZTNULL;
        
        list<LampGroup*>::const_iterator it = find_if(m_LampGroups.begin(), m_LampGroups.end(), LampGroup_Comparor(0));
        if (m_LampGroups.end() == it)
        {
            group = GetGroup(0);
        }
        else
        {
            group = *it;
        }
        
        return group;
    }
    
    
    LampGroup *InterGraphicsModule::GetGroup(BYTE lddout)
    {
        LampGroup *group = ZTNULL;
        
        list<LampGroup*>::const_iterator it = find_if(m_LampGroups.begin(), m_LampGroups.end(), LampGroup_Comparor(lddout));
        if (m_LampGroups.end() == it)
        {
            group = new LampGroup;
            group->setLddout(lddout);
            group->setState(LampStateRed);
            
            m_LampGroups.push_back(group);
        }
        else
        {
            group = *it;
        }
        
        return group;
    }
    
    
#pragma mark - coding
    void InterGraphicsModule::generateVertexBinary(BYTE *&pByte, INT &length)
    {
        //开始:0x04 第4个byte 结束:0x18E, 不包括0x18E
        //总共189个byte
        length = 0x189;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        SHORT *pShort = (SHORT *)pByte;
        *pShort = m_Vertexes.size();        //记录个数
        
        INT offset = 2;     //偏移一个word,从第二个word开始
        list<Vertex*>::iterator it = m_Vertexes.begin();
        while (it != m_Vertexes.end())
        {
            BYTE *pVertexByte = ZTNULL;
            INT len = 0;
            (*it)->GenerateBinary(pVertexByte, len);
            
            memcpy(pByte, pVertexByte, len);
            
            delete pVertexByte;
            
            offset += len;
            
            it++;
        }
    }
    
    void InterGraphicsModule::generateLinesBinary(BYTE *&pByte, INT &length)
    {
        //开始:0x18E  第398个byte  结束：0x4B0, 不包括0x4B0
        //总共802个byte
        length = 0x802;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        SHORT *pShort = (SHORT *)pByte;
        *pShort = m_Lines.size();        //记录个数
        
        INT offset = 2;     //偏移一个word,从第二个word开始
        list<Line*>::iterator it = m_Lines.begin();
        while (it != m_Lines.end())
        {
            BYTE *pLineByte = ZTNULL;
            INT len = 0;
            (*it)->GenerateBinary(pLineByte, len);
            
            memcpy(pByte, pLineByte, len);
            
            delete pLineByte;
            
            offset += len;
            
            it++;
        }
    }
    
    void InterGraphicsModule::generateLampsBinary(BYTE *&pByte, INT &length)
    {
        //开始:0x640  第1600个byte 结束:0x810 不包括0x810
        //总共0x1D0(464)个byte
        length = 0x1D0;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        SHORT *pShort = (SHORT *)pByte;
        *pShort = m_LampGroups.size();        //记录个数
        
        INT offset = 2;     //偏移一个word,从第二个word开始
        list<LampGroup*>::iterator it = m_LampGroups.begin();
        while (it != m_LampGroups.end())
        {
            BYTE *pLampgroupByte = ZTNULL;
            INT len = 0;
            (*it)->GenerateBinary(pLampgroupByte, len);
            
            memcpy(pByte, pLampgroupByte, len);
            
            delete pLampgroupByte;
            
            offset += len;
            
            it++;
        }
    }
    
    void InterGraphicsModule::generateNamesBinary(BYTE *&pByte, INT &length)
    {
        //开始:0x4B0  第1200个byte 结束:0x640, 不包括0x640
        //总共0x190(400)个BYTE
        length = 0x190;
        pByte = new BYTE[length];
        bzero(pByte, length);
        
        SHORT *pShort = (SHORT *)pByte;
        *pShort = m_Names.size();        //记录个数
        
        INT offset = 2;     //偏移一个word,从第二个word开始
        list<Name*>::iterator it = m_Names.begin();
        while (it != m_Names.end())
        {
            BYTE *pNameByte = ZTNULL;
            INT len = 0;
            (*it)->GenerateBinary(pNameByte, len);
            
            memcpy(pByte, pNameByte, len);
            
            delete pNameByte;
            
            offset += len;
            
            it++;
        }
    }
    
}