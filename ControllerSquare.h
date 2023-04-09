#pragma once
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	class ControllerSquare
	{
	public:
		static void clickSquareControl(ModelSquare* clickedSquare, ModelChecker* checker);
		static void clickSquareMove(ModelSquare* clickedSquare, ModelChecker* checker);
	};
}

