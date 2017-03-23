#include "SpaceEntity.h"
#include "physics/CCPhysicsBody.h"
#include "space/SpaceMarcos.h"

Space::SpaceEntity::SpaceEntity()
	:body(nullptr), core(nullptr)
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
	core->update(delta);

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
	core->clearCommandQueue();
}


void Space::SpaceEntity::setCollisionSize(cocos2d::Size s)
{
	collisionSize = s;
}

cocos2d::Size Space::SpaceEntity::getCollisionSize()
{
	return collisionSize;
}

cocos2d::RefPtr<Space::Core> Space::SpaceEntity::getCore()
{
	return core;
}

void Space::SpaceEntity::setCore(cocos2d::RefPtr<Core> c)
{
	core = c;
}
