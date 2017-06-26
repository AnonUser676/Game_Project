#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"

using namespace aie;
using namespace std;

class PauseState
{
public:
	PauseState();
	~PauseState();
	void onEnter();
	void onUpdate(float deltaTime /*statemachine*/);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

	Renderer2D*		m_Renderer;
	Texture*		m_background;
};

