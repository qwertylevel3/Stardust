#include "ContactListener.h"

#include "2d/CCSprite.h"


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
	auto spriteA = (cocos2d::Sprite*)bodyA->GetUserData();
	auto spriteB = (cocos2d::Sprite*)bodyB->GetUserData();

	if (spriteA != nullptr && spriteB != nullptr)
	{
		spriteA->setColor(cocos2d::Color3B::YELLOW);
		spriteB->setColor(cocos2d::Color3B::YELLOW);
	}
}
