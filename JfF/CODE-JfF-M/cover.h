#ifndef _COVER_H
#define _COVER_H
//#include "set.h"

//每个人是一个节点 data指向KSet
typedef struct _ListElmt
{
    void *data;：

    struct _ListElmt *next;
}ListElmt;
//ListElmt：每个节点对应一个人，也用来set中的每个技能，data指向KSet

//KSet：key对应一个人的标记，set指向每个人的技能集合

typedef struct _KSet
{
    void *key;
    Set *set;
}KSet;

#endif
