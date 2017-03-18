#pragma once

#include "SpaceEntity.h"
#include <vector>

namespace Space
{
	class SpaceShip :public SpaceEntity
	{
	public:
		SpaceShip();
		~SpaceShip();
		bool init();

		CREATE_FUNC(SpaceShip);

		void moveUpOn();
		void moveUpOff();
		void moveDownOn();
		void moveDownOff();
		void moveLeftOn();
		void moveLeftOff();
		void moveRightOn();
		void moveRightOff();

		void engineSwitch(bool b);
		void rudderLeftSwitch(bool b);
		void rudderRightSwitch(bool b);

		void update(float delta);
	protected:
		void accelerate();
		void decelerate();
		void rotateLeft();
		void rotateRight();

		CC_SYNTHESIZE(int, maxSpeed, MaxSpeed);
		CC_SYNTHESIZE(int, power, Power);
		CC_SYNTHESIZE(float, sensitivity, Sensitivity);

		bool accelerator;
		bool rudderLeft;
		bool rudderRight;
		
		bool moveUpFlag{ false };
		bool moveDownFlag{ false };
		bool moveLeftFlag{ false };
		bool moveRightFlag{ false };
	};
}
