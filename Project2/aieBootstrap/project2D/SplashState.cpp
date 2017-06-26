#include "SplashState.h"

SplashState::SplashState()
{
	m_background = new Texture("./textures/Splash/Splash.png");
	m_Letters = new SplashLetters;
	
	for (int i = 0; i < 20; i++)
	{
		m_Snow[i] = myPool.Create();
		//m_Snow.pushBack(m_Snow);
	}
}


SplashState::~SplashState()
{
	delete m_background;
}

void SplashState::onEnter()
{
	time = 0.0f;
}

void SplashState::onDraw(Renderer2D* renderer2D)
{
	renderer2D->drawSprite(m_background, 0, 0, 0, 0, 0, 99, 0.0f, 0.0f);
	
	for (int i = 0; i < m_Snow.Size(); i++)
	{
		m_Snow[i]->draw(renderer2D);
	}

	m_Letters->draw(renderer2D);
	
}

void SplashState::onUpdate(float deltaTime, StateMachine* State)
{
	time += deltaTime;

	for (int i = 0; i < m_Snow.Size(); i++)
	{
		m_Snow[i]->update(deltaTime);
	}
	m_Letters->update(deltaTime);
	
	if (time > 8.0f)
	{
		State->PushState(1);
	}
}

void SplashState::onExit()
{
	for (int i = 0; i < m_Snow.Size(); i++)
	{
		myPool.Destroy(m_Snow[i]);
	}
	m_Snow.Clear();
	time = 0.0f;
}
