#include "PawnMoves.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include "ChessBoard.h"

namespace logic {
	std::vector<class ModelSquare*> PawnMoves::calculate(ModelSquare* currentSquare, ChessBoard* checker, bool validate) {
        std::vector<ModelSquare*> validMoves;
        int x = currentSquare->getX();
        int y = currentSquare->getY();
        if (!currentSquare->getPiece()->isWhite()) {
            if (x + 1 < 8) {
                if (checker->getSquareAtPosition(x + 1, y)->getPiece() == nullptr) {
                    if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 1, y))) {
                        validMoves.push_back(checker->getSquareAtPosition(x + 1, y));
                    }
                }
                if (currentSquare->getPiece()->isFirstMove()) {
                    if (checker->getSquareAtPosition(x + 2, y)->getPiece() == nullptr) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 2, y))) {
                            validMoves.push_back(checker->getSquareAtPosition(x + 2, y));
                        }
                    }
                }
            }
            if (x + 1 < 8 && y + 1 < 8) {
                if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece() != nullptr) {
                    if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 1, y + 1))) {
                            validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 1));
                        }
                    }
                }
            }
            if (x + 1 < 8 && y - 1 >= 0) {
                if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece() != nullptr) {
                    if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 1, y - 1))) {
                            validMoves.push_back(checker->getSquareAtPosition(x + 1, y - 1));
                        }
                    }
                }
            }
        }
        else {
            if (x - 1 >= 0) {
                if (checker->getSquareAtPosition(x - 1, y)->getPiece() == nullptr) {
                    if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - 1, y))) {
                        validMoves.push_back(checker->getSquareAtPosition(x - 1, y));
                    }
                }
                if (currentSquare->getPiece()->isFirstMove()) {
                    if (checker->getSquareAtPosition(x - 2, y)->getPiece() == nullptr) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - 2, y))) {
                            validMoves.push_back(checker->getSquareAtPosition(x - 2, y));
                        }
                    }
                }
            }
            if (x - 1 >= 0 && y + 1 < 8) {
                if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece() != nullptr) {
                    if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - 1, y + 1))) {
                            validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 1));
                        }
                    }
                }
            }
            if (x - 1 >= 0 && y - 1 >= 0) {
                if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece() != nullptr) {
                    if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - 1, y - 1))) {
                            validMoves.push_back(checker->getSquareAtPosition(x - 1, y - 1));
                        }
                    }
                }
            }
        }
        return validMoves;
	}
}