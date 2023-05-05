#pragma once
#include "ValidMovesCalculator.h"

namespace model {
	class KingMoves :
		public ValidMovesCalculator
	{
	public:
		KingMoves() = default;
		std::vector<class Square*> calculate(Square* currentSquare, class Checker* checker, bool validate) override;
	};
}

