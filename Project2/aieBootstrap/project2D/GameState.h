#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"

using namespace aie;
using namespace std;

class GameState
{

public:
	GameState();
	virtual ~GameState();
	void onEnter();
	void onUpdate(float deltaTime);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_background;
};