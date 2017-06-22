#include "SplashState.h"

SplashState::SplashState()
{
	m_background = new Texture("./textures/Splash/Splash.png");
	m_Snow = myPool.Create();
	m_Letters = myLetterPool.Create();
}


SplashState::~SplashState()
{
	delete m_background;
}

void SplashState::onEnter()
{
}

void SplashState::onDraw(Renderer2D* renderer2D)
{
	m_Renderer->drawSprite(m_background, 0, 0, 0, 0, 0, 99, 0.0f, 0.0f);
	m_Snow->draw(renderer2D);
	for (int i = 0; i < 5; i++)
	{
		m_Letters->draw(renderer2D,i);
	}
	
}

void SplashState::onUpdate(float deltaTime)
{
	m_Snow->update(deltaTime);
	m_Letters->update(deltaTime);
}

void SplashState::onExit()
{
	myPool.Destroy(m_Snow);
}
