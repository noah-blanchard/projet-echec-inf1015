#pragma once
#include "Piece.h"

namespace model
{
	class Bishop : public Piece
	{
	public:
		Bishop(bool isWhite);

		std::vector<Square*> getMoves() override;

	private:
		ValidMoves* validMoves_;
	};
}

