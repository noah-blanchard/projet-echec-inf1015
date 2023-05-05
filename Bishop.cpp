#include "Bishop.h"
#include "BishopMoves.h"
#include "Square.h"
#include "ChessBoard.h"

namespace model
{
	Bishop::Bishop(bool isWhite)
		: Piece(isWhite), validMoves_(new BishopMoves(this))
	{
	}

	std::vector<Square*> Bishop::getMoves()
	{
		return validMoves_->get();
	}
}