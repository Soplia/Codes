#include "Entity.h"
Entity::Entity()
{
	this->mySprite=NULL;
}
Entity::~Entity()
{
}
CCSprite *Entity::getSprite()
{
	return this->mySprite;
}
void Entity::bindSprite(CCSprite *s)
{
	this->mySprite=s;
	this->addChild(mySprite,1);
}