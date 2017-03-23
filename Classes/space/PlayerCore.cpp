#include "PlayerCore.h"

Space::PlayerCore::PlayerCore(SpaceEntity* entity)
	:Core(entity)
{

}

Space::PlayerCore::~PlayerCore()
{
}

void Space::PlayerCore::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	Command c;

	c.keyCode = keyCode;
	c.press = true;
	commandQueue.push_back(c);
}

void Space::PlayerCore::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	Command c;
	c.keyCode = keyCode;
	c.press = false;
	commandQueue.push_back(c);
}
