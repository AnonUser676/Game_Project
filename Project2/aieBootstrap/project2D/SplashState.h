#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "Snowflake.h"
#include "SplashLetters.h"

using namespace aie;
using namespace std;

class SplashState : public BaseState
{
public:
	SplashState();
	~SplashState();
	void onEnter();
	void onUpdate(float deltaTime /*statemachine*/);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

	ObjectPool <Snowflake, 20> myPool;
	ObjectPool <SplashLetters, 5> myLetterPool;

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_background;
	Snowflake*		m_Snow;
	SplashLetters*	m_Letters;
};

