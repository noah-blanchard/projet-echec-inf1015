#pragma once
#include <vector>

namespace model {
	class ValidMovesCalculator
	{
	public:
			ValidMovesCalculator() = default;
			virtual ~ValidMovesCalculator() {};
			virtual std::vector<class Square*> calculate(Square* currentSquare, class Checker* checker, bool validate) = 0;
	};
}

