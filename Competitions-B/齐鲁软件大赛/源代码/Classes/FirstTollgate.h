/*
	Name: FirstTollgate
	Complier:VS 
	Date: 05/08/15 14:33
	Description: ��һ��
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
 	//�����������
	void createMonster();
	//���������
	void createMonsterHome();
	//��������ת
	void moveLeft();
	//��������ת
	void moveRight(); 
	//�������ذ�ť
	void createBackButton();
	//����Ļ���������¼�
	virtual void ccTouchesBegan(CCSet *s,CCEvent *e);
	virtual void ccTouchesMoved(CCSet *s,CCEvent *e);
	virtual void ccTouchesEnded(CCSet *s,CCEvent *e);
	virtual void ccTouchesCancelled(CCSet *s,CCEvent *e);
	//���ذ�ť�ķ�Χ
	CCRect backButtonRect();
	CCRect homeFRect();
	CCRect homeSRect();
	CCRect homeTRect();
	//���ع��޷�Χ
	CCRect monsterFRect();
	CCRect monsterSRect();
	CCRect monsterTRect();
	//�жϸܸ��Ƿ�ƽ��
	void judgeMonsterF();
	void judgeMonsterS();
	void judgeMonsterT();
	//��������Ҫ��͸ܸ˱���һ�£�Ӧ��ִ�еĶ���
	CCMoveTo* getDis(Monster *,int kind);
	//���غ���
	void backFunc(CCSet *c);
	//�жϸܸ��Ƿ��ܹ������ƶ�,
	bool judgeFit(int,Monster *);
	void myUpdateF(float a);
	void bgInit();
	//��ȥ����
	void subM(Monster *m);
	//�������ж��Ƿ��䵽�˸ܸ���
	bool finallJudge(Monster *);
	//��ȡH1�����嵽ɨ���ľ��εĵ׵ĳ���
	float getH1(Monster *);
	//��ȡH2�Ǹܸ˵�ɨ���ľ��εĵ׵ĳ���
	float getH2(Monster *);
 private:
	 //��Ƿſ��ֺ��ܹ�������
	 //������廹�͸ܸ˴�����ײ֮�У���ô��ʱ
	 //����ڴη��֣���ô������Ӧ���ڴ����ӣ�����
	 //ʹ�øñ��������п���
	 int flagAddF;
	 int flagAddS;
	 int flagAddT;
	 //�����Ƿ��ܹ��ƶ�
	 int flagMoveEnable;
	 //��һ������
	Monster *monsterF;
	//�ڶ�������
	Monster *monsterS;
	//����������
	Monster *monsterT;
	//�ܸ�
	GaveLock *myGaveLock;
	//��һ���������޵ĵط�
	CCSprite *homeF;
	//�ڶ����������޵ĵط�
	CCSprite *homeS;
	//�������������޵ĵط�
	CCSprite *homeT;
	//���ذ�ť
	CCSprite *backButton;
	//��־ʲôʱ���½�
	//�����������Ĺ��޳�����֮��������ܹ�
	//�����ƶ����������֮�������Ͳ��ܹ������ƶ���
	//�������������ǵ�����.
	int flagShow;
	//��¼�������ߵ�����ֵ
	int sumF;
	int sumS;
	//������ʾ���������ߵ�����
	float sF,sS;
	//����ܷ�ʼ�˶�
	int flagLeft;
	int flagRight;
	//��¼��ǰ����һ������
	int myKind;
	
	//��¼����
	float score;
	//��¼�������е���ʱ��
	float totalTime;
	//������ǩ
	CCLabelTTF *scoreLabel;
	//��������ܺͱ�ǩ
	CCLabelTTF *sumLeftLabel;
	//�ұ������ܺͱ�ǩ
	CCLabelTTF *sumRightLabel;
	//��¼����ʱ��ı�ǩ
	CCLabelTTF *totalTimeLabel;
	
};
#endif 
