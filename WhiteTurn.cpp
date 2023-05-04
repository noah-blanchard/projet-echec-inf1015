#include "WhiteTurn.h"

void model::WhiteTurn::selectPiece(Square* clickedSquare, Checker* checker)

{
	if (clickedSquare->getPiece()->isWhite())
	{
		GameTurn::selectPiece(clickedSquare, checker);
	}
}

void model::WhiteTurn::movePiece(Square* clickedSquare, Checker* checker)
{
	GameTurn::movePiece(clickedSquare, checker);
}

bool model::WhiteTurn::isGameOver(Checker* checker, bool& isGameOver)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			std::shared_ptr<Piece> piece = checker->getSquareAtPosition(i, j)->getPiece();

			if (piece != nullptr && piece->isWhite() && !piece->getValidMoves2(checker, true).empty())
			{
				return isGameOver = false;
			}
		}
	}

	return isGameOver = true;
}
