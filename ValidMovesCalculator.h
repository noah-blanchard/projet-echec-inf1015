#pragma once
#include <vector>

namespace logic {
	class ValidMovesCalculator
	{
	public:
			ValidMovesCalculator() = default;
			~ValidMovesCalculator();
			virtual std::vector<class ModelSquare*> calculate(ModelSquare* currentSquare, class ModelChecker* checker, bool validate) = 0;
	};
}

