#pragma once
#include "Enemy.h"

#define ENEMY_WIDTH 18
#define ENEMY_HEIGHT 20

#define ENEMY_X 10.0f
#define ENEMY_Y 100.0f

#define ENEMY_ANI_IDLE_RIGHT		0
#define ENEMY_ANI_IDLE_LEFT			1
#define ENEMY_ANI_WALKING_RIGHT		2
#define ENEMY_ANI_WALKING_LEFT		3

#define ENEMY_STATE_IDLE			0
#define ENEMY_STATE_WALKING_RIGHT	100
#define ENEMY_STATE_WALKING_LEFT	200

#define ENEMY_WALKING_SPEED		0.2f
#define ENEMY_JUMP_SPEED_Y		0.5f
#define ENEMY_GRAVITY			0.1f


class CEnemy1 : public CEnemy
{
protected:
	float x;
	float y;

	float vx;
	float vy;
public:
	//CEnemy1() :CEnemy() {};
	//CEnemy1(float x, float y, float vx);
	//void SetPosition() { this->x = ENEMY_X, this->y = ENEMY_Y; }
	//void SetSpeed() { this->vx = ENEMY_WALKING_SPEED, this->vy = 0.0f; }
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};
