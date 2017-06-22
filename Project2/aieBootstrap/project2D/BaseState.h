#pragma once
#include "Renderer2D.h"

using namespace aie;
using namespace std;

class BaseState
{
public:
	BaseState();
	virtual ~BaseState();

	virtual void onEnter() = 0;
	virtual void onUpdate(float deltaTIme) = 0;
	virtual void onDraw(Renderer2D* renderer2D) = 0;
	virtual void onExit() = 0;
};