#include "MainLayer.h"
#include "SpaceCraft.h"
#include "base/CCDirector.h"
#include "base/CCEventListenerKeyboard.h"
#include "base/CCEventKeyboard.h"
#include "base/CCEventDispatcher.h"

Space::MainLayer::MainLayer()
{
}

Space::MainLayer::~MainLayer()
{
	CC_SAFE_DELETE(world);
}

bool Space::MainLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initPhy();

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	//////////////////////////////////////////////////////////////////////////
	cocos2d::Sprite* bk = cocos2d::Sprite::create("space/bk.png");
	//bk->setScale(1.5);
	this->addChild(bk);
	cocos2d::Texture2D::TexParams tp = { GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT };// 主要用到的是这个，水平重复平铺，垂直重复平铺
	bk->getTexture()->setTexParameters(&tp);
	bk->setTextureRect(cocos2d::Rect(0, 0, 1000000, 1000000));
	bk->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2);

	player = SpaceCraft::create();
	player->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2);

	this->addEneity(player);

	//////////////////////////////////////////////////////////////////////////
	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		this->handleKeyPressed(keyCode);
		//Player::getInstance()->handleKeyPressed(keyCode);
	};
	listener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		this->handleKeyReleased(keyCode);
		//Player::getInstance()->handleKeyPressed(keyCode);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//	this->scheduleUpdate();

	return true;
}

void Space::MainLayer::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	static int count = 0;
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		player->engineSwitch(true);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		player->rudderLeftSwitch(true);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		player->rudderRightSwitch(true);
	}
}

void Space::MainLayer::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		player->engineSwitch(false);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		player->rudderLeftSwitch(false);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		player->rudderRightSwitch(false);
	}
}

void Space::MainLayer::update(float delta)
{
//	cocos2d::Point playerPosition = player->getPosition();
//	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
//	cocos2d::Size winSize = cocos2d::Director::getInstance()->getWinSize();

//	this->setPosition(
//		-(playerPosition.x - winSize.width / 2),
//		-(playerPosition.y - winSize.height / 2)
//	);
	//////////////////////////////////////////////////////////////////////////

	float timeStep = 0.03f;
	int32 velocityIterations = 8;
	int32 positionIterations = 1;

	world->Step(timeStep, velocityIterations, positionIterations);

	for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())                       
	{
		if (b->GetUserData() != nullptr) {
			cocos2d::Sprite* sprite = (cocos2d::Sprite*)b->GetUserData();
			sprite->setPosition(cocos2d::Vec2(b->GetPosition().x *
				PTM_RATIO, b->GetPosition().y * PTM_RATIO));
			sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
		}
	}
}

void Space::MainLayer::initPhy()
{
	cocos2d::Size s = cocos2d::Director::getInstance()->getVisibleSize();

	//重力参数
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);
	//创建世界
	world = new b2World(gravity);
	// 允许物体是否休眠
	world->SetAllowSleeping(true);
	// 开启连续物理测试
	world->SetContinuousPhysics(true);
}

void Space::MainLayer::addEneity(SpaceEntity* entity)
{
	this->addChild(entity);

	cocos2d::Point position = entity->getPosition();

	//物体定义
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x / PTM_RATIO, position.y / PTM_RATIO);
	b2Body *body = world->CreateBody(&bodyDef);
	
	body->SetUserData(entity);
	entity->setBody(body);

	// 定义2米见方的盒子形状
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1, 1);

	// 夹具定义
	b2FixtureDef fixtureDef;
	//设置夹具的形状
	fixtureDef.shape = &dynamicBox;
	//设置密度
	fixtureDef.density = 1.0f;
	//设置摩擦系数
	fixtureDef.friction = 0.3f;
	//使用夹具固定形状到物体上
	body->CreateFixture(&fixtureDef);
}