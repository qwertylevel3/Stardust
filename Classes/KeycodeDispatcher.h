#pragma once

#include "2d/CCNode.h"
#include "base/CCVector.h"
#include "base/CCRefPtr.h"

#include "Singleton.h"

class KeycodeListener;

class KeycodeDispatcher :public cocos2d::Node,public Singleton<KeycodeDispatcher>
{
public:
	KeycodeDispatcher();
	~KeycodeDispatcher();
	bool init();
	void addLinster(KeycodeListener* listener);
	void handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
	void handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);

	CREATE_FUNC(KeycodeDispatcher);
protected:
	cocos2d::Vector<cocos2d::RefPtr<KeycodeListener> > allListener;
};
