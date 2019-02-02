#include "WinTollgate.h"
//初始化
void WinTollgate::bgInit()
{
	//添加返回按钮到场景
	createBackButton();
	//播放背景音乐
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("successMusic.mp3",true);
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *background=CCSprite::create("winTollgate.png");
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,0);
}
//创建返回按钮
void WinTollgate::createBackButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//使用九妹进行按钮创建
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	//通过创建CCLabelTTF精灵来设置按钮上显示的文字
	CCLabelTTF *label=CCLabelTTF::create("BACK","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	//设置按钮单击时的颜色
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);
	//添加事件响应
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(WinTollgate::callBack),CCControlEventTouchUpInside);
	button->setPosition(ccp(size.width-35,size.height/8));
	this->addChild(button,1);
}
//按钮响应函数
void WinTollgate::callBack(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(MenuTollgate::scene());
}
//切换场景
void WinTollgate::changeTollgate()
{
	CCDirector::sharedDirector()->replaceScene(WinTollgate::scene());
}
//设置时间
void WinTollgate::setTime(int a)
{
	this->time=a;
}
//设置玩家得分
void WinTollgate::setScore(int a)
{
	this->score=a;
}
CCScene *WinTollgate::scene()
{
	CCScene *scene=CCScene::create();
	WinTollgate *h=WinTollgate::create();
	scene->addChild(h);
	return scene;
}
bool WinTollgate::init()
{
	bgInit();
	return true;
}