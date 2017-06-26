#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "StateMachine.h"
#include "SplashState.h"
#include "LoadingState.h"
#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"

using namespace std;
using namespace aie;

class SplashState;
class LoadingState;
class MenuState;
class Gamestate;
class PauseState;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	
private:
	Renderer2D*	m_2dRenderer;
	StateMachine* m_StateMachine;
	float m_timer;

	SplashState* m_Splash;
	LoadingState* m_Load;
	MenuState* m_Menu;
	GameState* m_Game;
	PauseState* m_Pause;
};