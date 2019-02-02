#include "MenuTollgate.h"
CCScene *MenuTollgate::scene()
{
	CCScene *scene=CCScene::create();
	MenuTollgate *h=MenuTollgate::create();
	scene->addChild(h);
	return scene;
}
bool MenuTollgate::init()
{
	this->schedule(schedule_selector(MenuTollgate::update));
	bgInit();
	return true;
}
void MenuTollgate::update(float a)
{
	//每时每刻设置文字坐标，来实现文字图片的移动.
	CCSize size=word->getContentSize();
	CCPoint point=word->getPosition();
	if(point.x<-size.width/2)
		word->setPositionX(CCDirector::sharedDirector()->getVisibleSize().width+size.width/2);
	else
		word->setPositionX(word->getPositionX()-2);
}
void MenuTollgate::bgInit()
{
	createStartButton();
	createHelpButton();
	createExitButton();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("throughmusic1.mp3",true);
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//添加背景图片
	CCSprite *background=CCSprite::create("menuTollgate.png");
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,0);
	//添加齐软字样
	word=CCSprite::create("word.png");
	word->setPosition(ccp(size.width/4*3,size.height/9));
	this->addChild(word,1);
}
void MenuTollgate::createStartButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	CCLabelTTF *label=CCLabelTTF::create("START","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);
	
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(MenuTollgate::startFunc),CCControlEventTouchUpInside);
	button->setPosition(ccp(size.width/2-100,size.height/7*3));
	this->addChild(button,1);
}
void MenuTollgate::startFunc(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(SelectTollgate::scene());
}

void MenuTollgate::createHelpButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	CCLabelTTF *label=CCLabelTTF::create("HELP","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);

	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(MenuTollgate::helpFunc),CCControlEventTouchUpInside);


	button->setPosition(ccp(size.width/2-f->getContentSize().width*1.5-70,size.height/7*3-
		f->getContentSize().height*1.5-25));
	this->addChild(button,1);
}

void MenuTollgate::helpFunc(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(HelpTollgate::scene());
}

void MenuTollgate::createExitButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	CCLabelTTF *label=CCLabelTTF::create("EXIT","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(MenuTollgate::exitFunc),CCControlEventTouchUpInside);

	button->setPosition(ccp(size.width/2+f->getContentSize().width*1.5-130,size.height/7*3-
		f->getContentSize().height*1.5-25));
	this->addChild(button,1);
}

void MenuTollgate::exitFunc(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->end();
}