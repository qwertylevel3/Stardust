#include "Engine.h"
#include "Box2D/Common/b2Math.h"
#include "space/SpaceEntity.h"
#include "space/SpaceMarcos.h"



Space::Engine::Engine(SpaceEntity* e)
	:SpaceComponent(e)
	,speed(10)
{

}

Space::Engine::~Engine()
{

}

void Space::Engine::setSpeed(int s)
{
	speed = s;
}

int Space::Engine::getSpeed()
{
	return speed;
}

void Space::Engine::handleCommand()
{
	std::vector<Command>& commandQueue = entity->getCore()->getCommandQueueRef();

	for (int i=0;i<commandQueue.size();i++)
	{
		handleCommand(commandQueue[i]);
	}
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
	handleCommand();

	b2Vec2 v(0, 0);

	if (moveUpFlag)
	{
		v += b2Vec2(0, speed);
	}
	if (moveDownFlag)
	{
		v += b2Vec2(0, -speed);
	}
	if (moveRightFlag)
	{
		v += b2Vec2(speed, 0);
	}
	if (moveLeftFlag)
	{
		v += b2Vec2(-speed, 0);
	}


//	cocos2d::Vec2 position = entity->getPosition();
//	entity->setPosition(
//		position.x+=v.x,
//		position.y+=v.y
//	);

	b2Body* body = entity->getBody();
	b2Vec2 tv = body->GetLinearVelocity();
	if (abs(tv.x-v.x)<0.1 && abs(tv.y-v.y)<0.1)
	{
		return;
	}
	body->SetLinearVelocity(v);
}

void Space::Engine::handleCommand(const Command& c)
{
	if (c.press)
	{
		handleKeyPressed(c.keyCode);
	}
	else
	{
		handleKeyReleased(c.keyCode);
	}
}
