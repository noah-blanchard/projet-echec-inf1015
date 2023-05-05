#pragma once
#include "Piece.h"
namespace model
{
	class Knight : public Piece
	{
	public:
		Knight(bool isWhite);

		std::vector<Square*> getMoves() override;
	private:
		ValidMoves* validMoves_;
	};
}


