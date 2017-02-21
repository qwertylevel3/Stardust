#include "SpaceCraft.h"



Space::SpaceCraft::SpaceCraft()
{
	this->scheduleUpdate();
	accelerator = false;
	rudderLeft = false;
	rudderRight = false;
	maxSpeed = 15;
	power = 100000;
	sensitivity = 5;
}


Space::SpaceCraft::~SpaceCraft()
{
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
	float angle=this->getRotation();
	cocos2d::Vec2 temp(0, 1);
	temp.scale(power);
	temp.rotateByAngle(this->getPosition(),-angle);

	this->getPhysicsBody()->applyForce(temp);
}

void Space::SpaceCraft::decelerate()
{
	float angle=this->getRotation();
	cocos2d::Vec2 temp(0, -1);
	temp.scale(power);
	temp.rotateByAngle(this->getPosition(),-angle);

	this->getPhysicsBody()->applyForce(temp);
}

void Space::SpaceCraft::rotateLeft()
{
	this->setRotation(this->getRotation() - sensitivity);
}

void Space::SpaceCraft::rotateRight()
{
	this->setRotation(this->getRotation() + sensitivity);
}

void Space::SpaceCraft::update(float delta)
{
	if (accelerator)
	{
		accelerate();
	}
	if (rudderLeft)
	{
		rotateLeft();
	}
	if (rudderRight)
	{
		rotateRight();
	}
}
