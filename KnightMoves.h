#pragma once
#include "ValidMovesCalculator.h"

namespace model {
	class KnightMoves :
		public ValidMovesCalculator
	{
	public:
		KnightMoves() = default;
		std::vector<class Square*> calculate(Square* currentSquare, class Checker* checker, bool validate) override;
	};
}

