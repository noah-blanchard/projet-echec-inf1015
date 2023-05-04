/**
 * @file ModelBishopPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the Bishop Piece
 * @date 20/04/2023
 */

#include "ModelBishopPiece.h"
#include "BishopMoves.h"

namespace model {
    const std::string Bishop::whiteImagePath_ = "images/white/fou_white.png";
    const std::string Bishop::blackImagePath_ = "images/black/fou_black.png";

    /*std::vector<ModelSquare*> ModelBishopPiece::getValidMoves(ModelChecker* checker, bool validate)
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

    }*/

    Bishop::Bishop(bool isWhite) : Piece(isWhite, whiteImagePath_, blackImagePath_)
    {
        calculators_.push_back(new BishopMoves());
	}

    Bishop::~Bishop()
    {
        for (auto& calculator : calculators_)
        {
			delete calculator;
		}
        calculators_.clear();
	}
}