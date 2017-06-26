#include "LoadingLetters.h"



LoadingLetters::LoadingLetters()
{
	m_LettersL = new Texture("./textures/Loading/L.png");
	m_LettersO = new Texture("./textures/Loading/o.png");
	m_LettersA = new Texture("./textures/Loading/A.png");
	m_LettersD = new Texture("./textures/Loading/d.png");
	m_LettersI = new Texture("./textures/Loading/i.png");
	m_LettersN = new Texture("./textures/Loading/n.png");
	m_LettersG = new Texture("./textures/Loading/g.png");
	m_Letters = m_LettersL;
	
	pos0.x = 600; pos0.y = 200;
	pos1.x = 600 + (m_LettersL->getWidth())*1; pos1.y = 200;
	pos2.x = 600 + (m_LettersL->getWidth())*2; pos2.y = 200;
	pos3.x = 600 + (m_LettersL->getWidth())*3; pos3.y = 200;
	pos4.x = 600 + (m_LettersL->getWidth())*4; pos4.y = 200;
	pos5.x = 600 + (m_LettersL->getWidth())*5; pos5.y = 200;
	pos6.x = 600 + (m_LettersL->getWidth())*6; pos6.y = 200;
	pos7.x = 600 + (m_LettersL->getWidth())*7; pos7.y = 200;

	speed = 50.0f;
	mass = 3.0f;
	time = 0.0f;
	checker = false;
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
	//delete m_Letters;
	time = 0.0f;
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

void LoadingLetters::update(float deltaTime, int type)
{
	time += deltaTime;
	Vector2 pos;
	Vector3 dir;
	Matrix3 container;
	Vector2 forceSum;
	Vector2 accel;
	
	if (type == 0)
	{
		pos = pos0;
	}
	else if (type == 1)
	{
		pos = pos1;
	}
	else if (type == 2)
	{
		pos = pos2;
	}
	else if (type == 3)
	{
		pos = pos3;
	}
	else if (type == 4)
	{
		pos = pos4;
	}
	else if (type == 5)
	{
		pos = pos5;
	}
	else if (type == 6)
	{
		pos = pos6;
	}
	else
	{
		pos = pos7;
	}

	if ((time/time) > 0.5f)
		dir += (LocalTransform[1]);

	if ((time/time) < 0.5f)
		dir += -(LocalTransform[1]);

	forceSum.convert(dir);
	forceSum *= speed;
	accel = forceSum / mass;
	
	velocity += accel * deltaTime;
	
	if ((pos.y < 200.0f) && checker == true)
	{
		velocity *= 0.0f;
		checker = false;
	}
	else
		checker = false;

	pos += velocity * deltaTime;
	container.setPosition(pos);
	LocalTransform = LocalTransform * container;
	updateGlobalTransform();
}