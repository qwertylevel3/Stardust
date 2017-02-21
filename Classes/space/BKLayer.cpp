#include "BKLayer.h"
#include "SimpleAudioEngine.h"
#include "base/CCDirector.h"
#include "2d/CCSprite.h"

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



    return true;
}

