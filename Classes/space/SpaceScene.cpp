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
	bkLayer = BKLayer::create();

	addChild(bkLayer, BKLayerZOrder);
	addChild(mainLayer,MainLayerZOrder);
	return true;
}

void Space::SpaceScene::update(float delta)
{
	mainLayer->update(delta);
	bkLayer->update(delta);
}
