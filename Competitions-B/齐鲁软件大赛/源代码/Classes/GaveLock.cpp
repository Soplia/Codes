#include "GaveLock.h"
GaveLock::GaveLock()
{
}
GaveLock::~GaveLock()
{}

bool GaveLock::init()
{
	return true;
}

CCRect GaveLock::getBox(int kind)
{
	if(getSprite()==NULL)
		return CCRectMake(0,0,0,0);
	else
	{
		CCSprite *m;
		switch(kind)
		{
			//������������಻ͬ����øܸ���Ӧ�ķ�Χ��
			case 1:m=CCSprite::create(CCString::createWithFormat("monster%d.png",kind)->getCString());
				break;
			case 2:m=CCSprite::create(CCString::createWithFormat("monster%d.png",kind)->getCString());
				break;
			case 3:m=CCSprite::create(CCString::createWithFormat("monster%d.png",kind)->getCString());
				break;
				//m=CCSprite::create("monster.png");break;
		}
		CCSize size=m->getContentSize();
		//��Ϊ����ʱ������ת����������ķ�Χ�ж�Ӧ��ʹ�����ַ�ʽ.
		CCPoint point=getSprite()->boundingBox().origin;
		return CCRectMake(point.x,point.y,getSprite()->boundingBox().size.width,getSprite()->boundingBox().size.height+size.width/4);
	}
}
