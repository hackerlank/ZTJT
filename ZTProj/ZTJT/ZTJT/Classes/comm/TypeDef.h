//
//  TypeDef.h
//  SocketOnBackground
//
//  Created by Perry on 14-2-15.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#ifndef SocketOnBackground_TypeDef_h
#define SocketOnBackground_TypeDef_h

#include <sys/types.h>

typedef int32_t  INT32;
typedef uint32_t UINT32;
typedef uint16_t UINT16;

typedef void VOID;


typedef int32_t INT;
typedef uint32_t UINT;
typedef double  DOUBLE;
typedef unsigned char BYTE;


typedef bool ZTBOOL;
#define ZTTRUE 1
#define ZTFALSE 0
#define ZTNULL 0


#define SOCKET_LEN_MAX 1024


typedef struct {
    UINT  x;
    UINT  y;
}POINT;




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

#endif
