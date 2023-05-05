#include "Knight.h"
#include "KnightMoves.h"
#include "Square.h"
#include "ChessBoard.h"

namespace model
{
	Knight::Knight(bool isWhite)
		: Piece(isWhite), validMoves_(new KnightMoves(this))
	{
	}

	std::vector<Square*> Knight::getMoves()
	{
		return validMoves_->get();
	}
}