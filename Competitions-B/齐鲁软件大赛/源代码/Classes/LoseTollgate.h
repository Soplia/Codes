/*
	Name: LoseTollgate 
	Complier��VS 
	Date: 05/08/15 14:03
	Description: ʧ�ܳ��� 
*/

#ifndef _LoseTollgate_
#define _LoseTollgate_
#include "cocos2d.h"
#include "cocos-ext.h"
#include "MenuTollgate.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d::extension;
using namespace cocos2d;
class LoseTollgate:public CCLayer
{
 public:
 	virtual bool init();
	static CCScene *scene();
	CREATE_FUNC(LoseTollgate);
	//�����������˵���ť
	void createBackButton();
	//���г�ʼ��
	void bgInit();	
	//�������˵�����
	void callBack(CCObject *b,CCControlEvent e);
};
#endif