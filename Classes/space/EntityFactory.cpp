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
	SpaceEntity* entity = SpaceEntity::create();
	entity->initWithFile("space/testShip.png");
//	entity->setPosition(origin.x + visibleSize.width / 2,
//		origin.y + visibleSize.height / 5);
	entity->setPosition(512, 100);
	entity->setController(cocos2d::RefPtr<EntityController>(new PlayerController()));

	entity->setCollisionSize(cocos2d::Size(10, 10));

	layer->addEneity(entity);
}

void Space::EntityFactory::createTestEnemy(MainLayer* layer)
{
	SpaceEntity* entity = SpaceEntity::create();
	entity->initWithFile("space/testShip2.png");
	entity->setPosition(512, 600);

	entity->setController(cocos2d::RefPtr<EntityController>(new EntityController()));
	entity->setCollisionSize(cocos2d::Size(20, 20));

	layer->addEneity(entity);
}