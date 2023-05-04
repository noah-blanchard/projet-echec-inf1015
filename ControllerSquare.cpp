/**
 * @file ControllerSquare.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Controller for the View and Model Square
 * @date 20/04/2023
 */

#include "ControllerSquare.h"

namespace model {
	void ControllerSquare::clickSquareControl(Square* clickedSquare, Checker* checker)
	{
		checker->setSelectedSquare(clickedSquare);
		std::vector <Square*> validMoves = clickedSquare->getPiece()->getValidMoves2(checker, true);
		for (Square* square : validMoves)
		{
			square->setPlayable(true);	
		}
	}

	void ControllerSquare::clickSquareMove(Square* clickedSquare, Checker* checker)
	{
		
		//checker->getSelectedSquare()->getPiece()->move(clickedSquare);
		//if (true/*checker->validateMove(checker->getSelectedSquare(), clickedSquare*/) {
			clickedSquare->setPiece(checker->getSelectedSquare()->getPiece());
			checker->getSelectedSquare()->setPiece(nullptr);
			
			if (clickedSquare->getPiece()->isKing() && clickedSquare->getPiece()->isWhite())
				checker->setWhiteKingSquare(clickedSquare);
			else if (clickedSquare->getPiece()->isKing() && !clickedSquare->getPiece()->isWhite())
				checker->setBlackKingSquare(clickedSquare);

			checker->setSelectedSquare(nullptr);
			checker->resetPlayableSquares();
		//}
	}
}