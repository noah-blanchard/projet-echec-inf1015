
#pragma once
#include "Command.h"
namespace model
{
    class MovePieceCommand : public UserCommand
    {
    public:
        MovePieceCommand(Piece* piece, Square* newSquare);

        void execute() override;

        void cancel() override;

    private:
        Piece* piece_;
        std::vector<Square*> playableSquares_;
        Square* oldSquare_;
        Square* newSquare_;
    };
}

