#pragma once

#include "2d/CCLayer.h"
#include "Box2D/Box2D.h"
#include "base/CCVector.h"

#define	PTM_RATIO 1


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


		CREATE_FUNC(MainLayer);
		void addEneity(SpaceEntity* entity);
		void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);
	protected:
		void initPhy();

		cocos2d::Vector<SpaceEntity*> allEntity;

		b2World* world;
		DebugDrawCommand command;
	};
}
