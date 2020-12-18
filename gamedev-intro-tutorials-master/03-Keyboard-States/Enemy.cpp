#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "Enemy.h"
#include "Sprites.h"

vector<LPANIMATION> CEnemy::animations1;

CEnemy::CEnemy()
{
	nx = 1;
	vx = 0.07f;
	vy = 0.07f;
	x = 0;
	y = 0;
}
//float CEnemy::GetVX()
//{
//	return vx;
//}

void CEnemy::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

}

void CEnemy::Render()
{
}

void CEnemy::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	animations1.push_back(ani);
}



CEnemy::~CEnemy()
{
}