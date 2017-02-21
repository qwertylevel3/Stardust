#include "SpaceEntity.h"
#include "physics/CCPhysicsBody.h"



Space::SpaceEntity::SpaceEntity()
{

}


Space::SpaceEntity::~SpaceEntity()
{
}

bool Space::SpaceEntity::init()
{
	this->initWithFile("space/testShip.png");
	this->addComponent(cocos2d::PhysicsBody::createCircle(this->getContentSize().width / 2));
	return true;
}
