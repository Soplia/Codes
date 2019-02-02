#include "WinTollgate.h"
//��ʼ��
void WinTollgate::bgInit()
{
	//��ӷ��ذ�ť������
	createBackButton();
	//���ű�������
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("successMusic.mp3",true);
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *background=CCSprite::create("winTollgate.png");
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,0);
}
//�������ذ�ť
void WinTollgate::createBackButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//ʹ�þ��ý��а�ť����
	CCScale9Sprite *f=CCScale9Sprite::create("kong.png");
	CCScale9Sprite *b=CCScale9Sprite::create("kong.png");
	//ͨ������CCLabelTTF���������ð�ť����ʾ������
	CCLabelTTF *label=CCLabelTTF::create("BACK","Arial",20);
	CCControlButton *button=CCControlButton::create(label,f);
	button->setBackgroundSpriteForState(b,CCControlStateSelected);
	//���ð�ť����ʱ����ɫ
	button->setTitleColorForState(ccRED,CCControlStateHighlighted);
	//����¼���Ӧ
	button->addTargetWithActionForControlEvents(this,
		cccontrol_selector(WinTollgate::callBack),CCControlEventTouchUpInside);
	button->setPosition(ccp(size.width-35,size.height/8));
	this->addChild(button,1);
}
//��ť��Ӧ����
void WinTollgate::callBack(CCObject *b,CCControlEvent e)
{
	CCDirector::sharedDirector()->replaceScene(MenuTollgate::scene());
}
//�л�����
void WinTollgate::changeTollgate()
{
	CCDirector::sharedDirector()->replaceScene(WinTollgate::scene());
}
//����ʱ��
void WinTollgate::setTime(int a)
{
	this->time=a;
}
//������ҵ÷�
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