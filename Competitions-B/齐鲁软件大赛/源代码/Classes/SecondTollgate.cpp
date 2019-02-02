#include "SecondTollgate.h"
//创建返回按钮
void SecondTollgate::createBackButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	backButton=CCSprite::create("backButton.png");
	CCSize sizeF=backButton->getContentSize();
	backButton->setPosition(ccp(size.width-sizeF.width/3*2,sizeF.height/3*2));
	this->addChild(backButton,1);
}
//返回怪兽接下来的运动方式
//k代表是要向上移动还是向下移动
CCMoveTo* SecondTollgate::getDis(Monster *mf,int k)
{
	//获取杠杆的大小
	CCSize size=myGaveLock->getSprite()->getContentSize();
	//获取怪兽的大小
	CCSize size1=mf->getSprite()->getContentSize();
	//获得杠杆中心点的位置
	CCPoint point1=myGaveLock->getSprite()->getPosition();
	//获取怪兽当前的位置
	CCPoint point2=mf->getSprite()->getPosition();
	//怪物要想和杠杆同时上升或者是下降，就需要知道
	//怪兽在垂直方向上移动的距离
	//所以使用勾股定理以及相似三角型的知识来求得怪兽要移动的距离。
	float a=size.width/4;
	float b=(size.width/2)*0.72;
	float c;
	//区分物体是在左边还是在右边
	if(point2.x>point1.x)
		c=point2.x-point1.x;
	else 
		c=point1.x-point2.x;
	float temp=(a*c)/b;
	CCMoveTo *m;
	if(k==1)//下降的动作
		m=CCMoveTo::create(2.0f,ccp(point2.x,point1.y-temp+size1.height/2));
	else if(k==2)//上升的动作
		m=CCMoveTo::create(2.0f,ccp(point2.x,point1.y+temp-size1.height/2));
	return m;
}
//向做左移动
void SecondTollgate::moveLeft()
{
	CCPoint pos1=myGaveLock->getSprite()->getPosition();
	//首先杠杆是在2秒之内移动30度。
	CCRotateTo *rLeft=CCRotateTo::create(2.0f,30);
	//创建一个动作对象，分别为一个怪兽准备。
	CCMoveTo *m1=NULL;
	//判断怪兽是否与杠杆碰撞
	if(monsterF->getFlagIn())
	{
		//如果已经和杠杆碰撞在一起了，
		//就根据怪兽创建相应的动作。
		if(monsterF->getSprite()->getPosition().x<pos1.x)
			m1=getDis(monsterF,2);//1是下降
		else
			m1=getDis(monsterF,1);//2是上升
	}
	//判断一下怪兽要执行的动作是否为空，如果不为空，则执行动作。
	if(m1!=NULL)
	{
		monsterF->getSprite()->runAction(m1);
	}
	myGaveLock->getSprite()->runAction(rLeft);
}
//向右旋转
void SecondTollgate::moveRight()
{
	CCPoint pos1=myGaveLock->getSprite()->getPosition();
	//首先杠杆是在2秒之内移动30度。
	CCRotateTo *rRight=CCRotateTo::create(2.0f,-30);
	CCMoveTo *m1=NULL;
	//判断怪兽是否与杠杆碰撞
	if(monsterF->getFlagIn())
	{
		//如果已经和杠杆碰撞在一起了，
		//就根据怪兽创建相应的动作。
		if(monsterF->getSprite()->getPosition().x<pos1.x)
			m1=getDis(monsterF,1);//1是下降
		else
			m1=getDis(monsterF,2);//2是上升
	}
	//判断一下怪兽要执行的动作是否为空，如果不为空，则执行动作。
	if(m1!=NULL)
	{
		monsterF->getSprite()->runAction(m1);
	}
	myGaveLock->getSprite()->runAction(rRight);
}

