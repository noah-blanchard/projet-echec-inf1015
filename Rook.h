#pragma once
#include "Piece.h"
namespace model
{
	class Rook : public Piece
	{
	public:
		Rook(bool isWhite);

		std::vector<Square*> getMoves() override;

	private:
		ValidMoves* validMoves_;
	};
}

