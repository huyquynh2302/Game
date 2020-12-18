#include "Endgame1.h"
#include "Brick.h"

CEndgame1::CEndgame1(float x, float y)
{
	this->x = x;
	this->y = y;
	SetState(END_STATE_IDLE);
}

void CEndgame1::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void CEndgame1::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	x += dx;
	y += dy;
	
	if (time == TIME_DEFAULT) {
		time = GetTickCount();
	}
	if (GetTickCount() - time >= 1700 && state != END_STATE_WALK)
	{
		SetState(END_STATE_WALK);
	}
}

void CEndgame1::Render()
{
	int ani = END_WALK;

	animation_set->at(ani)->Render(x, y);

	RenderBoundingBox();
}

void CEndgame1::SetState(int state)
{
	CGameObject::SetState(state);
	if (state == END_STATE_IDLE)
	{
		vx = 0;
		vy = 0;
	}
	else if (state == END_STATE_WALK)
	{
		vx = 0;
		vy = SPEED;
	}
}