SecondTollgate::SecondTollgate()
{
	totalTimeLabel=NULL;
	totalTime=0;
	score=0;
	flagShow=0;
	flagLeft=1;
	flagRight=1;
	myKind=0;
	sumF=sumS=0;
	myGaveLock=NULL;
	monsterF=NULL;
	homeF=NULL;
	flagMoveEnable=1;
	flagAddF=0;
	sF=0;
	sS=0;
}
SecondTollgate::~SecondTollgate()
{
}
//场景初始化
void SecondTollgate::bgInit()
{
	//播放背景音乐
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("throughmusic2.mp3",true);
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//创建左边重量标签
	sumLeftLabel=CCLabelTTF::create("sumLeft=0","Arial",20);
	//创建右边重量标签
	sumRightLabel=CCLabelTTF::create("sumRight=0","Arial",20);
	//创建得分标签
	scoreLabel=CCLabelTTF::create("Score=0","Arial",20);
	//创建玩家所用时间标签
	totalTimeLabel=CCLabelTTF::create("totalTime=0","Arial",20);
	//设置左右两边重量标签的位置
	sumLeftLabel->setPosition(ccp(60,size.height/7*6-15));
	this->addChild(sumLeftLabel,1);
	sumRightLabel->setPosition(ccp(60,size.height/7*6-45));
	this->addChild(sumRightLabel,1);
	//设置得分标签和玩家游戏所用时间标签
	scoreLabel->setPosition(ccp(size.width-60,size.height/7*6-15));
	this->addChild(scoreLabel,1);
	totalTimeLabel->setPosition(ccp(size.width-60,size.height/7*6-45));
	this->addChild(totalTimeLabel,1);
}
void SecondTollgate::myUpdateF(float a)
{
	//时间增加
	totalTime+=a;
	//防止玩家一开始将物体放在杠杆上，就开始计分
	//只要杠杆一不平衡，就开始计分，以后无论玩家如何防止了.
	//而且两边只要有一个不等于0就可以了
	if(sumF!=0||sumS!=0)
		score+=0.01;
	//根据最新数据刷新得分，所用时间，左右重量标签。
	scoreLabel->setString(CCString::createWithFormat("score=%0.f",score)->getCString());
	sumLeftLabel->setString(CCString::createWithFormat("sumLeft=%0.f",sF)->getCString());
	sumRightLabel->setString(CCString::createWithFormat("sumRight=%0.f",sS)->getCString());
	totalTimeLabel->setString(CCString::createWithFormat("totalTime=%0.f",totalTime)->getCString());
	//如果分数大于4分，则进入下一个关卡.
	if(score>=4)
		CCDirector::sharedDirector()->replaceScene(WinTollgate::scene());
	float c=myGaveLock->getSprite()->boundingBox().getMinY()-myGaveLock->getSprite()->getPosition().y;
	if(c<0)
		c=-c;
	CCSize size=myGaveLock->getSprite()->getContentSize();
	//如果杠杆一端着地，或者是所用时间超过规定时间则判为失败。
	if(c>=size.width/4||totalTime>=70)
		CCDirector::sharedDirector()->replaceScene(LoseTollgate::scene());
}
bool SecondTollgate::init()
{
	//启动屏幕触摸监测事件
	this->setTouchEnabled(true);
	//启动schedule
	this->schedule(schedule_selector(SecondTollgate::myUpdateF));
	//背景初始化
	bgInit();
	//创建返回按钮
	createBackButton();
	//创建怪兽
	createMonster();
	//创建怪兽产生地.
	createMonsterHome();
	//获取屏幕的大小进行初始化
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *background=CCSprite::create("moveTollgate.png");
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,0);
	CCSprite *s=CCSprite::create("gavelock.png");
	s->setPosition(ccp(size.width/2,size.height/6+17));
	myGaveLock=GaveLock::create();
	myGaveLock->bindSprite(s);
	this->addChild(myGaveLock,1);
	return true;
}
//创建怪兽
void SecondTollgate::createMonster()
{
	//获取屏幕的大小
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//创建第一个怪兽
	CCSprite *s=CCSprite::create("monster.png");
	s->setPosition(ccp(size.width+50,size.height+50));
	monsterF=Monster::create();
	monsterF->bindSprite(s);
	this->addChild(monsterF,1);
	monsterF->setKind(1);
	monsterF->setWeight(3);
}

