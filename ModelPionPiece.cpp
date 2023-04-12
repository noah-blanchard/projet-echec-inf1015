#include "ModelPionPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	
	const std::string ModelPionPiece::whiteImagePath = "images/white/pion_white.png";
	const std::string ModelPionPiece::blackImagePath = "images/black/pion_black.png";

	std::vector<ModelSquare*> ModelPionPiece::getValidMoves(ModelChecker* checker, bool validate) {
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();
		if (!isWhite()) {
			if (x + 1 < 8) {
				if (checker->getSquareAtPosition(x + 1, y)->getPiece() == nullptr) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y));
				}
				if (firstMove) {
					if (checker->getSquareAtPosition(x + 2, y)->getPiece() == nullptr) {
						validMoves.push_back(checker->getSquareAtPosition(x + 2, y));
					}
				}
			}
			if (x + 1 < 8 && y + 1 < 8) {
				if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece() != nullptr) {
					if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece()->isWhite() != this->isWhite()) {
						validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 1));
					}
				}
			}
			if (x + 1 < 8 && y - 1 >= 0) {
				if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece() != nullptr) {
					if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece()->isWhite() != this->isWhite()) {
						validMoves.push_back(checker->getSquareAtPosition(x + 1, y - 1));
					}
				}
			}
		}
		else {
			if (x - 1 >= 0) {
				if (checker->getSquareAtPosition(x - 1, y)->getPiece() == nullptr) {
					validMoves.push_back(checker->getSquareAtPosition(x - 1, y));
				}
				if (firstMove) {
					if (checker->getSquareAtPosition(x - 2, y)->getPiece() == nullptr) {
						validMoves.push_back(checker->getSquareAtPosition(x - 2, y));
					}
				}
			}
			if (x - 1 >= 0 && y + 1 < 8) {
				if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece() != nullptr) {
					if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece()->isWhite() != this->isWhite()) {
						validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 1));
					}
				}
			}
			if (x - 1 >= 0 && y - 1 >= 0) {
				if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece() != nullptr) {
					if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece()->isWhite() != this->isWhite()) {
						validMoves.push_back(checker->getSquareAtPosition(x - 1, y - 1));
					}
				}
			}
		}
		return validMoves;
			
	}
	
	ModelPionPiece::ModelPionPiece(bool isWhite, bool firstMove) : ModelPiece(isWhite, whiteImagePath, blackImagePath), firstMove(firstMove) {}
}