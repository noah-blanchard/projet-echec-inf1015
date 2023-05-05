
#pragma once	
#include "CommandsInvoker.h"
namespace model
{
	class PlayerTurn
	{
	public:
		virtual void movePiece(Piece* piece, Square* selectedSquare);

		virtual void selectPiece(Piece* piece);

		virtual bool isGameOver() = 0;
	};
}
