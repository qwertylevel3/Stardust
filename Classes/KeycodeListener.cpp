#include "KeycodeListener.h"
#include "KeycodeDispatcher.h"




KeycodeListener::KeycodeListener()
{
	KeycodeDispatcher::getInstance()->addLinster(this);
}

KeycodeListener::~KeycodeListener()
{
	KeycodeDispatcher::getInstance()->removeLinster(this);
}


void KeycodeListener::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{

}

void KeycodeListener::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{

}