/*
	Name: Monster
	Complier��VS 
	Date: 05/08/15 14:32
	Description: ������ 
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
	//�ж������Ƿ��ڸܸ�ɨ���ķ�Χ��
	bool isInGaveLock(GaveLock *temp,int ,Monster *);
	//���û������
	void setWeight(float a);
	float getWeight();
	//���û������ı��
	void setKind(int a);
	int getKind();
	//���û�ñ�������Ƿ�͸ܸ���ײ�ı��
	void setFlagIn(int );
	int getFlagIn();
 private:
	//���޵�����
	float weight;
	//���������
	int kind;
	//�����Ƿ��Ѿ��͸ܸ���ײ
	int flagIn;
};
#endif 
