#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "Enemy.h"
#include "Sprites.h"

vector<LPANIMATION> CEnemy::animations;

CEnemy::CEnemy()
{
	//x = y = 0;
	//vx = vy = 0;
	nx = 1;
}

void CEnemy::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CEnemy::SetSpeed(float vx, float vy)
{
	this->vx = vx;
	this->vy = vy;
}

float CEnemy::GetVX()
{
	return vx;
}

void CEnemy::Update(DWORD dt)
{
	x += vx * dt;
	y += vx * dt;
}

void CEnemy::Render()
{
}

void CEnemy::AddAnimation(int aniId)
{
	//vector<LPANIMATION> animations;
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}



CEnemy::~CEnemy()
{
}