#include "CollisionManager.h"

#include "CollisionManager.h"										

CollisionManager* CollisionManager::m_instance = nullptr;			

CollisionManager::CollisionManager() {}								
CollisionManager::~CollisionManager() {}

CollisionManager* CollisionManager::getInstance()
{
	return m_instance;
}

void CollisionManager::Create()
{
	if (m_instance == nullptr)
		m_instance = new CollisionManager;
}

void CollisionManager::Destroy()
{
	delete m_instance;
}

void CollisionManager::addObject(Entity* pObject)
{
	m_collisionList.push_back(pObject);
}


void CollisionManager::removeObject(Entity* pObject)
{
	auto iter = find(m_collisionList.begin(), m_collisionList.end(), pObject);
	if (iter != m_collisionList.end())
		m_collisionList.erase(iter);								
}

Entity* CollisionManager::TestCollisionSquare(Entity* pObject)		//Sends in the Parameter of the object that collided
{
	for (int i = 0; i < m_collisionList.size(); i++)				//goes through the list of Object instances to check what object did the collider collided with
	{
		if (pObject == m_collisionList[i])							//if the object is the same them it breaks out of the Loop
			continue;
		//Calculate AABB of our two objects
		Collider collider1 = pObject->getCollider();				//collider1 takes in the parameter of the object that collided
		collider1.m_TL = collider1.m_TL + pObject->getPosition();	//Gets the top left corner of the collider
		collider1.m_BR = collider1.m_BR + pObject->getPosition();	//gets the bottom right of the object that collided

		Collider collider2 = m_collisionList[i]->getCollider();		//Then collider2 takes in the parameter of the potential object that collided with collider1
		collider2.m_TL = collider2.m_TL + m_collisionList[i]->getPosition();		//gets the top-left corner for collider2
		collider2.m_BR = collider2.m_BR + m_collisionList[i]->getPosition();		//gets the bottom-right corner for collider2

		if (collider1.m_BR.x > collider2.m_TL.x &&					//If the corners of collider1 intersects with any corner of collider2
			collider1.m_BR.y > collider2.m_TL.y &&					//then the objects have collided
			collider1.m_TL.x < collider2.m_BR.x &&
			collider1.m_TL.y < collider2.m_BR.y)
		{
			return m_collisionList[i];								//and will return the Entities parameters
		}
	}
	return nullptr;												//if none of the conditions were met, then this test returns a Null pointer
}

/*==================================================================
Test Collision Circle
For testing Square items against circle objects
====================================================================*/
Entity* CollisionManager::TestCollisionCircle(Entity* pObject)		//Sends in the parameter of the object that collided
{
	for (int i = 0; i < m_collisionList.size(); i++)				//Tests it agains tthe collision list, checking against any circles it may have collided with
	{
		if (pObject == m_collisionList[i])							//If the object is the same then it is ignored
			continue;

		Collider collider = pObject->getCollider();					//Sets the Collider Square area and names it collider
		collider.m_TL += pObject->getPosition();					//Gets the Top-left corner of the object based on its position
		collider.m_BR += pObject->getPosition();					//Gets the Bottom-Right of the Object based on its position

		Collider circle = m_collisionList[i]->getCollider();		//Gets the instance of the potential collision object and anmes it circle
		Vector2 pos = m_collisionList[i]->getPosition();			//Gets the position of the circle object
		float rad = circle.radius;									//Gets it declared Radius

		Vector2 PointA = pos.clamping(collider.m_BR, collider.m_TL);//Sets Vector2 Point A to be the center of the collider
		Vector2 V = PointA - pos;									//Vector V will be the Center of the Object of Collision
		float VMag = V.sqrMagnitude();								//VMag will be the square distance of both object centres

		if (VMag <= rad * rad)										//checks if the object intersects with the circle based on the square Magnitude
			return m_collisionList[i];							//if it does, then it returns the collision object Entity parameters
	}

	return nullptr;												//if all conditions are not meant, then it returns a nullpointer
}

/*==================================================================
TestCollision2Circle Function
For testing against 2 circle object collision
====================================================================*/
Entity* CollisionManager::TestCollision2Circle(Entity* pObject)
{
	for (int i = 0; i < m_collisionList.size(); i++)
	{
		if (pObject == m_collisionList[i])
			continue;

		Collider collider = pObject->getCollider();
		Vector2 pos1 = pObject->getPosition();
		float r1 = collider.radius;

		Collider collider2 = m_collisionList[i]->getCollider();
		Vector2 pos2 = m_collisionList[i]->getPosition();
		float r2 = collider2.radius;

		Vector2 V = pos1 - pos2;
		float VMagnitude = V.magnitude();

		if (VMagnitude <= ((r1 * r2) * ((r1 * r2))))
			return m_collisionList[i];
	}
	return nullptr;
}