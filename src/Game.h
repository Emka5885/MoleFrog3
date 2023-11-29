#pragma once
#include "AssetManager.h"
#include "Board.h"
#include "Button.h"

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

	void Start();
	void Stop();

private:
	AssetManager* assets;

	Board* board;
	int testCounter = 3;

	Button* startButton;
	Button* stopButton;

	bool quitt = false;
};