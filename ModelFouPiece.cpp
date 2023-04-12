#include "ModelFouPiece.h"

namespace logic {
    const std::string ModelFouPiece::whiteImagePath = "images/white/fou_white.png";
    const std::string ModelFouPiece::blackImagePath = "images/black/fou_black.png";

    std::vector<ModelSquare*> ModelFouPiece::getValidMoves(ModelChecker* checker, bool validate)
    {
        std::vector<ModelSquare*> validMoves;
        int x = currentSquare->getX();
        int y = currentSquare->getY();
        int i = 1;
        while (x + i < 8 && y + i < 8) {
            if (checker->getSquareAtPosition(x + i, y + i)->getPiece() == nullptr) {
                if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + i, y + i))) {
                    validMoves.push_back(checker->getSquareAtPosition(x + i, y + i));
                }
            }
            else {
                if (checker->getSquareAtPosition(x + i, y + i)->getPiece()->isWhite() != this->isWhite()) {
                    if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + i, y + i))) {
                        validMoves.push_back(checker->getSquareAtPosition(x + i, y + i));
                    }
                }
                break;
            }
            i++;
        }
        i = 1;
        while (x - i >= 0 && y - i >= 0) {
            if (checker->getSquareAtPosition(x - i, y - i)->getPiece() == nullptr) {
                if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - i, y - i))) {
                    validMoves.push_back(checker->getSquareAtPosition(x - i, y - i));
                }
            }
            else {
                if (checker->getSquareAtPosition(x - i, y - i)->getPiece()->isWhite() != this->isWhite()) {
                    if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - i, y - i))) {
                        validMoves.push_back(checker->getSquareAtPosition(x - i, y - i));
                    }
                }
                break;
            }
            i++;
        }
        i = 1;
        while (x + i < 8 && y - i >= 0) {
            if (checker->getSquareAtPosition(x + i, y - i)->getPiece() == nullptr) {
                if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + i, y - i))) {
                    validMoves.push_back(checker->getSquareAtPosition(x + i, y - i));
                }
            }
            else {
                if (checker->getSquareAtPosition(x + i, y - i)->getPiece()->isWhite() != this->isWhite()) {
                    if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + i, y - i))) {
                        validMoves.push_back(checker->getSquareAtPosition(x + i, y - i));
                    }
                }
                break;
            }
            i++;
        }
        i = 1;
        while (x - i >= 0 && y + i < 8) {
            if (checker->getSquareAtPosition(x - i, y + i)->getPiece() == nullptr) {
                if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - i, y + i))) {
                    validMoves.push_back(checker->getSquareAtPosition(x - i, y + i));
                }
            }
            else {
                if (checker->getSquareAtPosition(x - i, y + i)->getPiece()->isWhite() != this->isWhite()) {
                    if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - i, y + i))) {
                        validMoves.push_back(checker->getSquareAtPosition(x - i, y + i));
                    }
                }
                break;
            }
            i++;
        }
        return validMoves;

    }
}