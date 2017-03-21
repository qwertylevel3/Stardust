#include "PlayerController.h"

Space::PlayerController::PlayerController()
{
}

Space::PlayerController::~PlayerController()
{
}

void Space::PlayerController::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	Command c;

	c.keyCode = keyCode;
	c.press = true;
	commandQueue.push_back(c);
}

void Space::PlayerController::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	Command c;
	c.keyCode = keyCode;
	c.press = false;
	commandQueue.push_back(c);
}
