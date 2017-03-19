#include "EntityFactory.h"
#include "SpaceEntity.h"
#include "base/CCDirector.h"
#include "MainLayer.h"



Space::EntityFactory::EntityFactory()
{
}


Space::EntityFactory::~EntityFactory()
{
}

void Space::EntityFactory::createPlayer(Space::MainLayer* layer)
{
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	SpaceEntity* player = SpaceEntity::create();
	player->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2);

	layer->addEneity(player);
}


