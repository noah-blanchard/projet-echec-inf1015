/**
 * @file ModelPawnPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelPawnPiece class
 * @date 20/04/2023
 */

#include "ModelPawnPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	
	const std::string ModelPawnPiece::whiteImagePath_ = "images/white/pion_white.png";
	const std::string ModelPawnPiece::blackImagePath_ = "images/black/pion_black.png";

    std::vector<ModelSquare*> ModelPawnPiece::getValidMoves(ModelChecker* checker, bool validate) {
        std::vector<ModelSquare*> validMoves;
        int x = currentSquare->getX();
        int y = currentSquare->getY();
        if (!isWhite()) {
            if (x + 1 < 8) {
                if (checker->getSquareAtPosition(x + 1, y)->getPiece() == nullptr) {
                    if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 1, y))) {
                        validMoves.push_back(checker->getSquareAtPosition(x + 1, y));
                    }
                }
                if (firstMove_) {
                    if (checker->getSquareAtPosition(x + 2, y)->getPiece() == nullptr) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 2, y))) {
                            validMoves.push_back(checker->getSquareAtPosition(x + 2, y));
                        }
                    }
                }
            }
            if (x + 1 < 8 && y + 1 < 8) {
                if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece() != nullptr) {
                    if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece()->isWhite() != this->isWhite()) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 1, y + 1))) {
                            validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 1));
                        }
                    }
                }
            }
            if (x + 1 < 8 && y - 1 >= 0) {
                if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece() != nullptr) {
                    if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece()->isWhite() != this->isWhite()) {
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
                if (firstMove_) {
                    if (checker->getSquareAtPosition(x - 2, y)->getPiece() == nullptr) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - 2, y))) {
                            validMoves.push_back(checker->getSquareAtPosition(x - 2, y));
                        }
                    }
                }
            }
            if (x - 1 >= 0 && y + 1 < 8) {
                if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece() != nullptr) {
                    if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece()->isWhite() != this->isWhite()) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - 1, y + 1))) {
                            validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 1));
                        }
                    }
                }
            }
            if (x - 1 >= 0 && y - 1 >= 0) {
                if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece() != nullptr) {
                    if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece()->isWhite() != this->isWhite()) {
                        if (!validate || checker->validateMove(currentSquare, checker->getSquareAtPosition(x - 1, y - 1))) {
                            validMoves.push_back(checker->getSquareAtPosition(x - 1, y - 1));
                        }
                    }
                }
            }
        }
        return validMoves;
    }

    void ModelPawnPiece::firstMoveDone() {
		firstMove_ = false;
	}
	
	ModelPawnPiece::ModelPawnPiece(bool isWhite, bool firstMove) : ModelPiece(isWhite, whiteImagePath_, blackImagePath_), firstMove_(firstMove) {}
}