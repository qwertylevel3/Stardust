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
