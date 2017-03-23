#pragma once

#include "space/Core.h"
#include "KeycodeListener.h"

namespace Space
{
	class PlayerCore :public Core,public KeycodeListener
	{
	public:
		PlayerCore(SpaceEntity* entity);
		~PlayerCore();
		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
		void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);
	};
}
