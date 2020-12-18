#pragma once
#include "GameObject.h"

#define JUMPER_WALKING_SPEED 0.03f
#define JUMPER_JUMP_X 0.03f
#define JUMPER_JUMP_Y 0.3f
#define JUMPER_GRAVITY 0.02f

#define JUMPER_BBOX_WIDTH 17
#define JUMPER_BBOX_HEIGHT 28
#define JUMPER_BBOX_HEIGHT_DIE 16

#define JUMPER_STATE_WALKING 100
#define JUMPER_STATE_JUMP_RIGHT 200
#define JUMPER_STATE_JUMP_LEFT 300

#define JUMPER_ANI_WALKING_RIGHT 0
#define JUMPER_ANI_WALKING_LEFT 1
#define JUMPER_ANI_JUMP_RIGHT 2
#define JUMPER_ANI_JUMP_LEFT 3

class CJumper : public CGameObject
{
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

public:
	CJumper(float x = 0.0f, float y = 0.0f);
	virtual void SetState(int state);
};