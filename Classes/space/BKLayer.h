#pragma once

#include "2d/CCLayer.h"

namespace Space
{
	class BKLayer : public cocos2d::Layer
	{
	public:
		virtual bool init();

		void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

		// implement the "static create()" method manually
		CREATE_FUNC(BKLayer);
	protected:
	};
}
