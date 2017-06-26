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

void LoadingState::onUpdate(float deltaTime, StateMachine* State)
{
	m_Letters->update(deltaTime);

	State->PushState(2);
}

void LoadingState::onExit()
{
	myLetterPool.Destroy(m_Letters);
}
