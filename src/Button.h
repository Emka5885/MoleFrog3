#pragma once
#include <SDL.h>
#include "Collider.h"
#include "Definitions.h"
#include "Vector2.h"
#include "AssetManager.h"
#include <string>
#include <functional>

class Button
{
private:
	int zoom;
	SDL_Rect rect;
	SDL_Color fontColor;
	SDL_Color unhoverColor;
	SDL_Color hoverColor;
	SDL_Color clickColor;
	Vector2 unhoverSize;
	Vector2 hoverSize;
	Vector2 unhoverPosition;
	Vector2 hoverPosition;
	ButtonTypes buttonType;
	const char* buttonText;

	std::function<void()> OnClick;

	TTF_Font* font;
	Collider* collider;

public:
	Button(Vector2 unhoverSize, SDL_Color unhoverColor, SDL_Color fontColor, const char* buttonText, TTF_Font* font, Vector2 unhoverPosition, std::function<void()> callback);

	void Init();
	void CheckIfHovered(Vector2 mousePos);
	void ChangeHover();
	void SetClicked(bool ifClicked);

	void Draw();

	SDL_Color GetCurrentColor();
	Vector2& GetCurrentPosition();
	Vector2& GetCurrentSize();

	void CheckIfClicked(Vector2 mousePos);
};