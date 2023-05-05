#include "King.h"
#include "Square.h"
#include "KingMoves.h"
#include "ChessBoard.h"
namespace model
{
	King::King(bool isWhite)
		: Piece(isWhite), validMoves_(new KingMoves(this))
	{
	}
	std::vector<Square*> King::getMoves()
	{
		return validMoves_->get();
	}
}
