#include "Core.h"
#include "SpaceComponent.h"



Space::Core::Core(SpaceEntity* e)
	:entity(e)
{
	cocos2d::RefPtr<SpaceComponent> ptr(new Engine(e));
	componentBox.pushBack(ptr);
}


Space::Core::~Core()
{
}

void Space::Core::update(float delta)
{
	for each (cocos2d::RefPtr<SpaceComponent> ptr in componentBox)
	{
		ptr->update(delta);
	}
}

void Space::Core::handleKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	for each (cocos2d::RefPtr<SpaceComponent> ptr in componentBox)
	{
		ptr->handleKeyPressed(keyCode);
	}
}

void Space::Core::handleKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	for each (cocos2d::RefPtr<SpaceComponent> ptr in componentBox)
	{
		ptr->handleKeyReleased(keyCode);
	}
}
