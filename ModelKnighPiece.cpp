/**
 * @file ModelKnightPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the Model for the Knight Piece
 * @date 20/04/2023
 */

#include "ModelKnightPiece.h"
#include "ModelChecker.h"
#include "KnightMoves.h"

namespace logic
{
    const std::string ModelKnightPiece::whiteImagePath_ = "images/white/cavalier_white.png";
    const std::string ModelKnightPiece::blackImagePath_ = "images/black/cavalier_black.png";

    /*std::vector<ModelSquare*> ModelKnightPiece::getValidMoves(ModelChecker* checker, bool validate)
    {
        std::vector<ModelSquare*> validMoves;

        int possibleMoves[8][2] = { {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1} };

        auto square = [&checker](int posX, int posY)
        {
            return checker->getSquareAtPosition(posX, posY);
        };

        auto isMoveValid = [square, this](int posX, int posY)
        {
            return (posX >= 0 && posX < 8 && posY >= 0 && posY < 8) &&
                (square(posX, posY)->getPiece() == nullptr ||
                    square(posX, posY)->getPiece()->isWhite() != this->isWhite());
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
    }*/

    ModelKnightPiece::ModelKnightPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath_, blackImagePath_) {
        calculators_.push_back(new KnightMoves());
    }
}