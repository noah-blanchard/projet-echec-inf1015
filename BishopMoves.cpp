#include "BishopMoves.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace model {

    std::vector<class Square*> BishopMoves::calculate(Square* currentSquare, Checker* checker, bool validate)
    {
        std::vector<Square*> validMoves;
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
                if (checker->getSquareAtPosition(x + i, y + i)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()) {
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
                if (checker->getSquareAtPosition(x - i, y - i)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()) {
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
                if (checker->getSquareAtPosition(x + i, y - i)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()) {
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
                if (checker->getSquareAtPosition(x - i, y + i)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()) {
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