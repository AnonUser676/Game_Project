#include "PauseState.h"

PauseState::PauseState()
{
	m_background = new Texture("./textures/Pause/MenuBG.png");
	m_ResumeOFF = new Texture("./textures/Pause/Resume.png");
	m_ResumeOn = new Texture("./textures/Pause/Resume_Pressed.png");
	m_OptionsOff = new Texture("./textures/Pause/Options.png");
	m_OptionsOn = new Texture("./textures/Pause/Options_Pressed.png");
	m_ExitOff = new Texture("./textures/Pause/Exit.png");
	m_ExitOn = new Texture("./textures/Pause/Exit_Pressed.png");
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
	renderer2D->drawSprite(m_background, 118.0f, 118.0f, 1044.0f, 484.0f, 0, 98.0f, 0, 0);
	renderer2D->drawSprite(m_Resume, 413.0f, 440.0f, 454.0f, 130.0f, 0.0f, 50.0f, 0.0f, 0.0f);
	renderer2D->drawSprite(m_Options, 413.0f, 290.0f, 454.0f, 130.0f, 0.0f, 50.0f, 0.0f, 0.0f);
	renderer2D->drawSprite(m_Exit, 413.0f, 140.0f, 454.0f, 130.0f, 0.0f, 50.0f, 0.0f, 0.0f);
}

void PauseState::onUpdate(float deltaTIme, StateMachine* State)
{
	time += deltaTIme;

	m_Input = Input::getInstance();

	if ((m_Input->getMouseX() > 413.0f) && (m_Input->getMouseX() < 867.0f))
	{
		if ((m_Input->getMouseY() > 440.0f) && (m_Input->getMouseY() < 570.0f))
		{
			m_Resume = m_ResumeOn;
			if (m_Input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
				if (m_Input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT)|| m_Input->wasKeyPressed(INPUT_KEY_ESCAPE))
				{
					State->bDrawLowerState = false;
					State->PopState();
				}
		}
		else if ((m_Input->getMouseY() > 290.0f) && (m_Input->getMouseY() < 420.0f))
			m_Options = m_OptionsOn;
		else if ((m_Input->getMouseY() > 140.0f) && (m_Input->getMouseY() < 270.0f))
		{
			m_Exit = m_ExitOn;
			if (m_Input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
			{
				State->bDrawLowerState = false;
				State->PopState();
				State->PushState(STATE_MENU);
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