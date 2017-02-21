#include "SpaceScene.h"
#include "physics/CCPhysicsWorld.h"
#include "BKLayer.h"
#include "MainLayer.h"
#include "ZOrder.h"



Space::SpaceScene::SpaceScene()
{
}


Space::SpaceScene::~SpaceScene()
{
}

bool Space::SpaceScene::init()
{
	Scene::init();
	initWithPhysics();
	_physicsWorld->setGravity(cocos2d::Vec2(0, 0));
	addChild(BKLayer::create(),BKLayerZOrder);
	addChild(MainLayer::create(),MainLayerZOrder);
	return true;
}

void Space::SpaceScene::toggleDebug()
{
#if CC_USE_PHYSICS
	debugDraw = !debugDraw;
	_physicsWorld->setDebugDrawMask(debugDraw ? cocos2d::PhysicsWorld::DEBUGDRAW_ALL : cocos2d::PhysicsWorld::DEBUGDRAW_NONE);
#endif
}
