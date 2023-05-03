#include "KnightMoves.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include "ChessBoard.h"

namespace logic {
	std::vector<class ModelSquare*> KnightMoves::calculate(ModelSquare* currentSquare, ChessBoard* checker, bool validate)
	{
        std::vector<ModelSquare*> validMoves;

        int possibleMoves[8][2] = { {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1} };

        auto square = [&checker](int posX, int posY)
        {
            return checker->getSquareAtPosition(posX, posY);
        };

        auto isMoveValid = [square, currentSquare, this](int posX, int posY)
        {
            return (posX >= 0 && posX < 8 && posY >= 0 && posY < 8) &&
                (square(posX, posY)->getPiece() == nullptr ||
                    square(posX, posY)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite());
        };

        for (int i = 0; i < 8; ++i)
        {
            int newX = currentSquare->getX() + possibleMoves[i][0];
            int newY = currentSquare->getY() + possibleMoves[i][1];

            if (isMoveValid(newX, newY) && (!validate || checker->validateMove(currentSquare, square(newX, newY))))
            {
                validMoves.push_back(square(newX, newY));
            }
        }

        return validMoves;
	}
}
