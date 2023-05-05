#include "Piece.h"
#include "Square.h"
#include "ValidMoves.h"

namespace model
{
	Piece::Piece(bool isWhite) : isWhite_(isWhite) {}

	bool Piece::isWhite() const
	{
		return isWhite_;
	}
}