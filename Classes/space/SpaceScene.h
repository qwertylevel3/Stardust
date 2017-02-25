#pragma once

#include "2d/CCScene.h"

namespace Space
{
	class SpaceScene :public cocos2d::Scene
	{
	public:
		SpaceScene();
		~SpaceScene();
		bool init();
		void toggleDebug();

		void update(float delta);

		CREATE_FUNC(SpaceScene);
	protected:
		bool debugDraw;
		cocos2d::Layer* mainLayer;
	};
}
