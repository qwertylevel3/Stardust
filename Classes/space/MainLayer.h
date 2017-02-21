#pragma once

#include "2d/CCLayer.h"

namespace Space
{
	class SpaceCraft;

	class MainLayer :public cocos2d::Layer
	{
	public:
		MainLayer();
		~MainLayer();
		bool init();

		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
		void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);

		CREATE_FUNC(MainLayer);
	protected:
		SpaceCraft* player;
	};
}
