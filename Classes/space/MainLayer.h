#pragma once

#include "2d/CCLayer.h"

namespace Space
{
	class SpaceEntity;

	class MainLayer :public cocos2d::Layer
	{
	public:
		MainLayer();
		~MainLayer();
		bool init();

		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

		CREATE_FUNC(MainLayer);
	protected:
		SpaceEntity* player;
	};
}
