#include "GameState.h"


GameState::GameState()
{
	m_background = new Texture("./textures/Game/background.png");
}


GameState::~GameState()
{
	delete m_background;
}

void GameState::onEnter()
{
}

void GameState::onDraw(Renderer2D* renderer2D)
{
	m_Renderer->drawSprite(m_background, 0, 0, 0, 0, 0, 99, 0.0f, 0.0f);
	
}

void GameState::onUpdate(float deltaTime, StateMachine* State)
{
}

void GameState::onExit()
{
}