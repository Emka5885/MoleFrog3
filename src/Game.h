#pragma once
#include "AssetManager.h"
#include "Board.h"

class Game
{
public:
	Game();
	~Game();
	void Init();
	void Loop();
	void Input();
	void Update();
	void Draw();

private:
	AssetManager* assets;

	Board* board;
	int testCounter = 3;

	bool quitt = false;
};