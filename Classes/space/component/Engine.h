#pragma once


#include "SpaceComponent.h"
#include "KeycodeListener.h"

namespace Space
{

	class Engine :public SpaceComponent,public KeycodeListener
	{
	public:
		Engine(SpaceEntity* e);
		~Engine();
		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
		void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);
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
		bool moveUpFlag{ false };
		bool moveDownFlag{ false };
		bool moveLeftFlag{ false };
		bool moveRightFlag{ false };
	
	};
}
