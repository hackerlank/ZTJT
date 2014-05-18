//
//  RunParam.h
//  ZTJT
//
//  Created by Perry on 14-5-11.
//  Copyright (c) 2014年 PerryMac. All rights reserved.
//

#ifndef __ZTJT__RunParam__
#define __ZTJT__RunParam__

#include "BinaryObj.h"
#include "TypeDef.h"


namespace ZTNAMESPACE
{
    
    class DevConfig : public BinaryObj
    {
        CONSTRUCTOR_DECLARE(DevConfig);
        
        PRIVATE_PROPERTY(INT, Manual);          //0：启动手动控制  1：关闭手动控制
        PRIVATE_PROPERTY(INT, RedStart);        //0: 红灯开路报警  1: 红灯开路黄闪
        PRIVATE_PROPERTY(INT, GreenConflict);   //0:绿灯冲突报警 1：绿灯冲突黄闪
        PRIVATE_PROPERTY(INT, Network);         //0:被动接收信息 1:主动发送信息
        PRIVATE_PROPERTY(INT, NetControl);      //0:降到无电缆协调 1:降到自适应控制
        
    public:
        void SetLampModuleExist(INT index, ZTBOOL exist);
        void SetVduModuleExist(INT index, ZTBOOL exist);
        void SetGPSModuleExist(ZTBOOL exist);
        
        void Reset();
        
        void GenerateBinary(BYTE *&pByte, INT &length);
        
    private:
        ZTBOOL m_LampModule[8];       //8个灯控模块
        ZTBOOL m_VduModule[2];              //2个视频模块
        ZTBOOL m_GpsModule;           //GPS校时模块
        
    };
}

#endif /* defined(__ZTJT__RunParam__) */
