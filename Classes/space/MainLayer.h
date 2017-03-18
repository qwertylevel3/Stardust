#pragma once

#include "2d/CCLayer.h"
#include "Box2D/Box2D.h"

#define	PTM_RATIO 32


namespace Space
{
	class SpaceShip;
	class SpaceEntity;

	//////////////////////////////////////////////////////////////////////////
	//DebugDrawCommand
	//////////////////////////////////////////////////////////////////////////

	class DebugDrawCommand :public cocos2d::CustomCommand
	{
	public:
		static void draw(DebugDrawCommand* command);
		DebugDrawCommand();
		void setWorld(b2World* w) { world = w; }
		void init(float globalZOrder);
	private:
		b2World* world;
	};


	//////////////////////////////////////////////////////////////////////////
	//MainLayer
	//////////////////////////////////////////////////////////////////////////

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
		void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);
	protected:
		void initPhy();
		void debugDraw();
		SpaceShip* player;
		b2World* world;
		DebugDrawCommand command;
	};
}
