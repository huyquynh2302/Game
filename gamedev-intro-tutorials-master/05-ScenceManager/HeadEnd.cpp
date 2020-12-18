#include "HeadEnd.h"
#include "Brick.h"

CHeadEnd::CHeadEnd(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CHeadEnd::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void CHeadEnd::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

}

void CHeadEnd::Render()
{
	int ani = HEADEND_IDLE;

	animation_set->at(ani)->Render(x, y);

	RenderBoundingBox();
}

void CHeadEnd::SetState(int state)
{
	CGameObject::SetState(state);
	state = HEADEND_STATE_IDLE;
}
