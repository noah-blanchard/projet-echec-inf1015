/**
 * @file ModelKnightPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the Model for the Knight Piece
 * @date 20/04/2023
 */

#include "ModelKnightPiece.h"
#include "ModelChecker.h"

namespace logic {
    const std::string ModelKnightPiece::whiteImagePath_ = "images/white/cavalier_white.png";
    const std::string ModelKnightPiece::blackImagePath_ = "images/black/cavalier_black.png";

    std::vector<ModelSquare*> ModelKnightPiece::getValidMoves(ModelChecker* checker, bool validate)
    {
        std::vector<ModelSquare*> validMoves;
        int posX = currentSquare->getX();
        int posY = currentSquare->getY();
        const int BOARD_LENGHT = 8; // nombre magique ?

        int possibleMoves[][2] = { {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1} };
        const int nPossibleMoves = 8; // nombre magique ?

        auto isMoveValid = [&checker, this](int posX, int posY) {
            return (posX >= 0 && posX < BOARD_LENGHT&& posY >= 0 && posY < BOARD_LENGHT) &&
                (checker->getSquareAtPosition(posX, posY)->getPiece() == nullptr ||
                    checker->getSquareAtPosition(posX, posY)->getPiece()->isWhite() != this->isWhite());
        };

        for (int i = 0; i < nPossibleMoves; ++i) {

            int newX = posX + possibleMoves[i][0];
            int newY = posY + possibleMoves[i][1]; // nombre magique ?
            ModelSquare* square = checker->getSquareAtPosition(newX, newY);

			if (isMoveValid(newX, newY) && (!validate || checker->validateMove(currentSquare, square))){
                validMoves.push_back(checker->getSquareAtPosition(newX, newY));
            }
        }

        return validMoves;
    }

    ModelKnightPiece::ModelKnightPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath_, blackImagePath_) {
    }
}