#include "RookMoves.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include "ChessBoard.h"

namespace logic {
    std::vector<class ModelSquare*> logic::RookMoves::calculate(ModelSquare* currentSquare, ChessBoard* checker, bool validate)
    {
        std::vector<ModelSquare*> validMoves;
        int x = currentSquare->getX();
        int y = currentSquare->getY();

        int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

        auto isInsideChessBoard = [&checker](int posX, int posY)
        {
            return (posX >= 0 && posX < 8 && posY >= 0 && posY < 8);
        };

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 1; isInsideChessBoard(x + j * direction[i][0], y + j * direction[i][1]); ++j)
            {
                ModelSquare* square = checker->getSquareAtPosition(x + j * direction[i][0], y + j * direction[i][1]);

                if (!(!validate || checker->validateMove(currentSquare, square)))
                {
                    continue;
                }

                if (square->getPiece() == nullptr)
                {
                    validMoves.push_back(square);
                    continue;
                }

                if (square->getPiece()->isWhite() != currentSquare->getPiece()->isWhite())
                {
                    validMoves.push_back(square);
                }

                break;
            }
        }

        return validMoves;
    }
}
