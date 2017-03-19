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

		void update(float delta);
	protected:
		bool moveUpFlag{ false };
		bool moveDownFlag{ false };
		bool moveLeftFlag{ false };
		bool moveRightFlag{ false };
	};
}
