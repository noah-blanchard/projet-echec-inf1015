#include "Queen.h"
#include "QueenMoves.h"
#include "Square.h"
#include "ChessBoard.h"

namespace model
{
	Queen::Queen(bool isWhite)
		: Piece(isWhite), validMoves_(new QueenMoves(this))
	{
	}

	std::vector<Square*> Queen::getMoves()
	{
		return validMoves_->get();
	}

}
