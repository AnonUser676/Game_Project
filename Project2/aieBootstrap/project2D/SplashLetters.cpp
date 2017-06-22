#include "SplashLetters.h"


SplashLetters::SplashLetters()
{

	Vector2 pos((letterPos + (m_LettersZ->getWidth()* 2.0f)), 740.0f);
	m_LettersZ = new Texture("./textures/Splash/Z.png");
	m_LettersE = new Texture("./textures/Splash/E.png");
	m_LettersR = new Texture("./textures/Splash/R.png");
	m_LettersO = new Texture("./textures/Splash/0.png");
	m_LettersEnt = new Texture("./textures/Splash/entertainment.png");
	speed = 3.0f;
	mass = 3.0f;
	
	Matrix3 TempPos;
	TempPos.setPosition(pos);
	LocalTransform = LocalTransform * TempPos;
	updateGlobalTransform();

	CollisionManager::getInstance()->addObject(this);
}


SplashLetters::~SplashLetters()
{
	delete	m_LettersZ;
	delete	m_LettersE;
	delete	m_LettersR;
	delete	m_LettersO;
	delete	m_LettersEnt;
	delete  m_Letters;
}

void SplashLetters::draw(Renderer2D* m_Renderer, int type)
{
	if (type == 0)
	{
		m_Letters = m_LettersZ;
	}
	else if (type == 1)
	{
		m_Letters = m_LettersE;
	}
	else if (type == 2)
	{
		m_Letters = m_LettersR;
	}
	else if (type == 3)
	{
		m_Letters = m_LettersO;
	}
	else
	{
		m_Letters = m_LettersEnt;
	}
	m_Renderer->drawSpriteTransformed3x3(m_Letters, GlobalTransform, 0.0f, 0.0f, 50.0f);
}

void SplashLetters::update(float deltaTime)
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

	//insert if statement here regarding stop position
	pos += velocity * deltaTime;
	container.setPosition(pos);
	LocalTransform = LocalTransform * container;
	updateGlobalTransform();
}