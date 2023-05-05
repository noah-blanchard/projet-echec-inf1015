
#pragma once
#include "Command.h"
namespace model
{
    class SelectPieceCommand : public UserCommand
    {
    public:
        SelectPieceCommand(Piece* piece);

        void execute() override;

        void cancel() override;

    private:
		Piece* piece_;
        std::vector<Square*> validMoves_;
    };
}