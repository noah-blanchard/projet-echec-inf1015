#pragma once
#include "GameTurn.h"

namespace model {
	class Checkmate : public GameTurn
	{
	public:
		void selectPiece(Square* clickedSquare, Checker* checker) override;

		void movePiece(Square* clickedSquare, Checker* checker) override;

		bool isGameOver(Checker* checker, bool& isGameOver) override;
	};
}

