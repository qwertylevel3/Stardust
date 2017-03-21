#pragma once

#include "base/CCEventKeyboard.h"
#include <vector>
#include "base/CCRef.h"

namespace Space
{
	struct Command
	{
		cocos2d::EventKeyboard::KeyCode keyCode;
		bool press;
	};
	class EntityController:public cocos2d::Ref
	{
	public:
		EntityController();
		~EntityController();
		virtual void update();
		void clearCommandQueue();
		std::vector<Command>& getCommandQueueRef();
	protected:
		std::vector<Command> commandQueue;
	};

}
