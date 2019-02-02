#include "HelpTollgate.h"
CCScene *HelpTollgate::scene()
{
	CCScene *scene=CCScene::create();
	HelpTollgate *h=HelpTollgate::create();
	scene->addChild(h);
	return scene;
}
bool HelpTollgate::init()
{
	bgInit();
	return true;
}
void HelpTollgate::bgInit()
{
	createBackButton();
	//´´½¨±³¾°Í¼Æ¬
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	
	CCSprite *background=CCSprite::create("helpTollgate.png");
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,0);
}
void HelpTollgate::createBackButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	CCLabelTTF *label=CCLabelTTF::create("BACK","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(HelpTollgate::callBack),CCControlEventTouchUpInside);
	CCSize sizeF=f->getContentSize();
	button->setPosition(ccp(size.width-sizeF.width/3*2,sizeF.height/3*2));
	this->addChild(button,1);
}
void HelpTollgate::callBack(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(MenuTollgate::scene());
}