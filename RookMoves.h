#pragma once
#include "ValidMovesCalculator.h"

namespace logic {
    class RookMoves :
        public ValidMovesCalculator
    {
    public:
		RookMoves() = default;
		~RookMoves();
		std::vector<class ModelSquare*> calculate(ModelSquare* currentSquare, class ModelChecker* checker, bool validate) override;
    };
}

