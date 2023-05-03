#pragma once
#include "ValidMovesCalculator.h"

namespace logic {
	class KnightMoves :
		public ValidMovesCalculator
	{
	public:
		KnightMoves() = default;
		~KnightMoves();
		std::vector<class ModelSquare*> calculate(ModelSquare* currentSquare, class ChessBoard* checker, bool validate) override;
	};
}

