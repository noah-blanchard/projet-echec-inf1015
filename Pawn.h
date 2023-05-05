#pragma once
#include "Piece.h"
namespace model
{
	class Pawn : public Piece
	{
	public:
		Pawn(bool isWhite);

		std::vector<Square*> getMoves() override;

	private:
		ValidMoves* validMoves_;
	};
}

