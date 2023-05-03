#pragma once
#include "ValidMovesCalculator.h"

namespace logic {
	class BishopMoves :
		public ValidMovesCalculator
	{
	public:
		BishopMoves() = default;
		~BishopMoves();
		std::vector<class ModelSquare*> calculate(ModelSquare* currentSquare, class ChessBoard* checker, bool validate) override;
	};
}

