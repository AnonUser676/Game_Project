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

	virtual void draw(Renderer2D* m_Renderer);
	virtual void update(float deltaTime);

	Vector2 velocity;
	float time;
	bool checker;
	float ticker;

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_Letters;
};