void SecondTollgate::createMonsterHome()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//创建第一个怪兽出生地
	homeF=CCSprite::create("ufoM.png");
	//高度下降,降低游戏的难度
	homeF->setPosition(ccp(size.width/2,size.height/7*5));
	this->addChild(homeF,1);
}
CCScene *SecondTollgate::scene()
{
	CCScene *scene=CCScene::create();
	SecondTollgate *m=SecondTollgate::create();
	scene->addChild(m);
	return scene;
}
//如果怪兽从杠杆上消失，需要将杠杆左右两边的重量进行相应的减少。
void SecondTollgate::subM(Monster *m)
{
	//获取怪兽的坐标
	int point=m->getSprite()->getPosition().x;
	//获取当前杠杆的位置坐标
	CCPoint pos=myGaveLock->getSprite()->getPosition();
	float temp=0;
	//如果怪兽在杠杆中点的右边
	if(point>pos.x)
	{
		temp=(point-pos.x)*(m->getWeight());
		if(sS>=temp)
			sS-=temp;
	}
	//如果怪兽在杠杆中点的左边
	else if(point<pos.x)
	{
		temp=(pos.x-point)*(m->getWeight());
		if(sF>=temp)
			sF-=temp;
	}
}
//触摸开始时进行的一系列操作
void SecondTollgate::ccTouchesBegan(CCSet *s,CCEvent *e)
{
	//获取触摸点的位置.
	CCTouch *t=(CCTouch *)s->anyObject();
	CCPoint pos=t->getLocationInView();
	CCPoint pos1=CCDirector::sharedDirector()->convertToGL(pos);
	//获取怪兽产生地的位置.
	CCRect rectF=homeFRect();
	//判断是否点中了怪兽1的产生地
	if(rectF.containsPoint(pos1))
	{
		//显示物体的重量，显示之后立即消失
		CCLabelTTF *label=CCLabelTTF::create(CCString::createWithFormat("%d",(int)monsterF->getWeight())->getCString()
			,"Arial",30);
		CCPoint pos=homeF->getPosition();
		CCSize size=homeF->getContentSize();
		label->setPosition(ccp(pos.x,pos.y+size.height/2));
		this->addChild(label,2);
		CCScaleTo *s=CCScaleTo::create(1.0f,0);
		label->runAction(s);
		//如果怪兽与物体碰撞在了一起，则在回收的时候减去响应的重量。
		if(monsterF->getFlagIn())
			subM(monsterF);
		monsterF->getSprite()->setPosition(pos1);
		//标志怪兽现在能否根据光标的移动而移动
		flagShow=1;
		//标志杠杆左右两边的重量能否增加
		flagAddF=1;
		//标志当前是那种怪兽在显示
		myKind=monsterF->getKind();
		//设置怪兽未与杠杆碰撞
		monsterF->setFlagIn(0);
	}
}
//触摸过程中进行的操作
void SecondTollgate::ccTouchesMoved(CCSet *s,CCEvent *e)
{
	CCTouch *t=(CCTouch *)s->anyObject();
	CCPoint pos=t->getLocationInView();
	CCPoint pos1=CCDirector::sharedDirector()->convertToGL(pos);
	//如果怪兽被允许出现，则进行显示
	if(flagShow&&myKind!=0)
	{
		//根据怪兽的类型进行相应的显示操作.
		if(myKind==1)
			monsterF->getSprite()->setPosition(ccp(pos1.x-40,pos1.y-40));
	}
}
//单击完了之后进行的一系列操作.
void SecondTollgate::ccTouchesEnded(CCSet *c,CCEvent *e)
{
	//修改运动标记，让硬币无法再此运动	
	flagShow=0;
	//返回按钮
	backFunc(c);
	CCTouch *touch=(CCTouch*)c->anyObject();
	CCPoint pos1=touch->getLocationInView();
	//进行改变
	CCPoint pos3=CCDirector::sharedDirector()->convertToGL(pos1);
	//为了让他能够在手指的左侧进行显示，
	//并且上次已经是将x的坐标减了20 ，
	//所以这一次应该是x减20才对.
	CCPoint pos2=CCPoint(pos3.x-40,pos3.y-40);
	CCRect mFRect=monsterFRect();
	if(mFRect.containsPoint(pos2))
	{
		judgeMonsterF();
	}
}
void SecondTollgate::ccTouchesCancelled(CCSet *s,CCEvent *e)
{
}
//返回 返回按钮的范围大小
CCRect SecondTollgate::backButtonRect()
{
	if(backButton==NULL)
		return CCRectMake(0,0,0,0);
	CCSize size=backButton->getContentSize();
	CCPoint point=backButton->getPosition();
	return CCRectMake(point.x-size.width/2,point.y-size.height/2,size.width,size.height);
}
//返回怪兽产生地的范围大小
CCRect SecondTollgate::homeFRect()
{
	if(homeF==NULL)
		return CCRectMake(0,0,0,0);
	CCSize size=homeF->getContentSize();
	CCPoint pos2=homeF->getPosition();
	return CCRectMake(pos2.x-size.width/2,pos2.y-size.height/2,size.width,size.height);
}


