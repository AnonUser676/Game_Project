#include "LoadingState.h"


LoadingState::LoadingState()
{
	for (int i = 0; i < 7; i++)
	{
		m_Letters.pushBack(myLetterPool.Create());
	}
	
}


LoadingState::~LoadingState()
{
	m_Letters.Clear();
}

void LoadingState::onEnter()
{
	time = 0.0f;
}

void LoadingState::onDraw(Renderer2D* renderer2D)
{
	for (int i = 0; i < m_Letters.Size(); i++)
	{
		m_Letters[i]->draw(renderer2D, i);
	}
}

void LoadingState::onUpdate(float deltaTime, StateMachine* State)
{
	time += deltaTime;

	for (int i = 0; i < m_Letters.Size(); i++)
	{
		m_Letters[i]->update(deltaTime, i);
	}

	if (time > 5)
	{
		State->PopState();
		State->PushState(2);
	}
}

void LoadingState::onExit()
{
	for (int i = 0; i < m_Letters.Size(); i++)
	{
		myLetterPool.Destroy(m_Letters[i]);
	}
	
	time = 0.0f;
}
