#include "Game.h"
#include "Enemy1.h"

//CEnemy1::CEnemy1(float x, float y, float vx) :CEnemy(x, y)
//{
//	this->vx = vx;
//};
//CEnemy1::CEnemy1()
//{
//	this->x = ENEMY_X;
//	this->y = ENEMY_Y;
//	this->vx = ENEMY_WALKING_SPEED;
//	this->vy = 0.0f;
//}

void CEnemy1::Update(DWORD dt)
{
	CEnemy::GetVX();
	CEnemy::Update(dt);
	
	//Ngang
	//CEnemy1::SetPosition();
	//CEnemy1::SetSpeed();
	//x += vx * dt;
	//y += vy * dt;
	//vx = ENEMY_WALKING_SPEED;

	//int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= 290) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= 290)
		{
			x = (float)(290);
		}
	}
	
	//Doc
	/*y += vx * dt;

	int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();
	if (y <= 0 || y >= BackBufferHeight - ENEMY_HEIGHT) {

		vx = -vx;

		if (y <= 0)
		{
			y = 0;
		}
		else if (y >= BackBufferHeight - ENEMY_HEIGHT)
		{
			y = (float)(BackBufferHeight - ENEMY_HEIGHT);
		}
	}*/
}

void CEnemy1::Render()
{
	

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to Mario!!
	//if (vx > 0) ani = CAnimations::GetInstance()->Get(500);
	//else ani = CAnimations::GetInstance()->Get(501);
	//vector<LPANIMATION> animations;
	int ani;
	if (vx == 0)
	{
		if (nx > 0) ani = ENEMY_ANI_IDLE_RIGHT;
		else ani = ENEMY_ANI_IDLE_LEFT;
	}
	else if (vx > 0)
		ani = ENEMY_ANI_WALKING_RIGHT;
	else ani = ENEMY_ANI_WALKING_LEFT;

	animations[ani]->Render(x, y);
}

void CEnemy1::SetState(int state)
{
	CEnemy::SetState(state);
	switch (state)
	{
	case ENEMY_STATE_WALKING_RIGHT:
		vx = ENEMY_WALKING_SPEED;
		nx = 1;
		break;
	case ENEMY_STATE_WALKING_LEFT:
		vx = -ENEMY_WALKING_SPEED;
		nx = -1;
		break;

	case ENEMY_STATE_IDLE:
		vx = 0;
		break;
	}
}