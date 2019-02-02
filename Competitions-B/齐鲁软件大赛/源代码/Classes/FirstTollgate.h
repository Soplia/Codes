/*
	Name: FirstTollgate
	Complier:VS 
	Date: 05/08/15 14:33
	Description: 第一关
*/
#ifndef _FirstTollgate_
#define _FirstTollgate_
#include "GaveLock.h"
#include "Monster.h"
#include "cocos2d.h"
#include "WinTollgate.h"
#include "LoseTollgate.h"
#include "SelectTollgate.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d::extension;
using namespace cocos2d;
class FirstTollgate:public CCLayer
{
 public:
	FirstTollgate();
	~FirstTollgate();
 	virtual bool init();
 	static CCScene*scene();
	CREATE_FUNC(FirstTollgate);
 	//创建怪物对象
	void createMonster();
	//创建怪物家
	void createMonsterHome();
	//设置向左转
	void moveLeft();
	//设置向右转
	void moveRight(); 
	//创建返回按钮
	void createBackButton();
	//打开屏幕触摸监听事件
	virtual void ccTouchesBegan(CCSet *s,CCEvent *e);
	virtual void ccTouchesMoved(CCSet *s,CCEvent *e);
	virtual void ccTouchesEnded(CCSet *s,CCEvent *e);
	virtual void ccTouchesCancelled(CCSet *s,CCEvent *e);
	//返回按钮的范围
	CCRect backButtonRect();
	CCRect homeFRect();
	CCRect homeSRect();
	CCRect homeTRect();
	//返回怪兽范围
	CCRect monsterFRect();
	CCRect monsterSRect();
	CCRect monsterTRect();
	//判断杠杆是否平衡
	void judgeMonsterF();
	void judgeMonsterS();
	void judgeMonsterT();
	//返回物体要想和杠杆保持一致，应该执行的动作
	CCMoveTo* getDis(Monster *,int kind);
	//返回函数
	void backFunc(CCSet *c);
	//判断杠杆是否能够进行移动,
	bool judgeFit(int,Monster *);
	void myUpdateF(float a);
	void bgInit();
	//减去质量
	void subM(Monster *m);
	//最后进行判断是否落到了杠杆上
	bool finallJudge(Monster *);
	//获取H1是物体到扫过的矩形的底的长度
	float getH1(Monster *);
	//获取H2是杠杆到扫过的矩形的底的长度
	float getH2(Monster *);
 private:
	 //标记放开手后能够加重量
	 //如果物体还和杠杆处于碰撞之中，那么此时
	 //如果在次放手，那么分数不应该在此增加，所以
	 //使用该变量来进行控制
	 int flagAddF;
	 int flagAddS;
	 int flagAddT;
	 //物体是否能够移动
	 int flagMoveEnable;
	 //第一个怪兽
	Monster *monsterF;
	//第二个怪兽
	Monster *monsterS;
	//第三个怪兽
	Monster *monsterT;
	//杠杆
	GaveLock *myGaveLock;
	//第一个产生怪兽的地方
	CCSprite *homeF;
	//第二个产生怪兽的地方
	CCSprite *homeS;
	//第三个产生怪兽的地方
	CCSprite *homeT;
	//返回按钮
	CCSprite *backButton;
	//标志什么时候下降
	//当点击了上面的怪兽出生地之后，物体才能够
	//进行移动，如果放手之后该物体就不能够进行移动了
	//所以这是这个标记的作用.
	int flagShow;
	//记录左右两边的重量值
	int sumF;
	int sumS;
	//用于显示的左右两边的重量
	float sF,sS;
	//标记能否开始运动
	int flagLeft;
	int flagRight;
	//记录当前是那一种物体
	int myKind;
	
	//记录分数
	float score;
	//记录程序运行的总时间
	float totalTime;
	//分数标签
	CCLabelTTF *scoreLabel;
	//左边质量总和标签
	CCLabelTTF *sumLeftLabel;
	//右边质量总和标签
	CCLabelTTF *sumRightLabel;
	//记录所用时间的标签
	CCLabelTTF *totalTimeLabel;
	
};
#endif 
