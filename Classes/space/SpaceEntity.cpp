#include "SpaceEntity.h"
#include "physics/CCPhysicsBody.h"



Space::SpaceEntity::SpaceEntity()
	:body(nullptr),core(this)
{

}


Space::SpaceEntity::~SpaceEntity()
{
}

bool Space::SpaceEntity::init()
{
	this->initWithFile("space/testShip.png");
	return true;
}

void Space::SpaceEntity::setBody(b2Body* b)
{
	body = b;
}

void Space::SpaceEntity::SetLinearVelocity(b2Vec2 v)
{
	body->SetLinearVelocity(v);

}

void Space::SpaceEntity::update(float delta)
{
	core.update(delta);
}

void Space::SpaceEntity::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	core.handleKeyPressed(keyCode);
}

void Space::SpaceEntity::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	core.handleKeyReleased(keyCode);
}
