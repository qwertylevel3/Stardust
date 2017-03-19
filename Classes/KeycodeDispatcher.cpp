#include "KeycodeDispatcher.h"
#include "base/CCEventListenerKeyboard.h"
#include "base/CCEventKeyboard.h"
#include "base/CCEventDispatcher.h"

#include "KeycodeListener.h"



KeycodeDispatcher::KeycodeDispatcher()
{
}


KeycodeDispatcher::~KeycodeDispatcher()
{
}

bool KeycodeDispatcher::init()
{
	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		this->handleKeyPressed(keyCode);
		//Player::getInstance()->handleKeyPressed(keyCode);
	};
	listener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		this->handleKeyReleased(keyCode);
		//Player::getInstance()->handleKeyPressed(keyCode);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void KeycodeDispatcher::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	for each (cocos2d::RefPtr<KeycodeListener> listener in allListener)
	{
		listener->handleKeyPressed(keyCode);
	}
}

void KeycodeDispatcher::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	for each (cocos2d::RefPtr<KeycodeListener> listener in allListener)
	{
		listener->handleKeyReleased(keyCode);
	}
}

void KeycodeDispatcher::addLinster(KeycodeListener* listener)
{
	cocos2d::RefPtr<KeycodeListener> ptr(listener);
	allListener.pushBack(ptr);
}

