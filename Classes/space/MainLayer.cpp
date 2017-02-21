#include "MainLayer.h"
#include "SpaceCraft.h"
#include "base/CCDirector.h"
#include "base/CCEventListenerKeyboard.h"
#include "base/CCEventKeyboard.h"
#include "base/CCEventDispatcher.h"





Space::MainLayer::MainLayer()
{
}


Space::MainLayer::~MainLayer()
{
}

bool Space::MainLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();



	//////////////////////////////////////////////////////////////////////////

	player = SpaceCraft::create();
	player->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2);

	this->addChild(player);


	//////////////////////////////////////////////////////////////////////////
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

void Space::MainLayer::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	static int count = 0;
	if (keyCode==cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		player->engineSwitch(true);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		player->rudderLeftSwitch(true);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		player->rudderRightSwitch(true);
	}
}

void Space::MainLayer::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode==cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		player->engineSwitch(false);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		player->rudderLeftSwitch(false);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		player->rudderRightSwitch(false);
	}

}
