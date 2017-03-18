#include "BKLayer.h"
#include "SimpleAudioEngine.h"
#include "base/CCDirector.h"
#include "2d/CCSprite.h"
#include "renderer/CCTexture2D.h"

bool Space::BKLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	//////////////////////////////////////////////////////////////////////////

	cocos2d::Sprite* bk = cocos2d::Sprite::create("space/bk.png");
	//bk->setScale(1.5);
	this->addChild(bk);
	cocos2d::Texture2D::TexParams tp = { GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT };// 主要用到的是这个，水平重复平铺，垂直重复平铺
	bk->getTexture()->setTexParameters(&tp);
	bk->setTextureRect(cocos2d::Rect(0, 0, 1000000, 1000000));
	bk->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2);



    return true;
}

void Space::BKLayer::update(float delta)
{

}

