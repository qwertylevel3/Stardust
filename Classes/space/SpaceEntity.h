#pragma once

#include "2d/CCSprite.h"

namespace Space
{
	class SpaceEntity:public cocos2d::Sprite
	{
	public:
		SpaceEntity();
		~SpaceEntity();
		bool init();
//		CREATE_FUNC(SpaceEntity);

	protected:

		
	};
}
