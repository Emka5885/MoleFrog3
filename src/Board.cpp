#include "Board.h"
#include "Definitions.h"
#include "Render.h"
#include <cmath>

Board::Board()
{
	gridWidth = DEFAULT_GRID_WIDTH;
	board.x = board.y = 0;
	board.h = board.w = HEIGHT;
	CalculateNewBoardGrid(DEFAULT_NUMBER_OF_BOARD_PIECES);
}

void Board::CalculateNewBoardGrid(int numberOfPiece)
{
	if (numberOfPiece == boardPieces.size())
		return;

	numOfPiecesInLine = sqrt(numberOfPiece);
	int pieceSize = board.w / numOfPiecesInLine - gridWidth * 2;

	int counter = 0;
	for (int i = 0; i < numOfPiecesInLine; i++)
	{
		for (int j = 0; j < numOfPiecesInLine; j++)
		{
			if (counter < boardPieces.size())
			{
				boardPieces[i * numOfPiecesInLine + j]->SetNewPosition({ gridWidth + (pieceSize + gridWidth * 2) * j, gridWidth + (pieceSize + gridWidth * 2) * i });
				boardPieces[i * numOfPiecesInLine + j]->SetNewSize({ pieceSize, pieceSize });
			}
			else
			{
				Vector2 position = { gridWidth + (pieceSize + gridWidth * 2) * j, gridWidth + (pieceSize + gridWidth * 2) * i };
				BoardPiece* b = new BoardPiece(position, { pieceSize, pieceSize });
				boardPieces.emplace_back(b);
			}
			counter++;
		}
	}

	if (counter < boardPieces.size())
	{
		boardPieces.erase(boardPieces.begin() + counter, boardPieces.end());
	}
}

void Board::Draw()
{
	DrawColoredSquare({ 0,0,0,255 }, { board.x, board.y }, { board.w, board.h });

	for (int i = 0; i < boardPieces.size(); i++)
	{
		boardPieces[i]->Draw();
	}
}
