#pragma once
#include "CommandsInvoker.h"
#include "SelectPieceCommand.h"*
#include "MovePieceCommand.h"*

namespace model {
	class GameTurn
	{
	public:
		virtual ~GameTurn() = default;

		virtual void selectPiece(Square* clickedSquare, Checker* checker);

		virtual void movePiece(Square* clickedSquare, Checker* checker);

		virtual bool isGameOver(Checker* checker, bool& isGameOver) = 0;
	};
}

