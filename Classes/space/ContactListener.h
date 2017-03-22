#pragma once

#include "Box2D/Box2D.h"

namespace Space
{
	class ContactListener :public b2ContactListener
	{
	public:
		ContactListener();
		~ContactListener();
		void BeginContact(b2Contact* contact);
	};
}
