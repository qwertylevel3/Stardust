#include "Core.h"
#include "space/component/SpaceComponent.h"



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

