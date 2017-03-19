#pragma once

#include "2d/CCSprite.h"
#include "Box2D/Box2D.h"


#include "Core.h"

namespace Space
{
	class SpaceEntity:public cocos2d::Sprite
	{
	public:
		SpaceEntity();
		~SpaceEntity();
		CREATE_FUNC(SpaceEntity);

		bool init();
		void setBody(b2Body* b);
	    void SetLinearVelocity(b2Vec2 v);
		void update(float delta);
	protected:
		Core core;
		b2Body* body;
	};
}
