#include "SpaceShip.h"
#include "base/ccMacros.h"
#include "base/CCDirector.h"
#include "2d/CCCamera.h"
#include "Box2D/Box2D.h"

Space::SpaceShip::SpaceShip()
{
	this->scheduleUpdate();
}

Space::SpaceShip::~SpaceShip()
{
}

bool Space::SpaceShip::init()
{
	if (!cocos2d::Sprite::init())
	{
		return false;
	}

	this->initWithFile("space/testShip.png");
	return true;
}

void Space::SpaceShip::moveUpOn()
{
	moveUpFlag = true;
}

void Space::SpaceShip::moveUpOff()
{
	moveUpFlag = false;
}

void Space::SpaceShip::moveDownOn()
{
	moveDownFlag = true;
}

void Space::SpaceShip::moveDownOff()
{
	moveDownFlag = false;
}

void Space::SpaceShip::moveLeftOn()
{
	moveLeftFlag = true;
}

void Space::SpaceShip::moveLeftOff()
{
	moveLeftFlag = false;
}

void Space::SpaceShip::moveRightOn()
{
	moveRightFlag = true;
}

void Space::SpaceShip::moveRightOff()
{
	moveRightFlag = false;
}

void Space::SpaceShip::update(float delta)
{

	b2Vec2 v(0, 0);

	if (moveUpFlag)
	{
		v += b2Vec2(0, 10);
	}
	if (moveDownFlag)
	{
		v += b2Vec2(0, -10);
	}

	if (moveRightFlag)
	{
		v += b2Vec2(10, 0);
	}

	if (moveLeftFlag)
	{
		v += b2Vec2(-10, 0);
	}

	body->SetLinearVelocity(v);


//	if (accelerator)
//	{
//		accelerate();
//	}
//	if (rudderLeft || rudderRight)
//	{
//		if (rudderLeft)
//		{
//			rotateLeft();
//		}
//		if (rudderRight)
//		{
//			rotateRight();
//		}
//	}
//	else
//	{
//		body->SetAngularVelocity(0);
//	}

//	cocos2d::Scene* scene = cocos2d::Director::getInstance()->getRunningScene();
//	cocos2d::Camera* camera = scene->getDefaultCamera();

//	camera->setPosition(this->getPosition());
//	camera->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
}