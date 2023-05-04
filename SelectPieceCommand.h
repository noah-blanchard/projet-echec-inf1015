#pragma once
#include "Command.h"

namespace model {
	class SelectPieceCommand : public Command
	{
	public:
		SelectPieceCommand(Square* clickedSquare, Checker* checker);

		void execute() override;

		void cancel() override;

	private:
		std::vector <Square*> validMoves_;
	};
}

