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
	time = 0.0f;
}

void GameState::onDraw(Renderer2D* renderer2D)
{
	renderer2D->drawSprite(m_background, 0, 0, 0, 0, 0, 99.0f, 0.0f, 0.0f);
	
}

void GameState::onUpdate(float deltaTime, StateMachine* State)
{
	time += deltaTime;
	m_Input = Input::getInstance();

	if (m_Input->isKeyDown(INPUT_KEY_ESCAPE))
	{
		State->PushState(4);
		State->bDrawLowerState = true;
	}
}

void GameState::onExit()
{
	time = 0.0f;
}