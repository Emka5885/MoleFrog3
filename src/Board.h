#pragma once
#include "BoardPiece.h"
#include <vector>

class Board
{
private:
	int gridWidth;
	int numOfPiecesInLine = 1;
	SDL_Rect board;

public:
	Board();

	void CalculateNewBoardGrid(int numberOfPiece);

	void Draw();

	const int& GetNumOfPiecesInLine() { return numOfPiecesInLine; }

	std::vector<BoardPiece*> boardPieces;
};