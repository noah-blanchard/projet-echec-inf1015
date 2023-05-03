#pragma once
#include "ValidMovesCalculator.h"

namespace logic {
	class PawnMoves :
		public ValidMovesCalculator
	{
	public:
		PawnMoves() = default;
		~PawnMoves();
		std::vector<class ModelSquare*> calculate(ModelSquare* currentSquare, class ModelChecker* checker, bool validate) override;
	};
}



