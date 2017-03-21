#include "SpaceEntity.h"
#include "physics/CCPhysicsBody.h"
#include "EntityController.h"



Space::SpaceEntity::SpaceEntity()
	:body(nullptr),core(this)
{

}


Space::SpaceEntity::~SpaceEntity()
{
}

bool Space::SpaceEntity::init()
{
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
	controller->update();
	core.update(delta);
	controller->clearCommandQueue();

}

void Space::SpaceEntity::setController(cocos2d::RefPtr<EntityController> p)
{
	controller = p;
}

cocos2d::RefPtr<Space::EntityController> Space::SpaceEntity::getController()
{
	return controller;
}
