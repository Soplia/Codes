/*
	Name: GaveLock
	Complier: VS
	Date: 05/08/15 14:09
	Description: �ܸ��� 
*/
#ifndef _GaveLock_
#define _GaveLock_
#include "cocos-ext.h"
#include "Entity.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace cocos2d::extension;
class GaveLock:public Entity
{
 public:
	virtual bool init();
	CREATE_FUNC(GaveLock)
 	GaveLock();
	~GaveLock();
	//��ȡ�ܸ˵ķ�Χ,kind�����������࣬����ǹ����һ������
	CCRect getBox(int kind);
};
#endif