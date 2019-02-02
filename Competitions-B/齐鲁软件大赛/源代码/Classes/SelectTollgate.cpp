#include "SelectTollgate.h"
//初始化
void SelectTollgate::bgInit()
{
	//创建第一关按钮
	createFirstGateButton();
	//创建第二关按钮
	createSecondGateButton();
	//创建返回按钮
	createBackButton();
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//创建背景图片
	CCSprite *background=CCSprite::create("selectTollgate.png");
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,0);
}
//创建进入第一关按钮
void SelectTollgate::createFirstGateButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("opr_btn_nor.png");
	CCScale9Sprite *b=CCScale9Sprite::create("opr_btn_light.png");
	CCLabelTTF *label=CCLabelTTF::create("1","Arial",30);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	//设置单击时按钮文字的显示颜色
	button->setTitleColorForState(ccYELLOW,CCControlStateHighlighted);
	//为该按钮添加屏幕响应事件
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(SelectTollgate::firstGateFunc),CCControlEventTouchUpInside);
	button->setPosition(ccp(size.width*0.43,size.height*0.36));
	this->addChild(button,1);
}
//第一关按钮回调函数
void SelectTollgate::firstGateFunc(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(FirstTollgate::scene());
}
//创建第二关按钮
void SelectTollgate::createSecondGateButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//使用九妹创建按钮
	CCScale9Sprite *f=CCScale9Sprite::create("opr_btn_nor.png");
	CCScale9Sprite *b=CCScale9Sprite::create("opr_btn_light.png");
	CCLabelTTF *label=CCLabelTTF::create("2","Arial",30);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	button->setTitleColorForState(ccYELLOW,CCControlStateHighlighted);
	//为按钮添加响应事件
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(SelectTollgate::secondGateFunc),CCControlEventTouchUpInside);
	button->setPosition(ccp(size.width*0.76,size.height*0.36));
	this->addChild(button,1);
}
//第二关按钮回调函数
void SelectTollgate::secondGateFunc(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(SecondTollgate::scene());
}
//创建返回主菜单回调函数
void SelectTollgate::createBackButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	CCLabelTTF *label=CCLabelTTF::create("BACK","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);
	//为按钮添加回调函数
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(SelectTollgate::callBack),CCControlEventTouchUpInside);
	CCSize sizeF=f->getContentSize();
	button->setPosition(ccp(size.width-sizeF.width/3*2,sizeF.height/3*2));
	this->addChild(button,1);
}
//返回主菜单按钮回调函数
void SelectTollgate::callBack(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(MenuTollgate::scene());
}

CCScene *SelectTollgate::scene()
{
	CCScene *scene=CCScene::create();
	SelectTollgate *h=SelectTollgate::create();
	scene->addChild(h);
	return scene;
}
bool SelectTollgate::init()
{
	bgInit();
	return true;
}