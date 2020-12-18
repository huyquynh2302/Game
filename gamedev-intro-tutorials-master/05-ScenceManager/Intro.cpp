#include "Intro.h"
#include "Brick.h"

CIntro::CIntro(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CIntro::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void CIntro::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

}

void CIntro::Render()
{
	int ani = Intro_IDLE;

	animation_set->at(ani)->Render(x, y);

	RenderBoundingBox();
}

void CIntro::SetState(int state)
{
	CGameObject::SetState(state);
	state = Intro_STATE_IDLE;
}
