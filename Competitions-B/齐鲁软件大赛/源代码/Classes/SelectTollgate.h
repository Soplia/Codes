/*
	Name: SelectTollgate
	Complier:VS 
	Date: 05/08/15 12:35
	Description: 关卡选择场景 
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
	//场景类所需的三个成员方法
	virtual bool init();
 	static CCScene *scene();
	CREATE_FUNC(SelectTollgate); 
	//关卡选择场景初始化方法（背景音乐，背景图片，标题等） 
	void bgInit();	
	//创建进入第一关的按钮 
	void createFirstGateButton();
	//创建进入第二关的按钮 
	void createSecondGateButton();
	//创建返回主菜单的按钮 
	void createBackButton();
	//进入第一关回调函数
	void firstGateFunc(CCObject *b,CCControlEvent e);
	//进入第二关回调函数
	void secondGateFunc(CCObject *b,CCControlEvent e);
	//返回主菜单回调函数
	void callBack(CCObject *b,CCControlEvent e);
};
#endif
