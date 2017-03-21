#pragma once


#include "SpaceComponent.h"

#include "space/EntityController.h"

namespace Space
{
	class Engine :public SpaceComponent
	{
	public:
		Engine(SpaceEntity* e);
		~Engine();
		void setSpeed(int s);
		int getSpeed();
		void handleCommand();

		void update(float delta);

		void moveUpOn() { moveUpFlag = true; };
		void moveUpOff() { moveUpFlag = false; };
		void moveDownOn() { moveDownFlag = true; };
		void moveDownOff() { moveDownFlag = false; };
		void moveLeftOn() { moveLeftFlag = true; };
		void moveLeftOff() { moveLeftFlag = false; };
		void moveRightOn() { moveRightFlag = true; };
		void moveRightOff() { moveRightFlag = false; };
	protected:
		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
		void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);
		void handleCommand(const Command& c);
		bool moveUpFlag{ false };
		bool moveDownFlag{ false };
		bool moveLeftFlag{ false };
		bool moveRightFlag{ false };

		int speed;
	};
}
