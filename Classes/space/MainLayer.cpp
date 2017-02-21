#include "MainLayer.h"
#include "SpaceEntity.h"
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

	player = SpaceEntity::create();
	player->initWithFile("space/testShip.png");
	player->addComponent(cocos2d::PhysicsBody::createCircle(player->getContentSize().width / 2));
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
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Space::MainLayer::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode==cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		player->getPhysicsBody()->applyForce(cocos2d::Vec2(0,100000));
		//player->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 10));
		//player->getPhysicsBody()->applyImpulse(cocos2d::Vec2(0, 10000));
	}
}
