#include "EntityFactory.h"

#include "base/CCDirector.h"

#include "SpaceEntity.h"
#include "MainLayer.h"
#include "PlayerCore.h"

#include "space/SpaceMarcos.h"

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
	entity->setCollisionSize(cocos2d::Size(10, 10));
	entity->setPosition(512, 100);
	cocos2d::RefPtr<Core> ptr(new PlayerCore(entity));

	entity->setCore(ptr);

	createEntityPhy(layer, entity);

	layer->addEneity(entity);
}

void Space::EntityFactory::createTestEnemy(MainLayer* layer)
{
	SpaceEntity* entity = SpaceEntity::create();
	entity->initWithFile("space/testShip2.png");
	entity->setPosition(512, 600);

	cocos2d::RefPtr<Core> ptr(new Core(entity));
	entity->setCore(ptr);

	entity->setCollisionSize(cocos2d::Size(20, 20));

	createEntityPhy(layer, entity);

	layer->addEneity(entity);
}

void Space::EntityFactory::createEntityPhy(MainLayer* layer, SpaceEntity* entity)
{
	b2World* phyWorld = layer->getPhyWorld();

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(
		entity->getPosition().x/PTM_RATIO,
		entity->getPosition().y/PTM_RATIO
	);
	b2Body *body = phyWorld->CreateBody(&bodyDef);

	b2PolygonShape collisionBox;
	collisionBox.SetAsBox(
		entity->getCollisionSize().width/PTM_RATIO,
		entity->getCollisionSize().height/PTM_RATIO
	);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &collisionBox;
	fixtureDef.density = 10;
	fixtureDef.friction = 0.3;
	fixtureDef.isSensor = true;
	body->CreateFixture(&fixtureDef);

	body->SetUserData(entity);
	entity->setBody(body);
}