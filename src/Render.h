#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cassert>
#include <string>
#include "Vector2.h"

SDL_Window* GetWindow();
SDL_Renderer* GetRenderer();

void RenderInit();
void RenderTerminate();

void RenderBackground();

void DrawSquareWithTexture(SDL_Texture* texture, Vector2 position, Vector2 size);
void DrawColoredSquare(SDL_Color color, Vector2 position, Vector2 size);
void DrawText(TTF_Font* font, SDL_Color fontColor, Vector2 position, const char* text);