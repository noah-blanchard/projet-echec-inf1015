#pragma once
#include "ValidMovesCalculator.h"

namespace model {
	class PawnMoves :
		public ValidMovesCalculator
	{
	public:
		PawnMoves() = default;
		std::vector<class Square*> calculate(Square* currentSquare, class Checker* checker, bool validate) override;
	};
}



