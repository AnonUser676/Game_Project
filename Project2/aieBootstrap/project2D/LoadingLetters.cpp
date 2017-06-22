#include "LoadingLetters.h"



LoadingLetters::LoadingLetters()
{
	Vector2 pos((letterPos + (m_LettersL->getWidth()* 2.0f)), 740.0f);
	m_LettersL = new Texture("./textures/Loading/L.png");
	m_LettersO = new Texture("./textures/Loading/o.png");
	m_LettersA = new Texture("./textures/Loading/A.png");
	m_LettersD = new Texture("./textures/Loading/d.png");
	m_LettersI = new Texture("./textures/Loading/i.png");
	m_LettersN = new Texture("./textures/Loading/n.png");
	m_LettersG = new Texture("./textures/Loading/g.png");
	speed = 3.0f;
	mass = 3.0f;

	Matrix3 TempPos;
	TempPos.setPosition(pos);
	LocalTransform = LocalTransform * TempPos;
	updateGlobalTransform();

}


LoadingLetters::~LoadingLetters()
{
	delete m_LettersL;
	delete m_LettersO;
	delete m_LettersA;
	delete m_LettersD;
	delete m_LettersI;
	delete m_LettersN;
	delete m_LettersG;
	delete m_Letters;
}

void LoadingLetters::draw(Renderer2D* m_Renderer, int type)
{
	if (type == 0)
	{
		m_Letters = m_LettersL;
	}
	else if (type == 1)
	{
		m_Letters = m_LettersO;
	}
	else if (type == 2)
	{
		m_Letters = m_LettersA;
	}
	else if (type == 3)
	{
		m_Letters = m_LettersD;
	}
	else if (type == 4)
	{
		m_Letters = m_LettersI;
	}
	else if (type == 5)
	{
		m_Letters = m_LettersN;
	}
	else if (type == 6)
	{
		m_Letters = m_LettersG;
	}
	else
	{
		m_Letters = m_LettersG;
	}
	m_Renderer->drawSpriteTransformed3x3(m_Letters, GlobalTransform, 0.0f, 0.0f, 50.0f);
}

void LoadingLetters::update(float deltaTime)
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