/**
 * @file ControllerSquare.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Controller for the View and Model Square
 * @date 20/04/2023
 */

#pragma once
#include "ModelSquare.h"
#include "ModelChecker.h"
#include "ChessBoard.h"

namespace logic {
	class ControllerSquare
	{
	public:
		static void clickSquareControl(ModelSquare* clickedSquare, ChessBoard* checker);
		static void clickSquareMove(ModelSquare* clickedSquare, ModelChecker* checker);
	};
}