void SecondTollgate::backFunc(CCSet *c)
{
	CCTouch *touch=(CCTouch *)c->anyObject();
	CCPoint pos1=touch->getLocationInView();
	CCPoint pos2=CCDirector::sharedDirector()->convertToGL(pos1);
	CCRect rectB=backButtonRect();
	if(rectB.containsPoint(pos2))
		CCDirector::sharedDirector()->replaceScene(SelectTollgate::scene());
}
//返回怪兽的范围
CCRect SecondTollgate::monsterFRect()
{
	if(monsterF==NULL)
		return CCRectMake(0,0,0,0);
	return monsterF->getSprite()->boundingBox();
}
//判断一下现在是否适合运动
bool SecondTollgate::judgeFit(int a,Monster *m)
{
	CCPoint pos1=myGaveLock->getSprite()->getPosition();
	CCSize size=myGaveLock->getSprite()->getContentSize();
	CCPoint point=m->getSprite()->getPosition();
	float c;
	if(a==1)//左边的物体重
		if(point.x<pos1.x)//物体在左边
		{
			c=myGaveLock->getSprite()->boundingBox().getMinY()-pos1.y;
			if(point.y<pos1.y&&c<-(size.width)/4)
				return false;
			return true;
		}
		else//物体在右边
			return false;
	else if(a==2)//右边的物体重
		if(point.x>pos1.x)
		{
			c=myGaveLock->getSprite()->boundingBox().getMinY()-pos1.y;
			if(point.y<pos1.y&&c<-(size.width/4))
				return false;
			return true;
		}
		else 
			return false;
}
void SecondTollgate::judgeMonsterF()
{
	float L1,L2,M1,M2;
	if(finallJudge(monsterF))
	{
		//立即将标记设置成1，
		//来进行标记物体是否和杠杆已经碰撞了。
		monsterF->setFlagIn(1);
		CCPoint posM=monsterF->getSprite()->getPosition();
		CCPoint posG=myGaveLock->getSprite()->getPosition();
		//根据怪兽落在刚赶上的位置来判断杠杆左右两边的重量该加多少
		if(posM.x<posG.x)
		{
			L1=posG.x-posM.x;
			M1=monsterF->getWeight();
			L2=0;
			M2=0;
		}
		else if(posM.x>posG.x)
		{
			
			L2=posM.x-posG.x;
			M2=monsterF->getWeight();
			L1=0;
			M1=0;
		}
		else if(posM.x==posG.x)
		{
			L2=L1=M1=M2=0;
		}
		//如果现在杠杆两边可以加重量，则加上怪兽的重量
		if(flagAddF)
		{
			sumF+=L1*M1;
			sumS+=L2*M2;
			sF=sumF;
			sS=sumS;
		}
		if(sumF>sumS)
		{ 
			if(judgeFit(1,monsterF))
				moveRight();
		}
		else if(sumF<sumS)
		{
			if(judgeFit(2,monsterF))
				moveLeft();
		}
	}
	//实现物体的回收
	else
	{
		monsterF->getSprite()->setPosition(ccp(homeF->getPosition().x,homeF->getPosition().y));
	}
	flagAddF=0;
}
bool SecondTollgate::finallJudge(Monster *mTemp)
{
	if(mTemp->isInGaveLock(myGaveLock,mTemp->getKind(),mTemp))
	{
		float h1=getH1(mTemp);
		float h2=getH2(mTemp);
		if(h1-h2>=-mTemp->getSprite()->getContentSize().width/4&&h1-h2<=mTemp->getSprite()->getContentSize().width/2)
			return true;
		return false;
	}
	else 
		return false;
}
float SecondTollgate::getH1(Monster *temp)
{
	return temp->getSprite()->boundingBox().getMidY();
}
float SecondTollgate::getH2(Monster *temp)
{
	if(sumF==sumS)
	{
		CCSize size=myGaveLock->getSprite()->getContentSize();
		CCPoint point=myGaveLock->getSprite()->getPosition();
		return point.y+size.height/2;
	}
	float a=myGaveLock->getSprite()->boundingBox().getMaxX()-
		myGaveLock->getSprite()->boundingBox().getMinX();
	float c=myGaveLock->getSprite()->boundingBox().getMaxY()-
		myGaveLock->getSprite()->boundingBox().getMinY();
	float b;
	if(sumF<sumS)
	{
		b=myGaveLock->getSprite()->boundingBox().getMaxX()-temp->getSprite()->getPositionX();
	}
	else if(sumF>sumS)
	{
		b=temp->getSprite()->getPositionX()-myGaveLock->getSprite()->boundingBox().getMinX();
	}
	
	float z=c*b/a;
	return z+=(myGaveLock->getSprite()->getContentSize().height/2+myGaveLock->getSprite()->boundingBox().getMinY());
}
