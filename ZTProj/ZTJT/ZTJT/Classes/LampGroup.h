//
//  Lamp.h
//  ZTJT
//
//  Created by PerryMac on 3/18/14.
//  Copyright (c) 2014 PerryMac. All rights reserved.
//

#ifndef __ZTJT__LampGroup__
#define __ZTJT__LampGroup__

#include "TypeDef.h"
#include "ZTObject.h"
#include "Lamp.h"
#include <string>
#include <list>
using namespace std;


class LampGroup : ZTObject
{
public:
    LampGroup();
    ~LampGroup();
    
    PRIVATE_PROPERTY(LampState,State)
    /*
     灯组
     如果灯组值为0，则为无法识别的灯，中间叉的图标
     */
    PRIVATE_PROPERTY(BYTE,Lddout)  //1~16
    
    
    UINT NextState();
    
    const string* LddoutString() const;
    
    ZTBOOL IsDefaultGroup()const;
    /*
     是否可以在这个组中添加这个路灯
     规则：如果是默认组(Lddout=0)，那么任何路灯都可以添加
          其实的必须是同一类型灯才能添加(路灯，普通信号灯，视频，手控)
     */
    ZTBOOL CanAddLamp(Lamp *aLamp)const;
    ZTBOOL AddLamp(Lamp *aLamp);
    void RemoveLamp(Lamp *aLamp);       //取出一个lamp，并从组中删除
    
    ZTBOOL HasLamp(const Lamp *aLamp)const;
    //void DelLamp(const Lamp *aLamp);           //从组中删除一个lamp
    ZTBOOL IsEmpty()const;
private:
    Lamp* GetALamp()const;   //获取组中任意一个Lamp
    
private:
    list<Lamp*> m_Lamps;
};


class LampGroup_Comparor
{
public:
	LampGroup_Comparor(BYTE b)
    : lddout(b)
	{
	}
	bool operator()(const LampGroup *p)
	{
		return (lddout == p->Lddout());
	}
    
private:
	BYTE lddout;
    
};
#endif /* defined(__ZTJT__Lamp__) */
