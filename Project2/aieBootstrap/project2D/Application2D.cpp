#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();
	CollisionManager::Create();
	//Create state machine

	m_StateMachine = new StateMachine();

	m_Splash = new SplashState();
	m_Load = new LoadingState();
	m_Menu = new MenuState();
	m_Game = new GameState();
	m_Pause = new PauseState();

	//Register states
	m_StateMachine->RegisterState(0, m_Splash);
	m_StateMachine->RegisterState(1, m_Load);
	m_StateMachine->RegisterState(2, m_Menu);
	m_StateMachine->RegisterState(3, m_Game);
	m_StateMachine->RegisterState(4, m_Pause);
	
	//Set first state
	m_StateMachine->PushState(3);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	
	delete m_Splash;
	delete m_Load;
	delete m_Menu;
	delete m_Game;
	delete m_Pause;
	CollisionManager::Destroy();
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	Input* input = Input::getInstance();

	m_StateMachine->Update(deltaTime);

	if (input->isKeyDown(INPUT_KEY_X))
		quit();
}

void Application2D::draw() 
{
	clearScreen();

	m_2dRenderer->begin();
	m_StateMachine->Draw(m_2dRenderer);
	m_2dRenderer->end();
}