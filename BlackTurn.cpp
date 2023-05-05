#include "BlackTurn.h"
#include "ChessBoard.h"
#include "Piece.h"
#include "Square.h"

namespace model
{
	void BlackTurn::selectPiece(Piece* piece)
	{
		if (!piece->isWhite())
		{
			PlayerTurn::selectPiece(piece);
		}
		else
		{
			// send warning
		}
	}

	void BlackTurn::movePiece(Piece* piece, Square* selectedSquare)
	{
		if (!piece->isWhite())
		{
			PlayerTurn::movePiece(piece, selectedSquare);
		}
		else
		{
			// send warning
		}
	}

	bool BlackTurn::isGameOver()
	{
		auto enemiesMove = ChessBoard::getEnemiesMoves(true);

		return enemiesMove.empty();
	}
}