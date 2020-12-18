#pragma once
#include "GameObject.h"

#define END_IDLE 0

#define END_STATE_IDLE	100


class CEndgame : public CGameObject
{


public:
	CEndgame(float x = 0.0f, float y = 0.0f);
	virtual void SetState(int state);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
};