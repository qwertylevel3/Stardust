#include "SpaceComponent.h"
#include "Box2D/Common/b2Math.h"
#include "space/SpaceEntity.h"



Space::SpaceComponent::SpaceComponent(SpaceEntity* e)
	:entity(e)
{
}


Space::SpaceComponent::~SpaceComponent()
{
}

void Space::SpaceComponent::update(float delta)
{

}

void Space::SpaceComponent::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{

}

void Space::SpaceComponent::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{

}

Space::Engine::Engine(SpaceEntity* e)
	:SpaceComponent(e)
{

}

Space::Engine::~Engine()
{

}

void Space::Engine::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		moveUpOn();
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		moveDownOn();
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		moveLeftOn();
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		moveRightOn();
	}
}

void Space::Engine::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		moveUpOff();
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		moveDownOff();
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		moveLeftOff();
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		moveRightOff();
	}
}

void Space::Engine::update(float delta)
{
	b2Vec2 v(0, 0);

	if (moveUpFlag)
	{
		v += b2Vec2(0, 10);
	}
	if (moveDownFlag)
	{
		v += b2Vec2(0, -10);
	}

	if (moveRightFlag)
	{
		v += b2Vec2(10, 0);
	}

	if (moveLeftFlag)
	{
		v += b2Vec2(-10, 0);
	}

	entity->SetLinearVelocity(v);
}
