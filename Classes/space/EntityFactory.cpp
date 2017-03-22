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
	entity->setCollisionSize(cocos2d::Size(10, 10));
	entity->setPosition(512, 100);
	entity->setController(cocos2d::RefPtr<EntityController>(new PlayerController()));

	createEntityPhy(layer, entity);

	layer->addEneity(entity);
}

void Space::EntityFactory::createTestEnemy(MainLayer* layer)
{
	SpaceEntity* entity = SpaceEntity::create();
	entity->initWithFile("space/testShip2.png");
	entity->setPosition(512, 600);
	entity->setController(cocos2d::RefPtr<EntityController>(new EntityController()));
	entity->setCollisionSize(cocos2d::Size(20, 20));

	createEntityPhy(layer, entity);

	layer->addEneity(entity);
}

void Space::EntityFactory::createEntityPhy(MainLayer* layer, SpaceEntity* entity)
{
	b2World* phyWorld = layer->getPhyWorld();

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(entity->getPosition().x
		, entity->getPosition().y);
	b2Body *body = phyWorld->CreateBody(&bodyDef);

	body->SetUserData(entity);
	entity->setBody(body);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(
		entity->getCollisionSize().width,
		entity->getCollisionSize().height
	);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
}
