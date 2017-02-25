#pragma once

#include "SpaceEntity.h"

namespace Space
{
	class SpaceCraft :public SpaceEntity
	{
	public:
		SpaceCraft();
		~SpaceCraft();
		bool init();

		CREATE_FUNC(SpaceCraft);

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
	};
}
