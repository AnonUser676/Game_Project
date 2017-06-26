#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "LoadingLetters.h"
#include "StateMachine.h"
#include "DynamicArray.h"

using namespace aie;
using namespace std;


class LoadingState : public BaseState
{
public:
	LoadingState();
	virtual ~LoadingState();

	void onEnter();
	void onUpdate(float deltaTime, StateMachine* State);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

	ObjectPool <LoadingLetters, 7> myLetterPool;

	float time;

protected:
	Renderer2D*		m_Renderer;
	DynamicArray<LoadingLetters*> m_Letters;
};

