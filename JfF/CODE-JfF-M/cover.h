#ifndef _COVER_H
#define _COVER_H
//#include "set.h"

//ÿ������һ���ڵ� dataָ��KSet
typedef struct _ListElmt
{
    void *data;��

    struct _ListElmt *next;
}ListElmt;
//ListElmt��ÿ���ڵ��Ӧһ���ˣ�Ҳ����set�е�ÿ�����ܣ�dataָ��KSet

//KSet��key��Ӧһ���˵ı�ǣ�setָ��ÿ���˵ļ��ܼ���

typedef struct _KSet
{
    void *key;
    Set *set;
}KSet;

#endif
