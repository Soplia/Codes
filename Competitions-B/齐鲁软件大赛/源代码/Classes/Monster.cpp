#include "Monster.h"
bool Monster::init()
{
	return true;
}
//设置flagIn的值，其中a是要被设置的值
void Monster::setFlagIn(int a)
{
	flagIn=a;
}
int Monster::getFlagIn()
{
	return flagIn;
}
Monster::Monster()
{
	weight=0;
	kind=0;
	flagIn=0;
}
Monster::~Monster()
{}
int Monster::getKind()
{
	return kind;
}
void Monster::setKind(int a)
{
	this->kind=a;
}
float Monster::getWeight()
{
	return this->weight;
}
void Monster::setWeight(float a)
{
	this->weight=a;
}
//根据杠杆，怪兽种类，怪兽来初步判断怪兽是否与杠杆进行了碰撞
bool Monster::isInGaveLock(GaveLock *temp,int kind,Monster *m)
{
	CCRect mr=m->getSprite()->boundingBox();
	CCRect rect=temp->getBox(kind);
	return rect.intersectsRect(mr);
}

