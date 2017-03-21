#pragma once

#include "space/EntityController.h"
#include "KeycodeListener.h"

namespace Space
{
	class PlayerController :public EntityController,public KeycodeListener
	{
	public:
		PlayerController();
		~PlayerController();
		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
		void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);
	};
}
