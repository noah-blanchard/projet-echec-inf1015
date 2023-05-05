
#pragma once
#include "PlayerTurn.h"
namespace model
{
	class BlackTurn : public PlayerTurn
	{
	public:
		void selectPiece(Piece* piece) override;

		void movePiece(Piece* piece, Square* selectedSquare) override;

		bool isGameOver() override;
	};
}
