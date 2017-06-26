#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "StateMachine.h"

using namespace aie;
using namespace std;

class GameState
{

public:
	GameState();
	virtual ~GameState();
	void onEnter();
	void onUpdate(float deltaTime, StateMachine* State);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_background;
};