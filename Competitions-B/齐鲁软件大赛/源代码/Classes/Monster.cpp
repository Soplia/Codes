#include "Monster.h"
bool Monster::init()
{
	return true;
}
//����flagIn��ֵ������a��Ҫ�����õ�ֵ
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
//���ݸܸˣ��������࣬�����������жϹ����Ƿ���ܸ˽�������ײ
bool Monster::isInGaveLock(GaveLock *temp,int kind,Monster *m)
{
	CCRect mr=m->getSprite()->boundingBox();
	CCRect rect=temp->getBox(kind);
	return rect.intersectsRect(mr);
}

