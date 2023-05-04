#pragma once
#include "Command.h"

namespace model {
	class MovePieceCommand : public Command
	{
	public:
		MovePieceCommand(Square* clickedSquare, Checker* checker) :
			clickedSquare_(clickedSquare),
			checker_(checker) {}

		void execute() override;

		void cancel() override;

	private:
		Square* clickedSquare_;
		Checker* checker_;
		std::shared_ptr<Piece> clickedSquarePiece_;
		std::shared_ptr<Piece> checkerPiece_;
		std::vector <Square*> playableSquareToReset_;
		Square* checkerSquare_;
		Square* whiteKingSquare_;
		Square* blackKingSquare_;

	};
}
