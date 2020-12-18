#pragma once
#include "GameObject.h"

#define Intro_IDLE 0

#define Intro_STATE_IDLE	100


class CIntro : public CGameObject
{


public:
	CIntro(float x = 0.0f, float y = 0.0f);
	virtual void SetState(int state);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
};