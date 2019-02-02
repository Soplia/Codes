/*
	Name: LoseTollgate 
	Complier：VS 
	Date: 05/08/15 14:03
	Description: 失败场景 
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
	//创建返回主菜单按钮
	void createBackButton();
	//进行初始化
	void bgInit();	
	//返回主菜单函数
	void callBack(CCObject *b,CCControlEvent e);
};
#endif