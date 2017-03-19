#pragma once


#include "base/CCVector.h"
#include "base/CCRefPtr.h"
#include "base/CCEventKeyboard.h"


namespace Space
{

	class SpaceComponent;
	class SpaceEntity;

	class Core
	{
	public:
		Core(SpaceEntity* e);
		~Core();
		void update(float delta);
	protected:
		cocos2d::Vector<cocos2d::RefPtr<SpaceComponent> > componentBox;
		SpaceEntity* entity;
	};
}
