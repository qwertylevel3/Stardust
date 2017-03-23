#include "ContactListener.h"

#include "space/SpaceEntity.h"


Space::ContactListener::ContactListener()
{
}


Space::ContactListener::~ContactListener()
{
}

void Space::ContactListener::BeginContact(b2Contact* contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();
	auto entityA = (SpaceEntity*)bodyA->GetUserData();
	auto entityB = (SpaceEntity*)bodyB->GetUserData();

	if (entityA != nullptr && entityB != nullptr)
	{
		entityA->setColor(cocos2d::Color3B::YELLOW);
		entityB->setColor(cocos2d::Color3B::YELLOW);

		entityA->setDead(true);
		entityB->setDead(true);
	}
}
