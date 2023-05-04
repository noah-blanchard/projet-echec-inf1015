#include "GameTurn.h"

void model::GameTurn::selectPiece(Square* clickedSquare, Checker* checker)

{
	CommandsInvoker::executeCommand(new SelectPieceCommand(clickedSquare, checker));
}

void model::GameTurn::movePiece(Square* clickedSquare, Checker* checker)
{
	CommandsInvoker::executeCommand(new MovePieceCommand(clickedSquare, checker));
}
