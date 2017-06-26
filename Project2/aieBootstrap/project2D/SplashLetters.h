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

	virtual void draw(Renderer2D* m_Renderer);
	virtual void update(float deltaTime);

	float letterPos;
	Vector2 velocity;

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_Letters;
};

