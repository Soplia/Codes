/*
	Name: SelectTollgate
	Complier:VS 
	Date: 05/08/15 12:35
	Description: �ؿ�ѡ�񳡾� 
*/

#ifndef _SelectTollgate_
#define _SelectTollgate_
#include "cocos2d.h"
#include "FirstTollgate.h"
#include "MenuTollgate.h"
#include "SecondTollgate.h"
using namespace cocos2d::extension;
using namespace cocos2d;
class SelectTollgate:public CCLayer
{
 public:
	//�����������������Ա����
	virtual bool init();
 	static CCScene *scene();
	CREATE_FUNC(SelectTollgate); 
	//�ؿ�ѡ�񳡾���ʼ���������������֣�����ͼƬ������ȣ� 
	void bgInit();	
	//���������һ�صİ�ť 
	void createFirstGateButton();
	//��������ڶ��صİ�ť 
	void createSecondGateButton();
	//�����������˵��İ�ť 
	void createBackButton();
	//�����һ�ػص�����
	void firstGateFunc(CCObject *b,CCControlEvent e);
	//����ڶ��ػص�����
	void secondGateFunc(CCObject *b,CCControlEvent e);
	//�������˵��ص�����
	void callBack(CCObject *b,CCControlEvent e);
};
#endif
