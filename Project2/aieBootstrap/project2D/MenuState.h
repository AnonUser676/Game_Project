#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "Snowflake.h"

using namespace aie;
using namespace std;

class MenuState : public BaseState
{
public:
	MenuState();
	~MenuState();

	void onEnter();
	void onUpdate(float deltaTime, StateMachine* State);
	void onDraw(Renderer2D* renderer2D);
	void onExit();
	
	ObjectPool <Snowflake, 20> myPool;

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_background;
	Snowflake*		m_Snow;
};