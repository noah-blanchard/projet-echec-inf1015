#include "WhiteTurn.h"
#include "Piece.h"
#include "ChessBoard.h"
#include "Square.h"

namespace model
{
	void WhiteTurn::selectPiece(Piece* piece)
	{
		if (piece->isWhite())
		{
			PlayerTurn::selectPiece(piece);
		}
		else
		{
			// send warning
		}
	}

	void WhiteTurn::movePiece(Piece* piece, Square* selectedSquare)
	{
		if (piece->isWhite())
		{
			PlayerTurn::movePiece(piece, selectedSquare);
		}
		else
		{
			// send warning
		}
	}

	bool WhiteTurn::isGameOver()
	{
		std::vector<Square*> enemiesMove = ChessBoard::getEnemiesMoves(false);

		return enemiesMove.empty();
	}
}