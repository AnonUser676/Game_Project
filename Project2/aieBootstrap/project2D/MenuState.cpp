#include "MenuState.h"

MenuState::MenuState()
{
	m_background = new Texture("./textures/Menu/bg.png");
	m_Snow = myPool.Create();
}


MenuState::~MenuState()
{
	delete m_background;
}

void MenuState::onEnter()
{
}

void MenuState::onDraw(Renderer2D* renderer2D)
{
	m_Renderer->drawSprite(m_background, 0, 0, 0, 0, 0, 99, 0.0f, 0.0f);
	m_Snow->draw(renderer2D);
}

void MenuState::onUpdate(float deltaTime, StateMachine* State)
{
	m_Snow->update(deltaTime);
}

void MenuState::onExit()
{
	myPool.Destroy(m_Snow);
}