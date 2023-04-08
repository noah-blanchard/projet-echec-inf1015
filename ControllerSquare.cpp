#include "ControllerSquare.h"

namespace logic {
	void ControllerSquare::clickSquareControl(ModelSquare* clickedSquare, ModelChecker* checker)
	{
		std::vector <ModelSquare*> validMoves = clickedSquare->getPiece()->getValidMoves(clickedSquare, checker);
		for (ModelSquare* square : validMoves)
		{
			square->setPlayable();	
		}
	}
}