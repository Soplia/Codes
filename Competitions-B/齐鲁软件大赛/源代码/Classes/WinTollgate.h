/*
	Name: WinTollgate
	Complier: VS
	Date: 05/08/15 14:02
	Description:获胜场景 
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
	//场景类所需的三个成员方法
 	virtual bool init();
	static CCScene *scene();
	CREATE_FUNC(WinTollgate);
	//创建返回主菜单按钮
	void createBackButton();
	//创建进入下一关的按钮	
	void createNextGate();
	//进行初始化
	void bgInit(); 
	//返回主菜单函数
	void callBack(CCObject *b,CCControlEvent e);
	//切换场景
	void changeTollgate();
	//设置时间
	void setTime(int );
	//设置游戏得分
	void setScore(int );
private:
	//记录玩家所用的时间
	int time;
	//记录玩家的游戏得分
	int score;
};
#endif
