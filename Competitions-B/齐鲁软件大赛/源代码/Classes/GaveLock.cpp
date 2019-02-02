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
			//根据物体的种类不同来获得杠杆相应的范围。
			case 1:m=CCSprite::create(CCString::createWithFormat("monster%d.png",kind)->getCString());
				break;
			case 2:m=CCSprite::create(CCString::createWithFormat("monster%d.png",kind)->getCString());
				break;
			case 3:m=CCSprite::create(CCString::createWithFormat("monster%d.png",kind)->getCString());
				break;
				//m=CCSprite::create("monster.png");break;
		}
		CCSize size=m->getContentSize();
		//因为物体时刻在旋转，所以物体的范围判断应该使用这种方式.
		CCPoint point=getSprite()->boundingBox().origin;
		return CCRectMake(point.x,point.y,getSprite()->boundingBox().size.width,getSprite()->boundingBox().size.height+size.width/4);
	}
}
