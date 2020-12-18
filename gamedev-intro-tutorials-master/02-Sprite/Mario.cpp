#include "Game.h"
#include "Mario.h"

//CMario::CMario(float x, float y, float vx):CGameObject(x, y)
//{
//	this->vx = vx;
//};

void CMario::Update(DWORD dt)
{
	CGameObject::Update(dt);

	// simple fall down
	vy += MARIO_GRAVITY;
	if (y > 100)
	{
		vy = 0; y = 100.0f;
	}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;

	/*x += vx*dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}*/
}

void CMario::Render()
{
	//LPANIMATION ani;

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to Mario!!
	//if (vx>0) ani = CAnimations::GetInstance()->Get(500);
	//else ani = CAnimations::GetInstance()->Get(501);

	//ani->Render(x, y);

	int ani;
	if (vx == 0)
	{
		if (nx > 0) ani = MARIO_ANI_IDLE_RIGHT;
		else ani = MARIO_ANI_IDLE_LEFT;
	}
	else if (vx > 0)
		ani = MARIO_ANI_WALKING_RIGHT;
	else ani = MARIO_ANI_WALKING_LEFT;

	animations[ani]->Render(x, y);
}

void CMario::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		vx = MARIO_WALKING_SPEED;
		nx = 1;
		break;
	case MARIO_STATE_WALKING_LEFT:
		vx = -MARIO_WALKING_SPEED;
		nx = -1;
		break;
	case MARIO_STATE_JUMP:
		if (y == 100)
			vy = -MARIO_JUMP_SPEED_Y;

	case MARIO_STATE_IDLE:
		vx = 0;
		break;
	}
}