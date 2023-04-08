#pragma once
#include "ModelSquare.h"

namespace logic {
	//class ModelSquare;
	class ModelChecker
	{
	public:
		ModelChecker();
		~ModelChecker();
		ModelSquare* getSquareAtPosition(int x, int y) const;
	private:
		ModelSquare* squares[8][8];
	};
}

