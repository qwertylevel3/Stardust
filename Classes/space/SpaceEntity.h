#pragma once

#include "2d/CCSprite.h"
#include "Box2D/Box2D.h"

namespace Space
{
	class SpaceEntity:public cocos2d::Sprite
	{
	public:
		SpaceEntity();
		~SpaceEntity();
		bool init();
		void setBody(b2Body* b);
//		CREATE_FUNC(SpaceEntity);
	protected:
		b2Body* body;
	};
}
