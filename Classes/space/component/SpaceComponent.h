#pragma once

#include "base/CCRef.h"

namespace Space
{
	class SpaceEntity;

	class SpaceComponent:public cocos2d::Ref
	{
	public:
		SpaceComponent(SpaceEntity* e);
		virtual ~SpaceComponent();
		virtual void update(float delta);
	protected:
		SpaceEntity* entity;
	};

}
