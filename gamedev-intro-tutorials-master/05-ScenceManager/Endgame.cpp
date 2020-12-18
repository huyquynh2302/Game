#include "Endgame.h"
#include "Brick.h"

CEndgame::CEndgame(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CEndgame::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void CEndgame::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

}

void CEndgame::Render()
{
	int ani = END_IDLE;

	animation_set->at(ani)->Render(x, y);

	RenderBoundingBox();
}

void CEndgame::SetState(int state)
{
	CGameObject::SetState(state);
	state = END_STATE_IDLE;
}
