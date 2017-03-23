#pragma once

#include "2d/CCSprite.h"
#include "Box2D/Box2D.h"


#include "Core.h"
#include "base/CCRefPtr.h"


namespace Space
{
	class EntityController;

	class SpaceEntity:public cocos2d::Sprite
	{
	public:
		enum Type 
		{
			SHIP,BULLET
		};
		SpaceEntity();
		~SpaceEntity();
		CREATE_FUNC(SpaceEntity);

		bool init();
		void setBody(b2Body* b);
		void setController(cocos2d::RefPtr<EntityController> p);
		void setCollisionSize(cocos2d::Size s);
		cocos2d::Size getCollisionSize();
		void setCore(cocos2d::RefPtr<Core> c);
		cocos2d::RefPtr<Core> getCore();
	    void SetLinearVelocity(b2Vec2 v);
		void update(float delta);
	protected:
		b2Body* body;
		cocos2d::RefPtr<Core> core;
		//Åö×²ºÐ´óÐ¡
		cocos2d::Size collisionSize;

		Type type;
	};
}
