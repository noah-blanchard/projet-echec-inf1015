#pragma once
#include "ValidMovesCalculator.h"

namespace model {
	class BishopMoves :
		public ValidMovesCalculator
	{
	public:
		BishopMoves() = default;
		std::vector<class Square*> calculate(Square* currentSquare, class Checker* checker, bool validate) override;
	};
}

