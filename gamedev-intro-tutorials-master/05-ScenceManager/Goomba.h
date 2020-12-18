#pragma once
#include "GameObject.h"

#define GOOMBA_WALKING_SPEED 0.1f;
#define GOOMBA_GRAVITY_X 0.01f;
#define GOOMBA_GRAVITY_Y 0.01f;

#define GOOMBA_BBOX_WIDTH 18
#define GOOMBA_BBOX_HEIGHT 18
#define GOOMBA_BBOX_HEIGHT_DIE 9

#define GOOMBA_STATE_WALKING_LEFT 100
#define GOOMBA_STATE_WALKING_TOP 200
#define GOOMBA_STATE_WALKING_RIGHT 300
#define GOOMBA_STATE_WALKING_BOTTOM 400


#define GOOMBA_ANI_WALKING_LEFT 0
#define GOOMBA_ANI_WALKING_TOP 1
#define GOOMBA_ANI_WALKING_RIGHT 2
#define GOOMBA_ANI_WALKING_BOTTOM 3



class CGoomba : public CGameObject
{
	

public: 	
	bool top;
	bool bottom;
	bool right;
	bool left;
	CGoomba();
	virtual void SetState(int state);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
};