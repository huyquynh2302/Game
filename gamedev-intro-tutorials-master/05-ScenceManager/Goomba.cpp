#include "Goomba.h"
#include "Brick.h"

CGoomba::CGoomba()
{
	//SetState(GOOMBA_STATE_WALKING_BOTTOM);
	//bottom = false;
	top = false;
	//left = true;
	right = false;
	bottom = true;
	left = false;
}

void CGoomba::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + GOOMBA_BBOX_WIDTH;

	/*if (state == GOOMBA_STATE_DIE)
		bottom = y + GOOMBA_BBOX_HEIGHT_DIE;
	else 	*/
		bottom = y + GOOMBA_BBOX_HEIGHT;
}

void CGoomba::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	CGameObject::Update(dt, coObjects);
	
	

	
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	
	// turn off collision when die 
	/*if (state != GOOMBA_STATE_DIE)*/
		CalcPotentialCollisions(coObjects, coEvents);
	
	if (coEvents.size() == 0)
	{
		
		if (bottom == true)
		{
			vy += GOOMBA_GRAVITY_X;
			
		}

		if(left == true)
		{
			vx -= GOOMBA_GRAVITY_Y;
		}

		if (top == true && vy == 0 )
		{
			vy -= GOOMBA_GRAVITY_Y;
		}

		else if (top == true && vy < 0)
		{
			this->SetState(GOOMBA_STATE_WALKING_LEFT);
			x += dx;
			y += dy;
			bottom = false;
			right = false;
			left = true;
			top = false;
		}

		if (right == true && vx == 0)
		{
			vx += GOOMBA_GRAVITY_X;
		}
		else if (right == true && vx > 0)
		{
			this->SetState(GOOMBA_STATE_WALKING_TOP);
			x += dx;
			y += dy;
			bottom = false;
			right = false;
			left = false;
			top = true;

		}
	}
	else
	{
		bottom = false;
		top = false;
		right = false;
		left = false;
		float min_tx, min_ty, nx = 0, ny;
		float rdx = 0;
		float rdy = 0;

		// TODO: This is a very ugly designed function!!!!
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);

		// how to push back Mario if collides with a moving objects, what if Mario is pushed this way into another object?
		//if (rdx != 0 && rdx!=dx)
		//	x += nx*abs(rdx); 

		// block every object first!
		x += min_tx * dx + nx * 0.13f;
		y += min_ty * dy + ny * 0.13f;

		if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;


		//
		// Collision logic with other objects
		//
		for (UINT i = 0; i <coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			if (dynamic_cast<CBrick*>(e->obj)) // if e->obj is Brick
			{
				
				CBrick* brick = dynamic_cast<CBrick*>(e->obj);
				/*if (e->ny > 0)
				{
					bottom = false;
					right = false;
					left = false;
					top = true;
					if (this->GetState()!= GOOMBA_STATE_WALKING_TOP)
					{
						this->SetState(GOOMBA_STATE_WALKING_TOP);
					}
				}
				else if (e->ny < 0)
				{
					bottom = true;
					top = false;
					right = false;
					left = false;
					if (this->GetState() != GOOMBA_STATE_WALKING_BOTTOM)
					{
						this->SetState(GOOMBA_STATE_WALKING_BOTTOM);
					}
				}
				else if(e->nx < 0)
				{
					bottom = false;
					top = false;
					right = true;
					left = false;
					if (this->GetState() != GOOMBA_STATE_WALKING_RIGHT)
					{
						this->SetState(GOOMBA_STATE_WALKING_RIGHT);
					}
				}
				else if (e->nx > 0)
				{
					left = true;
					bottom = false;
					top = false;
					right = false;
					if (this->GetState() != GOOMBA_STATE_WALKING_LEFT)
					{
						this->SetState(GOOMBA_STATE_WALKING_LEFT);
					}
				 }*/
					 
			} 
		}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void CGoomba::Render()
{
	int ani = GOOMBA_ANI_WALKING_BOTTOM;
	if (state == GOOMBA_STATE_WALKING_LEFT)
	{
		ani = GOOMBA_ANI_WALKING_LEFT;
	}
	else if (state == GOOMBA_STATE_WALKING_RIGHT)
	{
		ani = GOOMBA_ANI_WALKING_RIGHT;
	}
	else if (state == GOOMBA_STATE_WALKING_TOP)
	{
		ani = GOOMBA_ANI_WALKING_TOP;
	}
	

	animation_set->at(ani)->Render(x,y);

	RenderBoundingBox();
}

void CGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
		/*case GOOMBA_STATE_DIE:
			vx = 0;
			vy = 0;
			break;*/
		case GOOMBA_STATE_WALKING_BOTTOM: 
			vx = GOOMBA_WALKING_SPEED;
			vy = 0;
			break;
		case GOOMBA_STATE_WALKING_TOP: 
			vx = GOOMBA_WALKING_SPEED;
			vy = 0;
			break;
		case GOOMBA_STATE_WALKING_LEFT: 
			vy = -GOOMBA_WALKING_SPEED;
			vx = 0;
			break;
		case GOOMBA_STATE_WALKING_RIGHT: 
			vy = -GOOMBA_WALKING_SPEED;
			vx = 0;
			break;
	}
}
