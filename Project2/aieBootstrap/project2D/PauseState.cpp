#include "PauseState.h"

PauseState::PauseState()
{
	m_background = new Texture("./textures/Pause/MenuBG.png");
	m_ResumeOFF = new Texture("./textures/Menu/Resume.png");
	m_ResumeOn = new Texture("./textures/Menu/Resume_Pressed.png");
	m_OptionsOff = new Texture("./textures/Menu/Options.png");
	m_OptionsOn = new Texture("./textures/Menu/Options_Pressed.png");
	m_ExitOff = new Texture("./textures/Menu/Exit.png");
	m_ExitOn = new Texture("./textures/Menu/Exit_Pressed.png");
	m_Resume = m_ResumeOFF;
	m_Options = m_OptionsOff;
	m_Exit = m_ExitOff;
}

PauseState::~PauseState()
{
	delete  m_background;
	delete 	m_ResumeOFF;
	delete 	m_ResumeOn;
	delete 	m_OptionsOff;
	delete 	m_OptionsOn;
	delete 	m_ExitOff;
	delete 	m_ExitOn;
}

void PauseState::onEnter()
{
	time = 0.0f;
}

void PauseState::onDraw(Renderer2D* renderer2D)
{
	renderer2D->drawSprite(m_background, 0, 0, 0, 0, 0, 98.0f, 0, 0);
	renderer2D->drawSprite(m_Resume, 640.0f, 400.0f, 10.0f, 10.0f, 0.0f, 50.0f, 0.0f, 0.0f);
	renderer2D->drawSprite(m_Options, 640.0f, 300.0f, 10.0f, 10.0f, 0.0f, 50.0f, 0.0f, 0.0f);
	renderer2D->drawSprite(m_Exit, 640.0f, 200.0f, 10.0f, 10.0f, 0.0f, 50.0f, 0.0f, 0.0f);
}

void PauseState::onUpdate(float deltaTIme, StateMachine* State)
{
	time += deltaTIme;

	m_Input = Input::getInstance();

	if ((m_Input->getMouseX() > 600.0f) && (m_Input->getMouseX() < 700.0f))
	{
		if ((m_Input->getMouseY() > 380.0f) && (m_Input->getMouseY() < 420.0f))
		{
			m_Resume = m_ResumeOn;
			if (m_Input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
				if (m_Input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
				{
					State->bDrawLowerState = false;
					State->PopState();
				}
		}
		else if ((m_Input->getMouseY() > 280.0f) && (m_Input->getMouseY() < 320.0f))
			m_Options = m_OptionsOn;
		else if ((m_Input->getMouseY() > 180.0f) && (m_Input->getMouseY() < 220.0f))
		{
			m_Exit = m_ExitOn;
			if (m_Input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
			{
				State->bDrawLowerState = false;
				State->PopState();
				State->PushState(2);
			}
		}
		else
		{
			m_Resume = m_ResumeOFF;
			m_Options = m_OptionsOff;
			m_Exit = m_ExitOff;
		}
	}
	else
	{
		m_Resume = m_ResumeOFF;
		m_Options = m_OptionsOff;
		m_Exit = m_ExitOff;
	}
}

void PauseState::onExit()
{
	time = 0.0f;
}