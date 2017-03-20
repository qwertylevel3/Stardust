#include "MainLayer.h"
#include <functional>
#include "base/CCDirector.h"
#include "base/CCEventListenerKeyboard.h"
#include "base/CCEventKeyboard.h"
#include "base/CCEventDispatcher.h"

#include "GLES-Render.h"
#include "SpaceEntity.h"
#include "EntityFactory.h"

//////////////////////////////////////////////////////////////////////////
//DebugDrawCommand
//////////////////////////////////////////////////////////////////////////

Space::DebugDrawCommand::DebugDrawCommand()
{
}

void Space::DebugDrawCommand::init(float globalZOrder)
{
	CustomCommand::init(globalZOrder);
	func = std::bind(draw, this);
}

void Space::DebugDrawCommand::draw(DebugDrawCommand* command)
{
	command->world->DrawDebugData();
}

//////////////////////////////////////////////////////////////////////////
//MainLayer
//////////////////////////////////////////////////////////////////////////

Space::MainLayer::MainLayer()
{
	world = nullptr;
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

	EntityFactory::getInstance()->createPlayer(this);
	EntityFactory::getInstance()->createTestEnemy(this);

	return true;
}

void Space::MainLayer::update(float delta)
{
	for each (SpaceEntity* entity in allEntity)
	{
		entity->update(delta);
	}

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

	auto debugDrawFlag = new GLESDebugDraw(PTM_RATIO);   //这里新建一个 debug渲染模块

	world->SetDebugDraw(debugDrawFlag);
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	debugDrawFlag->SetFlags(flags);
}

void Space::MainLayer::addEneity(SpaceEntity* entity)
{
	this->addChild(entity);
	allEntity.pushBack(entity);

	cocos2d::Point position = entity->getPosition();

	//物体定义
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x / PTM_RATIO, position.y / PTM_RATIO);
	b2Body *body = world->CreateBody(&bodyDef);

	body->SetUserData(entity);
	entity->setBody(body);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(entity->getContentSize().width, entity->getContentSize().height);

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

void Space::MainLayer::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags)
{
	enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);

	command.init(_globalZOrder);
	command.setWorld(world);
	renderer->addCommand(&command);

	CHECK_GL_ERROR_DEBUG();
}