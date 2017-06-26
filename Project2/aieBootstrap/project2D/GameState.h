#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "StateMachine.h"
#include "Input.h"

using namespace aie;
using namespace std;

class GameState : public BaseState
{

public:
	GameState();
	virtual ~GameState();

	void onEnter();
	void onUpdate(float deltaTime, StateMachine* State);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

	float time;

protected:
	Texture*		m_background;
	Input*			m_Input;
};