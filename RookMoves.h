#pragma once
#include "ValidMovesCalculator.h"

namespace model {
    class RookMoves :
        public ValidMovesCalculator
    {
    public:
		RookMoves() = default;
		std::vector<class Square*> calculate(Square* currentSquare, class Checker* checker, bool validate) override;
    };
}

