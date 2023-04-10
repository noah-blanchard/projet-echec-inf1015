#include "ControllerSquare.h"

namespace logic {
	void ControllerSquare::clickSquareControl(ModelSquare* clickedSquare, ModelChecker* checker)
	{
		checker->setSelectedSquare(clickedSquare);
		std::vector <ModelSquare*> validMoves = clickedSquare->getPiece()->getValidMoves(checker);
		for (ModelSquare* square : validMoves)
		{
			square->setPlayable(true);	
		}
	}

	void ControllerSquare::clickSquareMove(ModelSquare* clickedSquare, ModelChecker* checker)
	{
		
		//checker->getSelectedSquare()->getPiece()->move(clickedSquare);
		clickedSquare->setPiece(checker->getSelectedSquare()->getPiece());
		checker->getSelectedSquare()->setPiece(nullptr);
		checker->setSelectedSquare(nullptr);
		checker->resetPlayableSquares();
	}
}