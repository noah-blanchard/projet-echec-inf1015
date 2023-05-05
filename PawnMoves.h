
#pragma once
#include "ValidMoves.h"
namespace model
{
	class PawnMoves : public ValidMoves
	{
	public:
		PawnMoves(Piece* piece);

		std::vector<Square*> get() override;

		std::vector<Square*> guess() override;
		

	private:
		Piece* piece_;
		static bool hasMoved_;
	};
}

