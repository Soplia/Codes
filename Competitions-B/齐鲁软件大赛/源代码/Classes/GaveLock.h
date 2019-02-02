/*
	Name: GaveLock
	Complier: VS
	Date: 05/08/15 14:09
	Description: 杠杆类 
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
	//获取杠杆的范围,kind代表怪物的种类，这个是怪物的一个属性
	CCRect getBox(int kind);
};
#endif