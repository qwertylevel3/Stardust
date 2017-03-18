#include "SpaceShip.h"
#include "base/ccMacros.h"
#include "base/CCDirector.h"
#include "2d/CCCamera.h"
#include "Box2D/Box2D.h"

Space::SpaceShip::SpaceShip()
{
	this->scheduleUpdate();
	accelerator = false;
	rudderLeft = false;
	rudderRight = false;
	maxSpeed = 15;
	power = 10;
	sensitivity = 1.0;
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

void Space::SpaceShip::engineSwitch(bool b)
{
	accelerator = b;
}

void Space::SpaceShip::rudderLeftSwitch(bool b)
{
	rudderLeft = b;
}

void Space::SpaceShip::rudderRightSwitch(bool b)
{
	rudderRight = b;
}

void Space::SpaceShip::accelerate()
{
	//	float angle = this->getRotation();

	float angle = body->GetAngle();
	cocos2d::Vec2 temp(0, 1);
	temp.scale(power);
	temp = temp.rotateByAngle(cocos2d::Vec2(0, 0), angle);

	b2Vec2 tempVec(temp.x, temp.y);
	body->ApplyForce(tempVec, body->GetPosition(), true);
}

void Space::SpaceShip::decelerate()
{
	float angle = body->GetAngle();
	cocos2d::Vec2 temp(0, -1);
	temp.scale(power);
	temp = temp.rotateByAngle(this->getPosition(), angle);

	b2Vec2 tempVec(temp.x, temp.y);
	body->ApplyForce(tempVec, body->GetPosition(), true);

	//	this->getPhysicsBody()->applyForce(temp);
}

void Space::SpaceShip::rotateLeft()
{
	//	this->setRotation(this->getRotation() - sensitivity);
	body->SetAngularVelocity(sensitivity);
	//	body->SetFixedRotation(body->GetAngle() - sensitivity);
}

void Space::SpaceShip::rotateRight()
{
	//	this->setRotation(this->getRotation() + sensitivity);
	//	body->SetFixedRotation(body->GetAngle() + sensitivity);
	body->SetAngularVelocity(-sensitivity);
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