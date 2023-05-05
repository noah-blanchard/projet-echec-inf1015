#pragma once
#include "Piece.h"
namespace model
{
	class Queen : public Piece
	{
	public:
		Queen(bool isWhite);

		std::vector<Square*> getMoves() override;

	private:
		ValidMoves* validMoves_;
	};
}

