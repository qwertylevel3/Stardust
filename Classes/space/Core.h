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
		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
		void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);
	protected:
		cocos2d::Vector<cocos2d::RefPtr<SpaceComponent> > componentBox;
		SpaceEntity* entity;
	};
}
