#include "Entity.h"



Entity::Entity()
{
	m_pParent = nullptr;
}


Entity::~Entity()
{
}

Vector2 Entity::getPosition()
{
	Vector2 pos;
	pos.x = GlobalTransform.matrix[2][0];
	pos.y = GlobalTransform.matrix[2][1];
	return pos;
}

Collider& Entity::getCollider()
{
	return m_Collider;
}

void Entity::updateGlobalTransform()
{
	if (m_pParent != nullptr)
	{
		GlobalTransform = m_pParent->GlobalTransform * LocalTransform;
	}
	else
	{
		GlobalTransform = LocalTransform;
	}
	for (int i = 0; i < m_childList.size(); i++)
	{
		m_childList[i]->updateGlobalTransform();
	}
}