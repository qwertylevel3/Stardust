#include "SpaceCraft.h"
#include "base/ccMacros.h"
#include "base/CCDirector.h"
#include "2d/CCCamera.h"
#include "Box2D/Box2D.h"

Space::SpaceCraft::SpaceCraft()
{
	this->scheduleUpdate();
	accelerator = false;
	rudderLeft = false;
	rudderRight = false;
	maxSpeed = 15;
	power = 10;
	sensitivity = 1.0;
}

Space::SpaceCraft::~SpaceCraft()
{
}

bool Space::SpaceCraft::init()
{
	if (!cocos2d::Sprite::init())
	{
		return false;
	}

	this->initWithFile("space/testShip.png");
	return true;
}

void Space::SpaceCraft::engineSwitch(bool b)
{
	accelerator = b;
}

void Space::SpaceCraft::rudderLeftSwitch(bool b)
{
	rudderLeft = b;
}

void Space::SpaceCraft::rudderRightSwitch(bool b)
{
	rudderRight = b;
}

void Space::SpaceCraft::accelerate()
{
	//	float angle = this->getRotation();

	float angle = body->GetAngle();
	cocos2d::Vec2 temp(0, 1);
	temp.scale(power);
	temp = temp.rotateByAngle(cocos2d::Vec2(0, 0), angle);

	b2Vec2 tempVec(temp.x, temp.y);
	body->ApplyForce(tempVec, body->GetPosition(), true);
}

void Space::SpaceCraft::decelerate()
{
	float angle = body->GetAngle();
	cocos2d::Vec2 temp(0, -1);
	temp.scale(power);
	temp = temp.rotateByAngle(this->getPosition(), angle);

	b2Vec2 tempVec(temp.x, temp.y);
	body->ApplyForce(tempVec, body->GetPosition(), true);

	//	this->getPhysicsBody()->applyForce(temp);
}

void Space::SpaceCraft::rotateLeft()
{
	//	this->setRotation(this->getRotation() - sensitivity);
	body->SetAngularVelocity(sensitivity);
	//	body->SetFixedRotation(body->GetAngle() - sensitivity);
}

void Space::SpaceCraft::rotateRight()
{
	//	this->setRotation(this->getRotation() + sensitivity);
	//	body->SetFixedRotation(body->GetAngle() + sensitivity);
	body->SetAngularVelocity(-sensitivity);
}

void Space::SpaceCraft::update(float delta)
{
	if (accelerator)
	{
		accelerate();
	}
	if (rudderLeft || rudderRight)
	{
		if (rudderLeft)
		{
			rotateLeft();
		}
		if (rudderRight)
		{
			rotateRight();
		}
	}
	else
	{
		body->SetAngularVelocity(0);
	}

	cocos2d::Scene* scene = cocos2d::Director::getInstance()->getRunningScene();
	cocos2d::Camera* camera = scene->getDefaultCamera();

	camera->setPosition(this->getPosition());
//	camera->setRotation(body->GetAngle());
	camera->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
}