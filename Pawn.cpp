#include "Pawn.h"
#include "ValidMoves.h"
#include "Square.h"
#include "ChessBoard.h"

namespace model
{
	Pawn::Pawn(bool isWhite) : Piece(isWhite) {}

	std::vector<Square*> Pawn::getMoves()
	{
		return validMoves_->get();
	}
}