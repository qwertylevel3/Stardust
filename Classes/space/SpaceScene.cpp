#include "SpaceScene.h"
#include "physics/CCPhysicsWorld.h"
#include "BKLayer.h"
#include "MainLayer.h"



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
	addChild(BKLayer::create(),0);


	addChild(MainLayer::create(),1);
	return true;
}

void Space::SpaceScene::toggleDebug()
{
#if CC_USE_PHYSICS
	debugDraw = !debugDraw;
	_physicsWorld->setDebugDrawMask(debugDraw ? cocos2d::PhysicsWorld::DEBUGDRAW_ALL : cocos2d::PhysicsWorld::DEBUGDRAW_NONE);
#endif
}
