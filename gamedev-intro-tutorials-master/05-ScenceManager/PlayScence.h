#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scence.h"
#include "GameObject.h"
#include "Brick.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopas.h"
#include "Jumper.h"
#include "Intro.h"
#include "Endgame.h"
#include "HeadEnd.h"
#include "Endgame1.h"
#include "Endgame3.h"

#define SPEED_CAM 0.05f;

class CPlayScene: public CScene
{
protected: 
	CMario *player;					// A play scene has to have player, right? 
	CJumper* jumper;
	CIntro* intro;
	CEndgame* endgame;
	CEndgame1* endgame1;
	CEndgame3* endgame3;
	CHeadEnd* headend;
	vector<LPGAMEOBJECT> objects;

	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_ANIMATION_SETS(string line);
	void _ParseSection_OBJECTS(string line);

	float xc = 0.0f;
	float yc = 0.0f;

	
public: 
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	CMario * GetPlayer() { return player; } 

	//friend class CPlayScenceKeyHandler;
};

class CPlayScenceKeyHandler : public CScenceKeyHandler
{
public: 
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode) {};
	CPlayScenceKeyHandler(CScene *s) :CScenceKeyHandler(s) {};
};

