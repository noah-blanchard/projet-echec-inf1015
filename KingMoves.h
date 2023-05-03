#pragma once
#include "ValidMovesCalculator.h"

namespace logic {
	class KingMoves :
		public ValidMovesCalculator
	{
	public:
		KingMoves() = default;
		~KingMoves();
		std::vector<class ModelSquare*> calculate(ModelSquare* currentSquare, class ModelChecker* checker, bool validate) override;
	};
}

