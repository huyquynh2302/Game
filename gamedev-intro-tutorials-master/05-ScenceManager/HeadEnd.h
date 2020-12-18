#pragma once
#include "GameObject.h"

#define HEADEND_IDLE 0

#define HEADEND_STATE_IDLE	100


class CHeadEnd : public CGameObject
{


public:
	CHeadEnd(float x = 0.0f, float y = 0.0f);
	virtual void SetState(int state);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
};