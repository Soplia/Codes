/*
	Name: Entity 
	Complier��VS 
	Date: 05/08/15 14:06
	Description:ʵ���� 
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
	//��þ��� 
	CCSprite *getSprite();
	//�󶨾��� 
	void bindSprite(CCSprite *s);
 private:
 	//������� 
 	CCSprite *mySprite;	
};
#endif
