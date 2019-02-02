#include "LoseTollgate.h"
CCScene *LoseTollgate::scene()
{
	CCScene *scene=CCScene::create();
	LoseTollgate *h=LoseTollgate::create();
	scene->addChild(h);
	return scene;
}
bool LoseTollgate::init()
{
	//进行场景初始化
	bgInit();
	return true;
}
void LoseTollgate::bgInit()
{
	//创建返回按钮
	createBackButton();
	//播放背景音乐
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("endmusic.mp3",true);
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *background=CCSprite::create("loseTollgate.png");
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,1);
}
void LoseTollgate::createBackButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	CCLabelTTF *label=CCLabelTTF::create("BACK","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	//添加按钮响应事件
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(LoseTollgate::callBack),CCControlEventTouchUpInside);
	button->setPosition(ccp(size.width-35,size.height/8));
	this->addChild(button,2);
}
void LoseTollgate::callBack(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(MenuTollgate::scene());
}