/*==================================================================
								Game Project
							Author - Rouie Ortega
							Student Number: 172117
							Application 2D Header
====================================================================*/

/*==================================================================
Pragma Once, Include and Namespace Command Codes for Application2D
====================================================================*/
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

/*==================================================================
Forward Declared all the States for easier access
====================================================================*/

class SplashState;							//Forward Declare for SplashState
class LoadingState;							//Forward Declare for LoadingState
class MenuState;							//Forward Declare for MenuState
class Gamestate;							//Forward Declare for GameState
class PauseState;							//Forward Declare for PauseState

/*==================================================================
Application2D is an Inheritor of Application
====================================================================*/

class Application2D : public Application {
public:

	Application2D();						//Application2D Constructor; no Parameters passed in
	virtual ~Application2D();				//Application2D Destructor; no Parameters needed

	virtual bool startup();					//Application2D Startup runs to set starting variables and Initialise Instances; runs once during star-up; no parameter passed in
	virtual void shutdown();				//Application2D Shutdown Function; runs once during exit; no parameter passed in

	virtual void draw();					//draw function that runs to activate other draw functions; no parameter passed in
	virtual void update(float deltaTime);	//update function that runs to modify other update functions of the game; deltaTime parameter passed in to set runtime
	
private:
	Renderer2D*	m_2dRenderer;				//Renderer2D instance called m_2dRenderer
	StateMachine* m_StateMachine;			//StateMachine instance called m_StateMachine
	SplashState* m_Splash;					//SplashState instance called m_Splash
	LoadingState* m_Load;					//LoadingState instance called m_Load
	MenuState* m_Menu;						//MenuState instance called m_Menu
	GameState* m_Game;						//GameState instance called m_Game
	PauseState* m_Pause;					//PauseState instance called m_Pause

	float m_timer;							//Variable called m_timer created to use when measuring runtime
};