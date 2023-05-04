#pragma once
#include "ValidMovesCalculator.h"

namespace model {
	class KingMoves :
		public ValidMovesCalculator
	{
	public:
		KingMoves() = default;
		//~KingMoves();
		std::vector<class Square*> calculate(Square* currentSquare, class Checker* checker, bool validate) override;
	};
}

