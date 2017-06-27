#include "MenuState.h"

MenuState::MenuState()
{
	m_background = new Texture("./textures/Menu/bg.png");
	m_Ice = new Texture("./textures/Menu/ICE.png");
	m_Glider = new Texture("./textures/Menu/Glider.png");
	m_font = new Font("./font/consolas.ttf", 32);
	for (int i = 0; i < 20; i++)
	{
		m_Snow.pushBack(myPool.Create());
	}
	textTimer = 0;
	ticker = 0;
}


MenuState::~MenuState()
{
	delete m_background;
	delete m_Ice;
	delete m_Glider;
	delete m_font;
	m_Snow.Clear();
}

void MenuState::onEnter()
{
	time = 0.0f;
}

void MenuState::onDraw(Renderer2D* renderer2D)
{
	renderer2D->drawSprite(m_background, 0, 0, 0, 0, 0, 97.0f, 0.0f, 0.0f);
	renderer2D->drawSprite(m_Ice, 480.0f, 360.0f, m_Ice->getWidth(), m_Ice->getHeight(), 0, 50.0f, 0.0f, 0.0f);
	renderer2D->drawSprite(m_Glider, 480.0f, 250.0f, m_Glider->getWidth(), m_Glider->getHeight(), 0, 50.0f, 0.0f, 0.0f);
	renderer2D->drawText(m_font, instructions, 280.0f, 220.0f);

	for (int i = 0; i < m_Snow.Size(); i++)
	{
		m_Snow[i]->draw(renderer2D);
	}
}

void MenuState::onUpdate(float deltaTime, StateMachine* State)
{
	time += deltaTime;
	
	m_Input = Input::getInstance();

	for (int i = 0; i < m_Snow.Size(); i++)
	{
		m_Snow[i]->update(deltaTime);
		
		if (((m_Snow[i]->getPosition().x) <= 0.0f) || ((m_Snow[i]->getPosition().x) >= 1280.0f) || ((m_Snow[i]->getPosition().y) <= 0.0f))
			m_Snow[i]->reset();
	}

	if (ticker <= 20)
	{
		strcpy_s(instructions, "Press Enter or Left Mouse Button to Begin");
		ticker++;
	}
	else
	{
		strcpy_s(instructions, "");
		ticker = 0;
	}

	if ((m_Input->wasKeyPressed(INPUT_KEY_ENTER)) || m_Input->wasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT))
	{
		State->PopState();
		State->PushState(STATE_GAME);
	}	 
}

void MenuState::onExit()
{
	for (int i = 0; i < m_Snow.Size(); i++)
	{
		myPool.Destroy(m_Snow[i]);
		m_Snow[i]->reset();
	}
	time = 0.0f;	
}