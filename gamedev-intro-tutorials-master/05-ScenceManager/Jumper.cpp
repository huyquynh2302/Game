#include "Jumper.h"

CJumper::CJumper(float x, float y)
{
	this->x = x;
	this->y = y;
	SetState(JUMPER_STATE_WALKING);
}

void CJumper::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	/*left = x;
	top = y;
	right = x + JUMPER_BBOX_WIDTH;

	if (state == JUMPER_STATE_DIE)
		bottom = y + JUMPER_BBOX_HEIGHT_DIE;
	else
		bottom = y + JUMPER_BBOX_HEIGHT;*/
}

void CJumper::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure Koopas can interact with the world and to each of them too!
	// 

	x += vx * dt;
	y += vy * dt;

	vy += JUMPER_GRAVITY;

	if (vx < 0 && x < 0) {
		x = 0;
		vx = -vx;
		nx = 1;
	}

	if (vx > 0 && x > 532) {
		x = 532;
		vx = -vx;
		nx = -1;
	}
	if (y > 122)
	{
		y = 122;
	}
}

void CJumper::Render()
{
	int ani = JUMPER_ANI_WALKING_RIGHT;
	if (state == JUMPER_STATE_WALKING && vx < 0)
	{
		ani = JUMPER_ANI_WALKING_LEFT;
	}


	if (state == JUMPER_STATE_JUMP_RIGHT)
	{
		ani = JUMPER_ANI_JUMP_RIGHT;
	}
	else if (state == JUMPER_STATE_JUMP_LEFT)
	{
		ani = JUMPER_ANI_JUMP_LEFT;
	}

	animation_set->at(ani)->Render(x, y);

	RenderBoundingBox();
}

void CJumper::SetState(int state)
{
	CGameObject::SetState(state);
	/*switch (state)
	{
	case JUMPER_STATE_JUMP_RIGHT:
		vx = JUMPER_JUMP_SPEED_X;
		vy = -JUMPER_JUMP_SPEED_Y;
		break;
	case JUMPER_STATE_JUMP_LEFT:
		vx = -JUMPER_JUMP_SPEED_X;
		vy = -JUMPER_JUMP_SPEED_Y;
		break;
	case JUMPER_STATE_WALKING:
		vx = JUMPER_WALKING_SPEED;
		break;
	}*/
	if (state == JUMPER_STATE_WALKING) {
		if (nx == 1) {
			vx = JUMPER_WALKING_SPEED;
		}
		else
		{
			vx = -JUMPER_WALKING_SPEED;
		}

		vy = 0;
	}
	else if (state == JUMPER_STATE_JUMP_RIGHT) {
		nx = 1;
		vx = JUMPER_JUMP_X;
		vy = -JUMPER_JUMP_Y;
	}
	else if (state == JUMPER_STATE_JUMP_LEFT) {
		nx = -1;
		vx = -JUMPER_JUMP_X;
		vy = -JUMPER_JUMP_Y;
	}

}