#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "CollisionManager.h"
#include "Matrix3.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace aie;

class Snowflake : public Entity
{
public:
	Snowflake();
	virtual ~Snowflake();

	virtual void draw(Renderer2D* m_Renderer);
	virtual void update(float deltaTime);
	virtual void reset();

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_Snowflake;
	Texture*		m_MeltedSnowflake;
	Vector2			velocity;
	bool collision;
	float depth;
};

