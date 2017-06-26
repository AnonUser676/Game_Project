#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "Snowflake.h"
#include "SplashLetters.h"
#include "StateMachine.h"
#include "DynamicArray.h"

using namespace aie;
using namespace std;

class SplashState : public BaseState
{
public:
	SplashState();
	virtual ~SplashState();
	void onEnter();
	void onUpdate(float deltaTime, StateMachine* State);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

	ObjectPool <Snowflake, 20> myPool;

	float time;

protected:
	Texture*						m_background;
	DynamicArray<Snowflake*>		m_Snow;
	SplashLetters*					m_Letters;
};

