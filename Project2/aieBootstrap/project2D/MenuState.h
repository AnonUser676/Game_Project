#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "Snowflake.h"
#include "StateMachine.h"
#include "DynamicArray.h"
#include "Input.h"
#include <iostream>
#include <cstring>
#include "Font.h"

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

	float time;
	char instructions[100];
	int textTimer;
	int ticker;

protected:
	Input*			m_Input;
	Texture*		m_background;
	Texture*		m_Ice;
	Texture*		m_Glider;
	Font*			m_font;
	DynamicArray<Snowflake*>		m_Snow;
};