#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "CollisionManager.h"
#include "Matrix3.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace aie;

class SplashLetters : public Entity
{
public:
	SplashLetters();
	virtual ~SplashLetters();

	virtual void draw(Renderer2D* m_Renderer,int type);
	virtual void update(float deltaTime);

	float letterPos = 600.0f;

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_Letters;
	Texture*		m_LettersZ;
	Texture*		m_LettersE;
	Texture*		m_LettersR;
	Texture*		m_LettersO;
	Texture*		m_LettersEnt;
};

