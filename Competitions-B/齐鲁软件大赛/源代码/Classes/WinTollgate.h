/*
	Name: WinTollgate
	Complier: VS
	Date: 05/08/15 14:02
	Description:��ʤ���� 
*/
#ifndef _WinTollgate_
#define _WinTollgate_
#include "cocos2d.h"
#include "cocos-ext.h"
#include "MenuTollgate.h"
using namespace cocos2d::extension;
using namespace cocos2d;
class WinTollgate:public CCLayer
{
 public:
	//�����������������Ա����
 	virtual bool init();
	static CCScene *scene();
	CREATE_FUNC(WinTollgate);
	//�����������˵���ť
	void createBackButton();
	//����������һ�صİ�ť	
	void createNextGate();
	//���г�ʼ��
	void bgInit(); 
	//�������˵�����
	void callBack(CCObject *b,CCControlEvent e);
	//�л�����
	void changeTollgate();
	//����ʱ��
	void setTime(int );
	//������Ϸ�÷�
	void setScore(int );
private:
	//��¼������õ�ʱ��
	int time;
	//��¼��ҵ���Ϸ�÷�
	int score;
};
#endif
