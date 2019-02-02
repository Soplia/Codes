/*
	Name: MenuTollgate 
	Complier��VS 
	Date: 05/08/15 14:03
	Description: ���˵����� 
*/

#ifndef _MenuTollgate_
#define _MenuTollgate_
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SelectTollgate.h"
#include "HelpTollgate.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d::extension;
using namespace cocos2d;
class MenuTollgate:public CCLayer
{
 public:
 	static CCScene *scene();
 	virtual bool init();
 	CREATE_FUNC(MenuTollgate);
 	//������ʼ��ť
	void createStartButton();
	//����������ť
	void createHelpButton();
	//�����˳���ť
	void createExitButton();
	//���г�ʼ�����������֣�����ͼƬ������ȣ� 
	void bgInit(); 
	//�����˵�����
	void helpFunc(CCObject *b,CCControlEvent e);
	//��ʼ����
	void startFunc(CCObject *b,CCControlEvent e);
	//�˳��ص�����
	void exitFunc(CCObject *b,CCControlEvent e);
	//���ƶ�
	void update(float a);
	//���־���
	CCSprite *word;
};
#endif 
