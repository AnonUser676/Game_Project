#include "Snowflake.h"


Snowflake::Snowflake()
{
	collision = false;
	depth = static_cast <float> (rand()) / (static_cast <float> (99));

	Vector2 pos(rand() % 1360 + 50.0f, 800.0f);
	m_Snowflake = new Texture("./textures/Splash/snowflake.png");
	m_MeltedSnowflake = new Texture("./textures/Splash/snowflake_melted.png");
	speed = (rand() % 30 + 12) * 1.0f;
	mass = 1.0f;
	m_Collider.m_TL = Vector2(-((m_Snowflake->getHeight()) / 2), -((m_Snowflake->getWidth()) / 2));
	m_Collider.m_BR = Vector2((m_Snowflake->getHeight()) / 2, (m_Snowflake->getWidth()) / 2);
	m_Collider.radius = (m_Snowflake->getWidth() / 2);

	Matrix3 TempPos;
	TempPos.setPosition(pos);
	LocalTransform = LocalTransform * TempPos;
	updateGlobalTransform();
		
	CollisionManager::getInstance()->addObject(this);
}

Snowflake::~Snowflake()
{
	delete m_Snowflake;
	delete m_MeltedSnowflake;
}

void Snowflake::draw(Renderer2D* m_Renderer)
{		
	m_Renderer->drawSpriteTransformed3x3(m_Snowflake, GlobalTransform, 0.0f, 0.0f, 1.0f);
}

void Snowflake::update(float deltaTime)
{
	Vector3 dir;
	Vector2 pos;
	Matrix3 container;
	Vector2 forceSum;
	Vector2 accel;
		
	dir += -(LocalTransform[1]);

	if ((getPosition().y >= 471) ||  (getPosition().y == 128) || (getPosition().y == 571))
	{
		dir += -(LocalTransform[0]);
	}

	else if ((getPosition().y == 699) || (getPosition().y == 64) || (getPosition().y == 376))
	{
		dir += -(LocalTransform[0]);
	}

	forceSum.convert(dir);
	forceSum *= speed;
	accel = forceSum / mass;

	velocity += accel * deltaTime;

	CollisionManager* pCollision = CollisionManager::getInstance();

	Entity* colliderSq = pCollision->TestCollisionSquare(this);

	if (colliderSq && (collision == false))
	{
		velocity *= 0.0f;
		collision = true;
	}

	Entity* colliderCir = pCollision->TestCollisionCircle(this);

	if (colliderCir && (collision == false))
	{
		velocity *= 0.0f;
		collision = true;
	}

	Entity* colliderCir2 = pCollision->TestCollision2Circle(this);

	if (colliderCir2 && (collision == false))
	{
		velocity *= 0.0f;
		collision = true;
	}
	pos += velocity * deltaTime;
	container.setPosition(pos);
	LocalTransform = LocalTransform * container;
	updateGlobalTransform();
}