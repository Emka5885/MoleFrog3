#pragma once
#include <SDL.h>
#include "Vector2.h"

class BoardPiece
{
private:
	SDL_Rect shape;
	SDL_Color color;

public:
	BoardPiece(Vector2 position, Vector2 size);

	void SetNewPosition(Vector2 position);
	void SetNewSize(Vector2 size);

	void Draw();
};