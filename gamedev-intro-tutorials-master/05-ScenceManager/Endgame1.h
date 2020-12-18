#pragma once
#include "GameObject.h"
#define TIME_DEFAULT	0
#define SPEED 0.008f

//#define END_IDLE 0
#define END_WALK 0

#define END_STATE_IDLE	100
#define END_STATE_WALK	200


class CEndgame1 : public CGameObject
{
public:
	DWORD time = TIME_DEFAULT;
public:
	CEndgame1(float x = 0.0f, float y = 0.0f);
	virtual void SetState(int state);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
};