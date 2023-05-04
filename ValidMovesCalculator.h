#pragma once
#include <vector>

namespace model {
	class ValidMovesCalculator
	{
	public:
			ValidMovesCalculator() = default;
			~ValidMovesCalculator();
			virtual std::vector<class Square*> calculate(Square* currentSquare, class Checker* checker, bool validate) = 0;
	};
}

