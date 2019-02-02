/*
	Name: MenuTollgate 
	Complier：VS 
	Date: 05/08/15 14:03
	Description: 主菜单场景 
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
 	//创建开始按钮
	void createStartButton();
	//创建帮助按钮
	void createHelpButton();
	//创建退出按钮
	void createExitButton();
	//进行初始化（背景音乐，背景图片，标题等） 
	void bgInit(); 
	//帮助菜单函数
	void helpFunc(CCObject *b,CCControlEvent e);
	//开始函数
	void startFunc(CCObject *b,CCControlEvent e);
	//退出回调函数
	void exitFunc(CCObject *b,CCControlEvent e);
	//字移动
	void update(float a);
	//文字精灵
	CCSprite *word;
};
#endif 
