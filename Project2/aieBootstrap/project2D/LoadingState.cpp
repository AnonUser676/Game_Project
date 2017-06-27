#include "LoadingState.h"


LoadingState::LoadingState()
{
		m_Letters = new LoadingLetters;
}


LoadingState::~LoadingState()
{
	delete m_Letters;
}

void LoadingState::onEnter()
{
	time = 0.0f;
}

void LoadingState::onDraw(Renderer2D* renderer2D)
{
	m_Letters->draw(renderer2D);
}

void LoadingState::onUpdate(float deltaTime, StateMachine* State)
{
	time += deltaTime;

	m_Letters->update(deltaTime);


	if (time > 5)
	{
		State->PopState();
		State->PushState(STATE_MENU);
	}
}

void LoadingState::onExit()
{
	time = 0.0f;
}
