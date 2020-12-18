#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"

#define ENEMY_SPEED_X 0.1f
#define ENEMY_SPEED_Y 0.1f
using namespace std;

class CEnemy
{
public:
	float x;
	float y;

	float vx;
	float vy;

	int nx;

	int state;

	static vector<LPANIMATION> animations1;
public:
	//CGameObject(float x, float y);

	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	//float GetX() { return x; }
	//float GetY() { return y; }

	//virtual void Update(DWORD dt) = 0;
	//virtual void Render() = 0;

	void SetSpeed(float vx, float vy){ this->vx = vx, this->vy = vy; }
	//float GetVX();
	void SetState(int state) { this->state = state; }
	int GetState() { return this->state; }


	static void AddAnimation(int aniId);

	CEnemy();

	void Update(DWORD dt);
	void Render();
	~CEnemy();
};

