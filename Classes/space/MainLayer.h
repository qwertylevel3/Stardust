#pragma once

#include "2d/CCLayer.h"
#include "Box2D/Box2D.h"

#define	PTM_RATIO 32


namespace Space
{
	class SpaceCraft;
	class SpaceEntity;

	class MainLayer :public cocos2d::Layer
	{
	public:
		MainLayer();
		~MainLayer();
		bool init();
		void update(float delta);

		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
		void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);

		CREATE_FUNC(MainLayer);
		void addEneity(SpaceEntity* entity);
	protected:
		void initPhy();
		SpaceCraft* player;
		b2World* world;
	};
}
