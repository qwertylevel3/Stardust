#pragma once

#include "Singleton.h"



namespace Space
{
	class MainLayer;
	class SpaceEntity;

	class EntityFactory :public Singleton<EntityFactory>
	{
	public:
		EntityFactory();
		~EntityFactory();
		void createPlayer(MainLayer* layer);
		void createTestEnemy(MainLayer* layer);
	protected:
		void createEntityPhy(MainLayer* layer, SpaceEntity* entity);
	};
}
