#pragma once
#include <vector>
#include <iostream>
#include "Collider.h"
#include "Application.h"
#include "Texture.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

using namespace std;
using namespace aie;

class Entity
{
public:
	Entity();
	virtual ~Entity();

	Entity* m_pParent;
	vector<Entity*> m_childList;

	Matrix3 LocalTransform;
	Matrix3 GlobalTransform;
	Vector2 getPosition();

	Collider& getCollider();
	Collider m_Collider;

	void updateGlobalTransform();

protected:
	bool collision;
	float speed;
	float mass;
};

