#include "SelectPieceCommand.h"
#include "Piece.h"
#include "Square.h"
#include "ValidMoves.h"

namespace model
{
    SelectPieceCommand::SelectPieceCommand(Piece* piece)
        : piece_(piece), validMoves_(piece->getMoves())
    {
    }

    void SelectPieceCommand::execute()
    {
        
        for (auto square : validMoves_)
        {
            square->markAs(Status::PLAYABLE);
        }
    }

    void SelectPieceCommand::cancel()
    {
        for (auto& square : validMoves_)
        {
            square->markAs(Status::UNPLAYABLE);
        }
    }
}