#include "BKLayer.h"
#include "SimpleAudioEngine.h"
#include "base/CCDirector.h"
#include "2d/CCSprite.h"
#include "base/CCEventListenerKeyboard.h"
#include "base/CCEventKeyboard.h"
#include "base/CCEventDispatcher.h"

bool Space::BKLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	//////////////////////////////////////////////////////////////////////////

	cocos2d::Sprite* bk = cocos2d::Sprite::create("bk.png");
	bk->setScale(1.5);
	this->addChild(bk);
	bk->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2);


	//////////////////////////////////////////////////////////////////////////

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		this->handleKeyPressed(keyCode);
		//Player::getInstance()->handleKeyPressed(keyCode);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}


void Space::BKLayer::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{

}
