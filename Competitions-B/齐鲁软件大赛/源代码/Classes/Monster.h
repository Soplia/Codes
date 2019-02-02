/*
	Name: Monster
	Complier：VS 
	Date: 05/08/15 14:32
	Description: 怪物类 
*/
#ifndef _Monster_
#define _Monster_
#include "Entity.h"
#include "GaveLock.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class Monster:public Entity
{
 public:
 	Monster();
	~Monster();
	virtual bool init();
	CREATE_FUNC(Monster);
	//判断物体是否在杠杆扫过的范围内
	bool isInGaveLock(GaveLock *temp,int ,Monster *);
	//设置获得质量
	void setWeight(float a);
	float getWeight();
	//设置获得物体的标记
	void setKind(int a);
	int getKind();
	//设置获得标记物体是否和杠杆碰撞的标记
	void setFlagIn(int );
	int getFlagIn();
 private:
	//怪兽的质量
	float weight;
	//怪物的种类
	int kind;
	//怪物是否已经和杠杆碰撞
	int flagIn;
};
#endif 
