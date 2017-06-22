#include "Snowflake.h"


Snowflake::Snowflake()
{
	Vector2 pos(rand() % 1280 + 1.0f, 740.0f);
	m_Snowflake = new Texture("./textures/Splash/snowflake.png");
	m_MeltedSnowflake = new Texture("./textures/Splash/snowflake_melted.png");
	random = (rand() % 100 + 1);
	speed = random / 100.0f;
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
}

void Snowflake::draw(Renderer2D* m_Renderer)
{
	if (collision == true)
		m_Snowflake = m_MeltedSnowflake;
	
	m_Renderer->drawSpriteTransformed3x3(m_Snowflake, GlobalTransform, 0.0f, 0.0f, depth);
}

void Snowflake::update(float deltaTime)
{
	Vector3 dir;
	Vector2 pos;
	Matrix3 container;
	Vector2 forceSum;
	Vector2 accel;
	Vector2 velocity;
	
	dir += -(LocalTransform[1]);
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