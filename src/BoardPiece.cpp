#include "BoardPiece.h"
#include "Render.h"

BoardPiece::BoardPiece(Vector2 position, Vector2 size)
{
	color = { 255,255,255,255 };
	SetNewPosition(position);
	SetNewSize(size);
}

void BoardPiece::SetNewPosition(Vector2 position)
{
	shape.x = position.x;
	shape.y = position.y;
}

void BoardPiece::SetNewSize(Vector2 size)
{
	shape.w = size.x;
	shape.h = size.y;
}

void BoardPiece::Draw()
{
	DrawColoredSquare(color, { shape.x, shape.y }, { shape.w, shape.h });
}
