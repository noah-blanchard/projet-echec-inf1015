#include "MovePieceCommand.h"
#include "Piece.h"
#include "Square.h"
#include "ChessBoard.h"

namespace model
{
    MovePieceCommand::MovePieceCommand(Piece* piece, Square* newSquare)
        : piece_(piece), playableSquares_(piece->getMoves()), oldSquare_(ChessBoard::getSquare(piece)), newSquare_(newSquare)
    {
    }

    void MovePieceCommand::execute()
    {
        for (Square* square : playableSquares_)
        {
            square->markAs(Status::UNPLAYABLE);
        }

        ChessBoard::movePiece(piece_, newSquare_);
    }

    void MovePieceCommand::cancel()
    {
        for (Square* square : playableSquares_)
        {
            square->markAs(Status::PLAYABLE);
        }

        ChessBoard::movePiece(piece_, oldSquare_);
    }
}