#pragma once


#include "base/CCVector.h"
#include "base/CCRefPtr.h"
#include "base/CCEventKeyboard.h"


namespace Space
{
	class SpaceComponent;
	class SpaceEntity;

	struct Command
	{
		cocos2d::EventKeyboard::KeyCode keyCode;
		bool press;
	};

	class Core:public cocos2d::Ref
	{
	public:
		Core(SpaceEntity* e);
		~Core();
		void update(float delta);
		void clearCommandQueue();
		std::vector<Command>& getCommandQueueRef();
	protected:
		cocos2d::Vector<cocos2d::RefPtr<SpaceComponent> > componentBox;
//		cocos2d::RefPtr<SpaceEntity> entity;

		SpaceEntity* entity;

		std::vector<Command> commandQueue;
	};
}
