#include "SpaceEntity.h"
#include "physics/CCPhysicsBody.h"



Space::SpaceEntity::SpaceEntity()
	:body(nullptr)
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
