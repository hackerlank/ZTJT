//
//  TypeDef.h
//  SocketOnBackground
//
//  Created by Perry on 14-2-15.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#ifndef SocketOnBackground_TypeDef_h
#define SocketOnBackground_TypeDef_h

#ifdef  __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
#include <_types/_uint32_t.h>
#include <_types/_uint16_t.h>
#include <sys/_types/_int32_t.h>
#elif TARGET_OS_IPHONE
#include <sys/types.h>
#endif
#endif

#include <string.h>

typedef int32_t  INT32;
typedef uint32_t UINT32;
typedef uint16_t UINT16;

typedef void VOID;


typedef int32_t INT;
typedef uint32_t UINT;
typedef double  DOUBLE;
typedef unsigned char BYTE;
typedef short SHORT;


typedef bool ZTBOOL;
#define ZTTRUE 1
#define ZTFALSE 0
#define ZTNULL 0


#define SOCKET_LEN_MAX 1024

#define ZTNAMESPACE ZT


typedef struct {
    UINT  x;
    UINT  y;
}POINT;

/*  灯的状态
 描述灯的各种图形化类型
 */
typedef enum {
    //
    LampTypeWalk = 0,           //人行
    //////////////
    LampTypeUp,                 //上行
    LampTypeDown,               //下行
    LampTypeLeft,               //左行
    LampTypeRight,              //右行
    //以下两种等只有开/关两种状态
    LampTypeVDU,                //视频
    LampTypeManual,             //手动
    /////////////
    LampTypeRound,              //圆
    LampTypeUpTurnAround,       //上掉头
    LampTypeDownTurnAround,     //下掉头
    LampTypeLeftTurnAround,     //左掉头
    LampTypeRightTurnAround,    //右掉头
    LampTypeNonMotorizedVehicle,//非机动车
    
    LampTypeMax                 //枚举临界值
}LampType;

/*  灯的状态
    描述灯的各种状态
 */
typedef enum {
    LampStateBlack,                 //黑
    LampStateYellowShine = 1,       //黄闪
    LampStateRed,                   //红
    LampStateGreen,                 //绿
    LampStateGreenShine,            //绿闪
    LampStateYellow,                //黄
    LampStateYellowRed,             //黄红
    
    
    LampStateMax                    //临界值
}LampState;


#define PRIVATE_PROPERTY(type,name) \
private: \
    type m_##name; \
public: \
    const type& name()const; \
    void set##name(const type& newval);

#define PROTECTED_PROPERTY(type,name) \
protected: \
type m_##name; \
public: \
const type& name()const; \
void set##name(const type& newval);

#define SYNTHESIZE(wclass,type,name) \
const type& wclass::name() const \
{ \
    return m_##name; \
} \
 \
 \
VOID wclass::set##name(const type& newval) \
{ \
    m_##name = newval; \
}

#define CONSTRUCTOR_DECLARE(wclass) \
public:\
    wclass();\
    ~wclass();

#define PROTECTED_CONSTRUCTOR_DECLARE(wclass) \
protected:\
    wclass();\
    ~wclass();

#define CONSTRUCTOR_IMPLEMENTATION(wclass) \
wclass::wclass() \
{ \
} \
wclass::~wclass() \
{ \
}


#define MAKESHORT(low,high) ((SHORT)(((BYTE)(((UINT)(low)) & 0xff)) | ((SHORT)((BYTE)(((UINT)(high)) & 0xff))) << 8))

#endif
