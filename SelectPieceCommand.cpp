#include "SelectPieceCommand.h"

model::SelectPieceCommand::SelectPieceCommand(Square* clickedSquare, Checker* checker)
{
	checker->setSelectedSquare(clickedSquare);
	validMoves_ = clickedSquare->getPiece()->getValidMoves2(checker, true);
}

void model::SelectPieceCommand::execute()

{
	for (Square* square : validMoves_)
	{
		square->setPlayable(true);
	}
}

void model::SelectPieceCommand::cancel()

{
	for (Square* square : validMoves_)
	{
		square->setPlayable(false);
	}
}
