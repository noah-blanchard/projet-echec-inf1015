#include "PlayerTurn.h"
#include "Piece.h"
#include "Square.h"
#include "MovePieceCommand.h"
#include "SelectPieceCommand.h"

namespace model
{
	void PlayerTurn::movePiece(Piece* piece, Square* selectedSquare)
	{
		CommandsInvoker::executeCommand(std::make_shared<MovePieceCommand>(piece, selectedSquare));
	}

	void PlayerTurn::selectPiece(Piece* piece)
	{
		CommandsInvoker::executeCommand(std::make_shared<SelectPieceCommand>(piece));
	}
}