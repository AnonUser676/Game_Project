#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "StateMachine.h"
#include "Input.h"

using namespace aie;
using namespace std;

class PauseState : public BaseState
{
public:
	PauseState();
	~PauseState();
	void onEnter();
	void onUpdate(float deltaTime, StateMachine* State);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

	float time;

protected:
	Input*			m_Input;
	Texture*		m_background;
	Texture*		m_Resume;
	Texture*		m_ResumeOn;
	Texture*		m_ResumeOFF;
	Texture*		m_Options;
	Texture*		m_OptionsOn;
	Texture*		m_OptionsOff;
	Texture*		m_Exit;
	Texture*		m_ExitOn;
	Texture*		m_ExitOff;
};