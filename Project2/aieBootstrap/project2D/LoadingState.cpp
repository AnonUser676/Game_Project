#include "LoadingState.h"



LoadingState::LoadingState()
{
	m_Letters = myLetterPool.Create();
}


LoadingState::~LoadingState()
{
}

void LoadingState::onEnter()
{}

void LoadingState::onDraw(Renderer2D* renderer2D)
{
	for (int i = 0; i < 7; i++)
	{
		m_Letters->draw(renderer2D, i);
	}
}

void LoadingState::onUpdate(float deltaTime)
{
	m_Letters->update(deltaTime);
}

void LoadingState::onExit()
{
	myLetterPool.Destroy(m_Letters);
}
