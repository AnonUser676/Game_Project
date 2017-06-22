#pragma once
#include <vector>
#include "Entity.h"

class CollisionManager
{
public:
	static CollisionManager* getInstance();
	static void Create();
	static void Destroy();

	void addObject(Entity* pObject);
	void removeObject(Entity* pObject);

	Entity* TestCollisionSquare(Entity* pObject);
	Entity* TestCollisionCircle(Entity* pObject);
	Entity* TestCollision2Circle(Entity* pObject);

private:
	CollisionManager();
	~CollisionManager();

	static CollisionManager* m_instance;
	vector<Entity*> m_collisionList;
};

