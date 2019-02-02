#include "FirstTollgate.h"
//�������ذ�ť
void FirstTollgate::createBackButton()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	backButton=CCSprite::create("backButton.png");
	CCSize sizeF=backButton->getContentSize();
	backButton->setPosition(ccp(size.width-sizeF.width/3*2,sizeF.height/3*2));
	this->addChild(backButton,1);
}
//���ع��޽��������˶���ʽ
//k������Ҫ�����ƶ����������ƶ�
CCMoveTo* FirstTollgate::getDis(Monster *mf,int k)
{
	//��ȡ�ܸ˵Ĵ�С
	CCSize size=myGaveLock->getSprite()->getContentSize();
	//��ȡ���޵Ĵ�С
	CCSize size1=mf->getSprite()->getContentSize();
	//��øܸ����ĵ��λ��
	CCPoint point1=myGaveLock->getSprite()->getPosition();
	//��ȡ���޵�ǰ��λ��
	CCPoint point2=mf->getSprite()->getPosition();
	//����Ҫ��͸ܸ�ͬʱ�����������½�������Ҫ֪��
	//�����ڴ�ֱ�������ƶ��ľ���
	//����ʹ�ù��ɶ����Լ����������͵�֪ʶ����ù���Ҫ�ƶ��ľ��롣
	float a=size.width/4;
	float b=(size.width/2)*0.72;
	float c;
	//��������������߻������ұ�
	if(point2.x>point1.x)
		c=point2.x-point1.x;
	else 
		c=point1.x-point2.x;
	float temp=(a*c)/b;
	CCMoveTo *m;
	if(k==1)//�½��Ķ���
		m=CCMoveTo::create(2.0f,ccp(point2.x,point1.y-temp+size1.height/2));
	else if(k==2)//�����Ķ���
		m=CCMoveTo::create(2.0f,ccp(point2.x,point1.y+temp-size1.height/2));
	return m;
}
//�������ƶ�
void FirstTollgate::moveLeft()
{
	CCPoint pos1=myGaveLock->getSprite()->getPosition();
	//���ȸܸ�����2��֮���ƶ�30�ȡ�
	CCRotateTo *rLeft=CCRotateTo::create(2.0f,30);
	//���������������󣬷ֱ�Ϊ��������׼����
	CCMoveTo *m1=NULL;
	CCMoveTo *m2=NULL;
	CCMoveTo *m3=NULL;
	//�жϹ����Ƿ���ܸ���ײ
	if(monsterF->getFlagIn())
	{
		//����Ѿ��͸ܸ���ײ��һ���ˣ�
		//�͸��ݹ��޴�����Ӧ�Ķ�����
		if(monsterF->getSprite()->getPosition().x<pos1.x)
			m1=getDis(monsterF,2);//1���½�
		else
			m1=getDis(monsterF,1);//2������
	}
	//����ڶ���������ܸ���ײ��
	if(monsterS->getFlagIn())
	{
		if(monsterS->getSprite()->getPosition().x<pos1.x)
			m2=getDis(monsterS,2);
		else
			m2=getDis(monsterS,1);
	}
	//���������������ܸ���ײ��
	if(monsterT->getFlagIn())
	{
		if(monsterT->getSprite()->getPosition().x<pos1.x)
			m3=getDis(monsterT,2);
		else
			m3=getDis(monsterT,1);
	}
	//�ж�һ�¹���Ҫִ�еĶ����Ƿ�Ϊ�գ������Ϊ�գ���ִ�ж�����
	if(m1!=NULL)
	{
		monsterF->getSprite()->runAction(m1);
	}
	if(m2!=NULL)
	{
		monsterS->getSprite()->runAction(m2);
	}
	if(m3!=NULL)
	{
		monsterT->getSprite()->runAction(m3);
	}
	myGaveLock->getSprite()->runAction(rLeft);
}
//������ת
void FirstTollgate::moveRight()
{
	CCPoint pos1=myGaveLock->getSprite()->getPosition();
	//���ȸܸ�����2��֮���ƶ�30�ȡ�
	CCRotateTo *rRight=CCRotateTo::create(2.0f,-30);
	CCMoveTo *m1=NULL;
	CCMoveTo *m2=NULL;
	CCMoveTo *m3=NULL;
	//�жϹ����Ƿ���ܸ���ײ
	if(monsterF->getFlagIn())
	{
		//����Ѿ��͸ܸ���ײ��һ���ˣ�
		//�͸��ݹ��޴�����Ӧ�Ķ�����
		if(monsterF->getSprite()->getPosition().x<pos1.x)
			m1=getDis(monsterF,1);//1���½�
		else
			m1=getDis(monsterF,2);//2������
	}
	//�жϵڶ��������Ƿ���ܸ���ײ��
	if(monsterS->getFlagIn())
	{
		if(monsterS->getSprite()->getPosition().x<pos1.x)
			m2=getDis(monsterS,1);
		else
			m2=getDis(monsterS,2);
	}
	//�жϵ����������Ƿ���ܸ���ײ��
	if(monsterT->getFlagIn())
	{
		if(monsterT->getSprite()->getPosition().x<pos1.x)
			m3=getDis(monsterT,1);
		else
			m3=getDis(monsterT,2);
	}
	//�ж�һ�¹���Ҫִ�еĶ����Ƿ�Ϊ�գ������Ϊ�գ���ִ�ж�����
	if(m1!=NULL)
	{
		monsterF->getSprite()->runAction(m1);
	}
	if(m2!=NULL)
	{
		monsterS->getSprite()->runAction(m2);
	}
	if(m3!=NULL)
	{
		monsterT->getSprite()->runAction(m3);
	}
	myGaveLock->getSprite()->runAction(rRight);
}

