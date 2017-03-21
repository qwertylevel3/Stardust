#include "EntityFactory.h"

#include "base/CCDirector.h"

#include "SpaceEntity.h"
#include "MainLayer.h"
#include "PlayerController.h"



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

	SpaceEntity* entity = SpaceEntity::create();
	entity->initWithFile("space/testShip.png");
	entity->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 5);
	entity->setController(cocos2d::RefPtr<EntityController>(new PlayerController()));

	layer->addEneity(entity);
}

void Space::EntityFactory::createTestEnemy(MainLayer* layer)
{
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	SpaceEntity* entity = SpaceEntity::create();
	entity->initWithFile("space/testShip2.png");
	entity->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height*4 / 5);

	entity->setController(cocos2d::RefPtr<EntityController>(new EntityController()));

	layer->addEneity(entity);
}

