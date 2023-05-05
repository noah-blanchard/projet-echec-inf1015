#include "Rook.h"
#include "RookMoves.h"
#include "Square.h"
#include "ChessBoard.h"

namespace model
{
	Rook::Rook(bool isWhite)
		: Piece(isWhite), validMoves_(new RookMoves(this))
	{
	}

	std::vector<Square*> Rook::getMoves()
	{
		return validMoves_->get();
	}
}