FirstTollgate::FirstTollgate()
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
	monsterS=NULL;
	monsterT=NULL;
	homeF=NULL;
	homeS=NULL;
	homeT=NULL;
	flagMoveEnable=1;
	flagAddF=0;
	flagAddS=0;
	flagAddT=0;
	sF=0;
	sS=0;
}
FirstTollgate::~FirstTollgate()
{
}
//������ʼ��
void FirstTollgate::bgInit()
{
	//���ű�������
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("throughmusic2.mp3",true);
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//�������������ǩ
	sumLeftLabel=CCLabelTTF::create("sumLeft=0","Arial",20);
	//�����ұ�������ǩ
	sumRightLabel=CCLabelTTF::create("sumRight=0","Arial",20);
	//�����÷ֱ�ǩ
	scoreLabel=CCLabelTTF::create("Score=0","Arial",20);
	//�����������ʱ���ǩ
	totalTimeLabel=CCLabelTTF::create("totalTime=0","Arial",20);
	//������������������ǩ��λ��
	sumLeftLabel->setPosition(ccp(60,size.height/7*6-15));
	this->addChild(sumLeftLabel,1);
	sumRightLabel->setPosition(ccp(60,size.height/7*6-45));
	this->addChild(sumRightLabel,1);
	//���õ÷ֱ�ǩ�������Ϸ����ʱ���ǩ
	scoreLabel->setPosition(ccp(size.width-60,size.height/7*6-15));
	this->addChild(scoreLabel,1);
	totalTimeLabel->setPosition(ccp(size.width-60,size.height/7*6-45));
	this->addChild(totalTimeLabel,1);
}
void FirstTollgate::myUpdateF(float a)
{
	//ʱ������
	totalTime+=a;
	//��ֹ���һ��ʼ��������ڸܸ��ϣ��Ϳ�ʼ�Ʒ�
	//ֻҪ�ܸ�һ��ƽ�⣬�Ϳ�ʼ�Ʒ֣��Ժ����������η�ֹ��.
	//��������ֻҪ��һ��������0�Ϳ�����
	if(sumF!=0||sumS!=0)
		score+=0.01;
	//������������ˢ�µ÷֣�����ʱ�䣬����������ǩ��
	scoreLabel->setString(CCString::createWithFormat("score=%0.f",score)->getCString());
	sumLeftLabel->setString(CCString::createWithFormat("sumLeft=%0.f",sF)->getCString());
	sumRightLabel->setString(CCString::createWithFormat("sumRight=%0.f",sS)->getCString());
	totalTimeLabel->setString(CCString::createWithFormat("totalTime=%0.f",totalTime)->getCString());
	//�����������4�֣��������һ���ؿ�.
	if(score>=4)
		CCDirector::sharedDirector()->replaceScene(WinTollgate::scene());
	float c=myGaveLock->getSprite()->boundingBox().getMinY()-myGaveLock->getSprite()->getPosition().y;
	if(c<0)
		c=-c;
	CCSize size=myGaveLock->getSprite()->getContentSize();
	//����ܸ�һ���ŵأ�����������ʱ�䳬���涨ʱ������Ϊʧ�ܡ�
	if(c>=size.width/4||totalTime>=70)
		CCDirector::sharedDirector()->replaceScene(LoseTollgate::scene());
}
bool FirstTollgate::init()
{
	//������Ļ��������¼�
	this->setTouchEnabled(true);
	//����schedule
	this->schedule(schedule_selector(FirstTollgate::myUpdateF));
	//������ʼ��
	bgInit();
	//�������ذ�ť
	createBackButton();
	//��������
	createMonster();
	//�������޲�����.
	createMonsterHome();
	//��ȡ��Ļ�Ĵ�С���г�ʼ��
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
//��������
void FirstTollgate::createMonster()
{
	//��ȡ��Ļ�Ĵ�С
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//������һ������
	CCSprite *s=CCSprite::create("monster.png");
	s->setPosition(ccp(size.width+50,size.height+50));
	monsterF=Monster::create();
	monsterF->bindSprite(s);
	this->addChild(monsterF,1);
	monsterF->setKind(1);
	monsterF->setWeight(3);
	//�����ڶ�������
	CCSprite *ss=CCSprite::create("monster.png");
	ss->setPosition(ccp(size.width+60,size.height+60));
	monsterS=Monster::create();
	monsterS->bindSprite(ss);
	this->addChild(monsterS,1);
	monsterS->setKind(2);
	monsterS->setWeight(5);
	//��������������
	CCSprite *st=CCSprite::create("monster.png");
	st->setPosition(ccp(size.width+70,size.height+70));
	monsterT=Monster::create();
	monsterT->bindSprite(st);
	this->addChild(monsterT,1);
	monsterT->setKind(3);
	monsterT->setWeight(7);
}

void FirstTollgate::createMonsterHome()
{
	CCSize size=CCDirector::sharedDirector()->getVisibleSize();
	//������һ�����޳�����
	homeF=CCSprite::create("ufoM.png");
	//�߶��½�,������Ϸ���Ѷ�
	homeF->setPosition(ccp(size.width/2,size.height/7*5));
	this->addChild(homeF,1);
	CCSize sizeF=homeF->getContentSize();
	//�����ڶ������޳�����
	homeS=CCSprite::create("ufoL.png");
	//�߶��½�,������Ϸ���Ѷ�
	homeS->setPosition(ccp(size.width/2-sizeF.width/2*3,size.height/7*5));
	this->addChild(homeS,1);
	//�������������޳�����
	homeT=CCSprite::create("ufoR.png");
	//�߶��½�,������Ϸ���Ѷ�
	homeT->setPosition(ccp(size.width/2+sizeF.width/2*3,size.height/7*5));
	this->addChild(homeT,1);
}
CCScene *FirstTollgate::scene()
{
	CCScene *scene=CCScene::create();
	FirstTollgate *m=FirstTollgate::create();
	scene->addChild(m);
	return scene;
}
//������޴Ӹܸ�����ʧ����Ҫ���ܸ��������ߵ�����������Ӧ�ļ��١�
void FirstTollgate::subM(Monster *m)
{
	//��ȡ���޵�����
	int point=m->getSprite()->getPosition().x;
	//��ȡ��ǰ�ܸ˵�λ������
	CCPoint pos=myGaveLock->getSprite()->getPosition();
	float temp=0;
	//��������ڸܸ��е���ұ�
	if(point>pos.x)
	{
		temp=(point-pos.x)*(m->getWeight());
		if(sS>=temp)
			sS-=temp;
	}
	//��������ڸܸ��е�����
	else if(point<pos.x)
	{
		temp=(pos.x-point)*(m->getWeight());
		if(sF>=temp)
			sF-=temp;
	}
}
//������ʼʱ���е�һϵ�в���
void FirstTollgate::ccTouchesBegan(CCSet *s,CCEvent *e)
{
	//��ȡ�������λ��.
	CCTouch *t=(CCTouch *)s->anyObject();
	CCPoint pos=t->getLocationInView();
	CCPoint pos1=CCDirector::sharedDirector()->convertToGL(pos);
	//��ȡ���޲����ص�λ��.
	CCRect rectF=homeFRect();
	CCRect rectS=homeSRect();
	CCRect rectT=homeTRect();
	//�ж��Ƿ�����˹���1�Ĳ�����
	if(rectF.containsPoint(pos1))
	{
		//��ʾ�������������ʾ֮��������ʧ
		CCLabelTTF *label=CCLabelTTF::create(CCString::createWithFormat("%d",(int)monsterF->getWeight())->getCString()
			,"Arial",30);
		CCPoint pos=homeF->getPosition();
		CCSize size=homeF->getContentSize();
		label->setPosition(ccp(pos.x,pos.y+size.height/2));
		this->addChild(label,2);
		CCScaleTo *s=CCScaleTo::create(1.0f,0);
		label->runAction(s);
		//���������������ײ����һ�����ڻ��յ�ʱ���ȥ��Ӧ��������
		if(monsterF->getFlagIn())
			subM(monsterF);
		monsterF->getSprite()->setPosition(pos1);
		//��־���������ܷ���ݹ����ƶ����ƶ�
		flagShow=1;
		//��־�ܸ��������ߵ������ܷ�����
		flagAddF=1;
		//��־��ǰ�����ֹ�������ʾ
		myKind=monsterF->getKind();
		//���ù���δ��ܸ���ײ
		monsterF->setFlagIn(0);
	}
	//�ж��Ƿ�����˹���2�Ĳ�����
	if(rectS.containsPoint(pos1))
	{
		CCLabelTTF *labe2=CCLabelTTF::create(CCString::createWithFormat("%d",(int)monsterS->getWeight())->getCString()
			,"Arial",30);
		CCPoint pos=homeS->getPosition();
		CCSize size=homeS->getContentSize();
		labe2->setPosition(ccp(pos.x,pos.y+size.height/2));
		this->addChild(labe2,2);
		CCScaleTo *s2=CCScaleTo::create(1.0f,0);
		labe2->runAction(s2);

		if(monsterS->getFlagIn())
			subM(monsterS);
		
		monsterS->getSprite()->setPosition(pos1);
		flagShow=1;
		flagAddS=1;
		myKind=monsterS->getKind();
		monsterS->setFlagIn(0);
	}
	//�ж��Ƿ�����˹���3�Ĳ�����
	if(rectT.containsPoint(pos1))
	{
		CCLabelTTF *labe3=CCLabelTTF::create(CCString::createWithFormat("%d",(int)monsterT->getWeight())->getCString()
			,"Arial",30);
		CCPoint pos=homeT->getPosition();
		CCSize size=homeT->getContentSize();
		labe3->setPosition(ccp(pos.x,pos.y+size.height/2));
		this->addChild(labe3,2);
		CCScaleTo *s3=CCScaleTo::create(1.0f,0);
		labe3->runAction(s3);

		if(monsterT->getFlagIn())
			subM(monsterT);
		
		monsterT->getSprite()->setPosition(pos1);
		flagShow=1;
		flagAddT=1;
		myKind=monsterT->getKind();
		monsterT->setFlagIn(0);
	}
}
//���������н��еĲ���
void FirstTollgate::ccTouchesMoved(CCSet *s,CCEvent *e)
{
	CCTouch *t=(CCTouch *)s->anyObject();
	CCPoint pos=t->getLocationInView();
	CCPoint pos1=CCDirector::sharedDirector()->convertToGL(pos);
	//������ޱ�������֣��������ʾ
	if(flagShow&&myKind!=0)
	{
		//���ݹ��޵����ͽ�����Ӧ����ʾ����.
		if(myKind==1)
			monsterF->getSprite()->setPosition(ccp(pos1.x-40,pos1.y-40));
		else if(myKind==2)
			monsterS->getSprite()->setPosition(ccp(pos1.x-40,pos1.y-40));
		else if(myKind==3)
			monsterT->getSprite()->setPosition(ccp(pos1.x-40,pos1.y-40));
	}
}
//��������֮����е�һϵ�в���.
void FirstTollgate::ccTouchesEnded(CCSet *c,CCEvent *e)
{
	//�޸��˶���ǣ���Ӳ���޷��ٴ��˶�	
	flagShow=0;
	//���ذ�ť
	backFunc(c);
	CCTouch *touch=(CCTouch*)c->anyObject();
	CCPoint pos1=touch->getLocationInView();
	//���иı�
	CCPoint pos3=CCDirector::sharedDirector()->convertToGL(pos1);
	//Ϊ�������ܹ�����ָ����������ʾ��
	//�����ϴ��Ѿ��ǽ�x���������20 ��
	//������һ��Ӧ����x��20�Ŷ�.
	CCPoint pos2=CCPoint(pos3.x-40,pos3.y-40);
	CCRect mFRect=monsterFRect();
	CCRect mSRect=monsterSRect();
	CCRect mTRect=monsterTRect();
	if(mFRect.containsPoint(pos2))
	{
		judgeMonsterF();
	}
	else if(mSRect.containsPoint(pos2))
	{
		judgeMonsterS();
	}
	else if(mTRect.containsPoint(pos2))
	{
		judgeMonsterT();
	}
}
void FirstTollgate::ccTouchesCancelled(CCSet *s,CCEvent *e)
{
}
//���� ���ذ�ť�ķ�Χ��С
CCRect FirstTollgate::backButtonRect()
{
	if(backButton==NULL)
		return CCRectMake(0,0,0,0);
	CCSize size=backButton->getContentSize();
	CCPoint point=backButton->getPosition();
	return CCRectMake(point.x-size.width/2,point.y-size.height/2,size.width,size.height);
}
//���ع��޲����صķ�Χ��С
CCRect FirstTollgate::homeFRect()
{
	if(homeF==NULL)
		return CCRectMake(0,0,0,0);
	CCSize size=homeF->getContentSize();
	CCPoint pos2=homeF->getPosition();
	return CCRectMake(pos2.x-size.width/2,pos2.y-size.height/2,size.width,size.height);
}

CCRect FirstTollgate::homeSRect()
{
	if(homeS==NULL)
		return CCRectMake(0,0,0,0);
	CCSize size=homeS->getContentSize();
	CCPoint pos2=homeS->getPosition();
	return CCRectMake(pos2.x-size.width/2,pos2.y-size.height/2,size.width,size.height);
}
CCRect FirstTollgate::homeTRect()
{
	if(homeT==NULL)
		return CCRectMake(0,0,0,0);
	CCSize size=homeT->getContentSize();
	CCPoint pos2=homeT->getPosition();
	return CCRectMake(pos2.x-size.width/2,pos2.y-size.height/2,size.width,size.height);
}

void FirstTollgate::backFunc(CCSet *c)
{
	CCTouch *touch=(CCTouch *)c->anyObject();
	CCPoint pos1=touch->getLocationInView();
	CCPoint pos2=CCDirector::sharedDirector()->convertToGL(pos1);
	CCRect rectB=backButtonRect();
	if(rectB.containsPoint(pos2))
		CCDirector::sharedDirector()->replaceScene(SelectTollgate::scene());
}
//���ع��޵ķ�Χ
CCRect FirstTollgate::monsterFRect()
{
	if(monsterF==NULL)
		return CCRectMake(0,0,0,0);
	return monsterF->getSprite()->boundingBox();
}
CCRect FirstTollgate::monsterSRect()
{
	if(monsterS==NULL)
		return CCRectMake(0,0,0,0);
	return monsterS->getSprite()->boundingBox();
}
CCRect FirstTollgate::monsterTRect()
{
	if(monsterT==NULL)
		return CCRectMake(0,0,0,0);
	return monsterT->getSprite()->boundingBox();
}
//�ж�һ�������Ƿ��ʺ��˶�
bool FirstTollgate::judgeFit(int a,Monster *m)
{
	CCPoint pos1=myGaveLock->getSprite()->getPosition();
	CCSize size=myGaveLock->getSprite()->getContentSize();
	CCPoint point=m->getSprite()->getPosition();
	float c;
	if(a==1)//��ߵ�������
		if(point.x<pos1.x)//���������
		{
			c=myGaveLock->getSprite()->boundingBox().getMinY()-pos1.y;
			if(point.y<pos1.y&&c<-(size.width)/4)
				return false;
			return true;
		}
		else//�������ұ�
			return false;
	else if(a==2)//�ұߵ�������
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
void FirstTollgate::judgeMonsterF()
{
	float L1,L2,M1,M2;
	if(finallJudge(monsterF))
	{
		//������������ó�1��
		//�����б�������Ƿ�͸ܸ��Ѿ���ײ�ˡ�
		monsterF->setFlagIn(1);
		CCPoint posM=monsterF->getSprite()->getPosition();
		CCPoint posG=myGaveLock->getSprite()->getPosition();
		//���ݹ������ڸո��ϵ�λ�����жϸܸ��������ߵ������üӶ���
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
		//������ڸܸ����߿��Լ�����������Ϲ��޵�����
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
	//ʵ������Ļ���
	else
	{
		monsterF->getSprite()->setPosition(ccp(homeF->getPosition().x,homeF->getPosition().y));
	}
	flagAddF=0;
}
void FirstTollgate::judgeMonsterS()
{

	
	float L1,L2,M1,M2;
	if(finallJudge(monsterS))
	{
		monsterS->setFlagIn(1);
		CCPoint posM=monsterS->getSprite()->getPosition();
		CCPoint posG=myGaveLock->getSprite()->getPosition();
		if(posM.x<posG.x)
		{
			L1=posG.x-posM.x;
			M1=monsterS->getWeight();
			L2=0;
			M2=0;
		}
		else if(posM.x>posG.x)
		{	
			L2=posM.x-posG.x;
			M2=monsterS->getWeight();
			L1=0;
			M1=0;
		}
		else
		{
			L2=L1=M1=M2=0;
		}
		if(flagAddS)
		{
			sumF+=L1*M1;
			sumS+=L2*M2;
			sF=sumF;
			sS=sumS;
		}
		if(sumF>sumS)
		{
			if(judgeFit(1,monsterS))
				moveRight();
		}
		
		else if(sumF<sumS)
		{
			if(judgeFit(2,monsterS))
				moveLeft();
		}
	}
	//ʵ������Ļ���
	else
	{
		monsterS->getSprite()->setPosition(ccp(homeS->getPosition().x,homeS->getPosition().y));
	}
	flagAddS=0;
}
void FirstTollgate::judgeMonsterT()
{
	float L1,L2,M1,M2;
	if(finallJudge(monsterT))
	{
		monsterT->setFlagIn(1);
		CCPoint posM=monsterT->getSprite()->getPosition();
		CCPoint posG=myGaveLock->getSprite()->getPosition();
		if(posM.x<posG.x)
		{
			L1=posG.x-posM.x;
			M1=monsterT->getWeight();
			L2=0;
			M2=0;
		}
		else if(posM.x>posG.x)
		{
			
			L2=posM.x-posG.x;
			M2=monsterT->getWeight();
			L1=0;
			M1=0;
		}
		else
		{
			L2=L1=M1=M2=0;
		}
		if(flagAddT)
		{
			sumF+=L1*M1;
			sumS+=L2*M2;
			sF=sumF;
			sS=sumS;
		}
		if(sumF>sumS)
		{
			if(judgeFit(1,monsterT))
			{
				moveRight();
			}
		}
		else if(sumF<sumS)
		{
			if(judgeFit(2,monsterT))
			{
				moveLeft();
			}
		}
	}
	//ʵ������Ļ���
	else
	{
		monsterT->getSprite()->setPosition(ccp(homeT->getPosition().x,homeT->getPosition().y));
	}
	flagAddT=0;
}
bool FirstTollgate::finallJudge(Monster *mTemp)
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
float FirstTollgate::getH1(Monster *temp)
{
	return temp->getSprite()->boundingBox().getMidY();
}
float FirstTollgate::getH2(Monster *temp)
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
