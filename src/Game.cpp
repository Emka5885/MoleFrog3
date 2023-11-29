#include "Game.h"
#include <SDL.h>
#include <ctime>
#include <fstream>
#include "Render.h"
#include "Definitions.h"

Game::Game()
{
	//SDL Init
	int result = SDL_Init(SDL_INIT_VIDEO);
	assert(result == 0 && "SDL could not initialize!");
	//TTF Init
	result = TTF_Init();
	assert(result == 0 && "Font could not initialize!");
	//SDL_Image Init
	int imgFlags = IMG_INIT_PNG;
	int imgInitResult = IMG_Init(imgFlags);
	assert((imgInitResult & imgFlags) == imgFlags && "SDL_Image could not initialize!");

	assets = new AssetManager();
	board = new Board();
	startButton = new Button({ 200,75 }, { 255,255,255,255 }, { 0,0,0,255 }, "Start", assets->GetFont(FONT), { WIDTH - 150, 50 }, [&]{Start();} );
	stopButton = new Button({ 200,75 }, { 255,255,255,255 }, { 0,0,0,255 }, "Stop", assets->GetFont(FONT), { WIDTH - 150, 130 }, [&]{Stop();} );
}

Game::~Game()
{
	RenderTerminate();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Game::Init()
{
	srand(time(NULL));

	//Render Init
	RenderInit();
}

void Game::Loop()
{
	float dt = (float)(SDL_GetTicks() / 1000.f);
	float lastTime = 0.f;
	const float DESIRED_DT = 1 / 60.f; // 60 FPS 

	while (!quitt)
	{
		dt = (SDL_GetTicks() - lastTime) / 1000;

		if (dt >= DESIRED_DT)
		{
			Input();
			Update();

			lastTime = (float)SDL_GetTicks();

			Draw();
		}
	}
}

void Game::Input()
{
	Vector2 mousePosition;
	SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			quitt = true;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quitt = true;
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				if (board->GetNumOfPiecesInLine() > 3)
				{
					testCounter--;
					board->CalculateNewBoardGrid(testCounter * testCounter);
				}
			}
			if (event.key.keysym.sym == SDLK_UP)
			{
				if (board->GetNumOfPiecesInLine() < 22)
				{
					testCounter++;
					board->CalculateNewBoardGrid(testCounter * testCounter);
				}
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				startButton->CheckIfClicked(mousePosition);
				stopButton->CheckIfClicked(mousePosition);
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				startButton->SetClicked(false);
				stopButton->SetClicked(false);
			}
			break;
		}
	}

	startButton->CheckIfHovered(mousePosition);
	stopButton->CheckIfHovered(mousePosition);
}

void Game::Update()
{
}

void Game::Draw()
{
	RenderBackground();
	board->Draw();
	startButton->Draw();
	stopButton->Draw();
}

void Game::Start()
{
}

void Game::Stop()
{
}
