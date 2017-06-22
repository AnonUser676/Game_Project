#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "CollisionManager.h"
#include "Matrix3.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace aie;

class LoadingLetters : public Entity
{
public:
	LoadingLetters();
	virtual ~LoadingLetters();

	virtual void draw(Renderer2D* m_Renderer, int type);
	virtual void update(float deltaTime);

	float letterPos = 1000.0f;

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_Letters;
	Texture*		m_LettersL;
	Texture*		m_LettersO;
	Texture*		m_LettersA;
	Texture*		m_LettersD;
	Texture*		m_LettersI;
	Texture*		m_LettersN;
	Texture*		m_LettersG;
};

