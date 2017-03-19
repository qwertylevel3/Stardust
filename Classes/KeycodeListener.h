#pragma once


#include "base/CCRef.h"
#include "base/CCEventKeyboard.h"

class KeycodeListener:public cocos2d::Ref
{
public:
	KeycodeListener();
	~KeycodeListener();
	virtual void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
	virtual void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);
};
