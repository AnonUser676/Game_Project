#include "Snowflake.h"


Snowflake::Snowflake()
{
	collision = false;
	depth = (rand() % 99 + 1) *1.0f;
	Vector2 pos;

	pos.x = rand() % 1360 + 50.0f;
	pos.y = 800.0f;
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
	m_Renderer->drawSpriteTransformed3x3(m_Snowflake, GlobalTransform, 0.0f, 0.0f, depth);
}

void Snowflake::update(float deltaTime)
{
	Vector3 dir;
	Matrix3 container;
	Vector2 forceSum;
	Vector2 accel;
	Vector2 pos;

	dir += -(LocalTransform[1]);

	if ((getPosition().y >= 128) || (getPosition().y >= 471) || (getPosition().y >= 571))
		dir += -(LocalTransform[0]);

	if ((getPosition().y <= 64) || (getPosition().y <= 376) || (getPosition().y <= 699))
		dir += (LocalTransform[0]);

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

void Snowflake::reset()
{
	Vector2 pos;
	Matrix3 container;

	pos.x = rand() % 1270 * 1.0f;
	pos.y = 800.0f;
	velocity *= 0.99f;

	container.setPosition(pos);
	LocalTransform = LocalTransform * container;
	updateGlobalTransform();
}