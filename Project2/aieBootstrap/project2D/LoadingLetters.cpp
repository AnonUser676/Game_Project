#include "LoadingLetters.h"


LoadingLetters::LoadingLetters()
{
	m_Letters = new Texture("./textures/Loading/Loading.png");
	
	speed = 50.0f;
	mass = 3.0f;
	time = 0.0f;
	ticker = 0.0f;
	checker = true;
	Vector2 pos;
	Matrix3 tempPos;

	pos.x = 600.0f;
	pos.y = 200.0f;

	tempPos.setPosition(pos);
	LocalTransform = LocalTransform * tempPos;
	updateGlobalTransform();
}


LoadingLetters::~LoadingLetters()
{
	delete m_Letters;
	time = 0.0f;
}

void LoadingLetters::draw(Renderer2D* m_Renderer)
{
	m_Renderer->drawSpriteTransformed3x3(m_Letters, GlobalTransform, 0.0f, 0.0f, 50.0f);
}

void LoadingLetters::update(float deltaTime)
{
	time += deltaTime;
	Vector2 pos;
	Vector3 dir;
	Matrix3 container;
	Vector2 forceSum;
	Vector2 accel;
	

	if (ticker < 0.5f)
	{
		dir += (LocalTransform[1]);
		ticker += 0.1f;
	}
	else if (ticker > 0.5f)
	{
		dir += -(LocalTransform[1]);
		ticker += 0.1f;
	}
	else
		ticker = 0.0f;

	forceSum.convert(dir);
	forceSum *= speed;
	accel = forceSum / mass;
	
	velocity += accel * deltaTime;

	if ((GlobalTransform.getPosition().y <= 200.0f) && checker == true)
	{
		velocity *= 0.0f;
		checker = false;
	}
	else if((GlobalTransform.getPosition().y >= 250.0f) && checker == true)
	{
		velocity *= -1.0f;
		checker = false;
	}
	else
		checker = true;

	pos += velocity * deltaTime;
	container.setPosition(pos);
	LocalTransform = LocalTransform * container;
	updateGlobalTransform();
}