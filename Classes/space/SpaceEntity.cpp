#include "SpaceEntity.h"
#include "physics/CCPhysicsBody.h"
#include "EntityController.h"
#include "space/SpaceMarcos.h"

Space::SpaceEntity::SpaceEntity()
	:body(nullptr), core(this)
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


	if (body)
	{
		this->setPosition(
			cocos2d::Vec2(
				body->GetPosition().x*PTM_RATIO,
				body->GetPosition().y*PTM_RATIO
			)
		);
		this->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
	}
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

void Space::SpaceEntity::setCollisionSize(cocos2d::Size s)
{
	collisionSize = s;
}

cocos2d::Size Space::SpaceEntity::getCollisionSize()
{
	return collisionSize;
}