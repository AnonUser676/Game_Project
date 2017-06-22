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

	//Create state machine

	m_StateMachine = new StateMachine();

	//Register states
	m_StateMachine->RegisterState(0, new )
	//stateMachine->RegisterState(0, new SplashState());
	//stateMachine->RegisterState(1, new Loading());
	//stateMachine->RegisterState(2, new Game());

	//Set first state
	//stateMachine->PushState(0);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	clearScreen();

	m_2dRenderer->begin();

	m_2dRenderer->end();
}