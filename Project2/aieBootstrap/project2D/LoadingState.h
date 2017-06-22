#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "LoadingLetters.h"

using namespace aie;
using namespace std;


class LoadingState : public BaseState
{
public:
	LoadingState();
	~LoadingState();

	void onEnter();
	void onUpdate(float deltaTime);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

	ObjectPool <LoadingLetters, 7> myLetterPool;

protected:
	Renderer2D*		m_Renderer;
	LoadingLetters* m_Letters;
};

