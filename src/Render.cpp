#include "Render.h"
#include "Definitions.h"

SDL_Window* GetWindow()
{
	// Window has to be stored somewhere becouse we have to destroy it at the end
	static SDL_Window* window;

	if (!window)
	{
		window = SDL_CreateWindow("MoleFrog3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		assert(window != nullptr && "Window could not be created!");
	}

	return window;
}

SDL_Renderer* GetRenderer()
{
	static SDL_Renderer* renderer;

	if (!renderer)
	{
		renderer = SDL_CreateRenderer(GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		assert(renderer != nullptr && "Renderer could not be created!");
	}

	return renderer;
}

void RenderInit()
{
	GetWindow();
	GetRenderer();
}

void RenderTerminate()
{
	SDL_DestroyRenderer(GetRenderer());
	SDL_DestroyWindow(GetWindow());
}

void RenderBackground()
{
	SDL_SetRenderDrawColor(GetRenderer(), 255, 255, 255, 255);
	SDL_RenderPresent(GetRenderer());
	SDL_RenderClear(GetRenderer());
}

void DrawSquareWithTexture(SDL_Texture* texture, Vector2 position, Vector2 size)
{
	SDL_Rect dsrect = { position.x, position.y, size.x, size.y };
	assert(texture != nullptr && "Could not draw object, texture invalid!");
	SDL_RenderCopy(GetRenderer(), texture, NULL, &dsrect);
}

void DrawColoredSquare(SDL_Color color, Vector2 position, Vector2 size)
{
	SDL_Rect rect = { position.x, position.y, size.x, size.y };
	SDL_SetRenderDrawColor(GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(GetRenderer(), &rect);
}

void DrawText(TTF_Font* font, SDL_Color fontColor, Vector2 position, const char* text)
{
	SDL_Surface* surf;
	SDL_Texture* tex;
	SDL_Rect rect;

	surf = TTF_RenderText_Solid(font, text, fontColor);
	tex = SDL_CreateTextureFromSurface(GetRenderer(), surf);
	rect.x = position.x;
	rect.y = position.y;
	rect.w = surf->w;
	rect.h = surf->h;
	SDL_RenderCopy(GetRenderer(), tex, NULL, &rect);

	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
}