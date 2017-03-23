#include "MainLayer.h"
#include <functional>
#include "base/CCDirector.h"
#include "base/CCEventListenerKeyboard.h"
#include "base/CCEventKeyboard.h"
#include "base/CCEventDispatcher.h"

#include "GLES-Render.h"
#include "SpaceEntity.h"
#include "EntityFactory.h"
#include "space/ContactListener.h"
#include "space/SpaceMarcos.h"

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
	CC_SAFE_DELETE(contactListener);
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
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 10;
	int32 positionIterations = 10;

	world->Step(timeStep, velocityIterations, positionIterations);

	std::vector<SpaceEntity*>::iterator iter = allEntity.begin();

	while (iter != allEntity.end())
	{
		(*iter)->update(delta);

		if ((*iter)->isDead())
		{
			world->DestroyBody((*iter)->getBody());

			(*iter)->removeFromParent();
			iter = allEntity.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void Space::MainLayer::initPhy()
{
	cocos2d::Size s = cocos2d::Director::getInstance()->getVisibleSize();

	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);

	world = new b2World(gravity);
	world->SetAllowSleeping(true);
	world->SetContinuousPhysics(true);

	auto debugDrawFlag = new GLESDebugDraw(PTM_RATIO);   //这里新建一个 debug渲染模块

	world->SetDebugDraw(debugDrawFlag);
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	debugDrawFlag->SetFlags(flags);

	contactListener = new ContactListener();
	world->SetContactListener(contactListener);
}

void Space::MainLayer::addEneity(SpaceEntity* entity)
{
	this->addChild(entity);
	allEntity.push_back(entity);
}

void Space::MainLayer::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags)
{
	enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);

	command.init(_globalZOrder);
	command.setWorld(world);
	renderer->addCommand(&command);

	CHECK_GL_ERROR_DEBUG();
}