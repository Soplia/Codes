#include "SelectTollgate.h"
//��ʼ��
void SelectTollgate::bgInit()
{
	//������һ�ذ�ť
	createFirstGateButton();
	//�����ڶ��ذ�ť
	createSecondGateButton();
	//�������ذ�ť
	createBackButton();
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//��������ͼƬ
	CCSprite *background=CCSprite::create("selectTollgate.png");
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,0);
}
//���������һ�ذ�ť
void SelectTollgate::createFirstGateButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("opr_btn_nor.png");
	CCScale9Sprite *b=CCScale9Sprite::create("opr_btn_light.png");
	CCLabelTTF *label=CCLabelTTF::create("1","Arial",30);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	//���õ���ʱ��ť���ֵ���ʾ��ɫ
	button->setTitleColorForState(ccYELLOW,CCControlStateHighlighted);
	//Ϊ�ð�ť�����Ļ��Ӧ�¼�
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(SelectTollgate::firstGateFunc),CCControlEventTouchUpInside);
	button->setPosition(ccp(size.width*0.43,size.height*0.36));
	this->addChild(button,1);
}
//��һ�ذ�ť�ص�����
void SelectTollgate::firstGateFunc(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(FirstTollgate::scene());
}
//�����ڶ��ذ�ť
void SelectTollgate::createSecondGateButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//ʹ�þ��ô�����ť
	CCScale9Sprite *f=CCScale9Sprite::create("opr_btn_nor.png");
	CCScale9Sprite *b=CCScale9Sprite::create("opr_btn_light.png");
	CCLabelTTF *label=CCLabelTTF::create("2","Arial",30);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	button->setTitleColorForState(ccYELLOW,CCControlStateHighlighted);
	//Ϊ��ť�����Ӧ�¼�
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(SelectTollgate::secondGateFunc),CCControlEventTouchUpInside);
	button->setPosition(ccp(size.width*0.76,size.height*0.36));
	this->addChild(button,1);
}
//�ڶ��ذ�ť�ص�����
void SelectTollgate::secondGateFunc(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(SecondTollgate::scene());
}
//�����������˵��ص�����
void SelectTollgate::createBackButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	CCLabelTTF *label=CCLabelTTF::create("BACK","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);
	//Ϊ��ť��ӻص�����
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(SelectTollgate::callBack),CCControlEventTouchUpInside);
	CCSize sizeF=f->getContentSize();
	button->setPosition(ccp(size.width-sizeF.width/3*2,sizeF.height/3*2));
	this->addChild(button,1);
}
//�������˵���ť�ص�����
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