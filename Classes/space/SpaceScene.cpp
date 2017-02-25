#include "SpaceScene.h"
#include "2d/CCCamera.h"
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

	this->scheduleUpdate();
	mainLayer = MainLayer::create();
	addChild(mainLayer,MainLayerZOrder);
	return true;
}

void Space::SpaceScene::update(float delta)
{
	mainLayer->update(delta);
}
