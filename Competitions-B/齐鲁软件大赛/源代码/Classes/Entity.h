/*
	Name: Entity 
	Complier：VS 
	Date: 05/08/15 14:06
	Description:实体类 
*/
#ifndef _Entity_
#define _Entity_
#include "cocos2d.h"
using namespace cocos2d;
class Entity:public CCNode
{
 public:
 	Entity();
	~Entity();
	//获得精灵 
	CCSprite *getSprite();
	//绑定精灵 
	void bindSprite(CCSprite *s);
 private:
 	//精灵对象 
 	CCSprite *mySprite;	
};
#endif
