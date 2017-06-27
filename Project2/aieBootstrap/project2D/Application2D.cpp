/*==================================================================
								Game Project
							Author - Rouie Ortega
							Student Number: 172117
							Application 2D CPP
====================================================================*/

/*==================================================================
Pragma Once, Include and Namespace Command Codes for Application2D
====================================================================*/

#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"

using namespace aie;

Application2D::Application2D() {}								//Constructor for Application2D, does nothing, since startup does it's job but required to be present for program to work
Application2D::~Application2D() {}								//Destructor for Application2D, does nothing, since shutdown does it's job but required to be present for program to work


/*==================================================================
Application2D Function Startup
====================================================================*/

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();							//new Instance of Renderer2D initialized as m_2dRenderer
	CollisionManager::Create();									//Instance of CollisionManager created
	m_StateMachine = new StateMachine();						//Instance of Statemachine created as m_StateMachine
	m_Splash = new SplashState();								//Instance of SplashState created as m_Splash
	m_Load = new LoadingState();								//Instance of LoadingState created as m_Load
	m_Menu = new MenuState();									//Instance of MenuState created as m_Menu
	m_Game = new GameState();									//Instance of GameState created as m_Game
	m_Pause = new PauseState();									//Instance of MenuState created as m_Menu

	m_StateMachine->RegisterState(STATE_SPLASH, m_Splash);		//Registers m_Splash into the StateMachine and attaches it to enum value STATE_SPLASH for the stack
	m_StateMachine->RegisterState(STATE_LOAD, m_Load);			//Registers m_Load into the StateMachine and attaches it to enum value STATE_LOAD for the stack
	m_StateMachine->RegisterState(STATE_MENU, m_Menu);			//Registers m_Menu into the StateMachine and attaches it to enum value STATE_MENU for the stack
	m_StateMachine->RegisterState(STATE_GAME, m_Game);			//Registers m_Game into the StateMachine and attaches it to enum value STATE_GAME for the stack
	m_StateMachine->RegisterState(STATE_PAUSE, m_Pause);		//Registers m_Pause into the StateMachine and attaches it to enum value STATE_PAUSE for the stack
	
	m_StateMachine->PushState(STATE_SPLASH);					//Pushes Splash State first into the stack to ensure that it appears first

	m_timer = 0;												//Sets m_timer to 0 to initialize runtime to 0

	return true;												//returns true once startup is complete
}


/*==================================================================
Application2D Function Shutdown
====================================================================*/

void Application2D::shutdown() 
{
	delete m_Splash;											//Deletes Instance of SplashState to ensure no memory leaks
	delete m_Load;												//Deletes Instance of LoadingState to ensure no memory leaks
	delete m_Menu;												//Deletes Instance of MenuState to ensure no memory leaks
	delete m_Game;												//Deletes Instance of GameState to ensure no memory leaks
	delete m_Pause;												//Deletes Instance of PauseState to ensure no memory leaks
	CollisionManager::Destroy();								//Destroys Instance of CollisionManager to ensure no memory leaks
	delete m_2dRenderer;										//Deletes Instance of m_2dRenderer to ensure no memory leaks
}


/*==================================================================
Application2D Function Draw
====================================================================*/

void Application2D::draw()
{
	clearScreen();												//Clears the Screen

	m_2dRenderer->begin();										//Runs Renderer2D's begin function
	m_StateMachine->Draw(m_2dRenderer);							//Runs StateMachine's Draw function passing in m_2dRenderer to the function
	m_2dRenderer->end();										//Runs m_2dRenderer's end function
}

/*==================================================================
Application2D Function Update
====================================================================*/

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;										//m_timer adds the value of deltaTime to help in measuring runtime
	Input* input = Input::getInstance();						//Creates Instance of Input and names it input
	m_StateMachine->Update(deltaTime);							//Runs StateMachine's Update to Update all States on top of the Stack

	if (input->isKeyDown(INPUT_KEY_X))							//Pressing X exits the program, relies on the Input class function is KeyDown and passes the Input Key value
		quit();													//Runs quit function from Application if X is pressed
}