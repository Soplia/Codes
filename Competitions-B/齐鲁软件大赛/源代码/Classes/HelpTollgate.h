/*
	Name: HelpTollgate 
	Complier��VS 
	Date: 05/08/15 14:04
	Description: ��Ϸ��鳡�� 
*/
#ifndef _HelpTollgate_
#define _HelpTollgate_
#include "cocos2d.h"
#include "cocos-ext.h"
#include "MenuTollgate.h"
using namespace cocos2d::extension;
using namespace cocos2d;
class HelpTollgate:public CCLayer
{
 public:
	virtual bool init();
	static CCScene*scene();
	CREATE_FUNC(HelpTollgate);
	//���г�ʼ�����������֣�����ͼƬ������ȣ�
	void bgInit();
	//�����������˵���ť
	void createBackButton();	
	//�������˵�����
	void callBack(CCObject *b,CCControlEvent e);
};
#endif
