#pragma once
#include "Piece.h"
namespace model
{
	class King : public Piece
	{
	public:
		King(bool isWhite);

		std::vector<Square*> getMoves() override;

	private:
		ValidMoves* validMoves_;
	};
}

