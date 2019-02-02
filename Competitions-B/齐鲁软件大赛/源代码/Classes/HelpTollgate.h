/*
	Name: HelpTollgate 
	Complier：VS 
	Date: 05/08/15 14:04
	Description: 游戏简介场景 
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
	//进行初始化（背景音乐，背景图片，标题等）
	void bgInit();
	//创建返回主菜单按钮
	void createBackButton();	
	//返回主菜单函数
	void callBack(CCObject *b,CCControlEvent e);
};
#endif
