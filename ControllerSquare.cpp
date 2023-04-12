#include "ControllerSquare.h"

namespace logic {
	void ControllerSquare::clickSquareControl(ModelSquare* clickedSquare, ModelChecker* checker)
	{
		checker->setSelectedSquare(clickedSquare);
		std::vector <ModelSquare*> validMoves = clickedSquare->getPiece()->getValidMoves(checker, true);
		for (ModelSquare* square : validMoves)
		{
			square->setPlayable(true);	
		}
	}

	void ControllerSquare::clickSquareMove(ModelSquare* clickedSquare, ModelChecker* checker)
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