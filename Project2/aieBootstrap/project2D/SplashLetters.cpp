#include "SplashLetters.h"


SplashLetters::SplashLetters()
{
	letterPos = 600.0f;
	m_Letters = new Texture("./textures/Splash/Logo.png");
	Vector2 pos(letterPos, 740.0f);
	speed = 80.0f;
	mass = 1.0f;
	
	Matrix3 TempPos;
	TempPos.setPosition(pos);
	LocalTransform = LocalTransform * TempPos;
	updateGlobalTransform();

	CollisionManager::getInstance()->addObject(this);
}


SplashLetters::~SplashLetters()
{
	delete  m_Letters;
}

void SplashLetters::draw(Renderer2D* m_Renderer)
{
	m_Renderer->drawSpriteTransformed3x3(m_Letters, GlobalTransform, 0.0f, 0.0f, 50.0f);
}

void SplashLetters::update(float deltaTime)
{
	Vector3 dir;
	Vector2 pos;
	Matrix3 container;
	Vector2 forceSum;
	Vector2 accel;


	dir += -(LocalTransform[1]);
	forceSum.convert(dir);
	forceSum *= speed;
	accel = forceSum / mass;

	velocity += accel * deltaTime;

	if (LocalTransform.getPosition().y < 380.0f)
		velocity *= -0.5f;
	
	pos += velocity * deltaTime;
	container.setPosition(pos);
	LocalTransform = LocalTransform * container;
	updateGlobalTransform();
}