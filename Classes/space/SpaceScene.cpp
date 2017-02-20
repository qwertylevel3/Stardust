#include "SpaceScene.h"
#include "physics/CCPhysicsWorld.h"
#include "BKLayer.h"



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
	addChild(BKLayer::create());
	return true;
}

void Space::SpaceScene::toggleDebug()
{
#if CC_USE_PHYSICS
	debugDraw = !debugDraw;
	_physicsWorld->setDebugDrawMask(debugDraw ? cocos2d::PhysicsWorld::DEBUGDRAW_ALL : cocos2d::PhysicsWorld::DEBUGDRAW_NONE);
#endif
}
