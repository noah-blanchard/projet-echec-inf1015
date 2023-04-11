#include "ModelRoiPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	const std::string ModelRoiPiece::whiteImagePath = "images/white/roi_white.png";
	const std::string ModelRoiPiece::blackImagePath = "images/black/roi_black.png";
	//int counter = 0;

	bool ModelRoiPiece::isKing() {
		return true;
	}

	std::vector<ModelSquare*> ModelRoiPiece::getValidMoves(ModelChecker* checker)
	{
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();
		if (x + 1 < 8 && y + 1 < 8) {
			if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 1));
			}
			else {
				if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 1));
				}
			}
		}
		if (x - 1 >= 0 && y - 1 >= 0) {
			if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 1, y - 1));
			}
			else {
				if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 1, y - 1));
				}
			}
		}
		if (x + 1 < 8 && y - 1 >= 0) {
			if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 1, y - 1));
			}
			else {
				if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y - 1));
				}
			}
		}
		if (x - 1 >= 0 && y + 1 < 8) {
			if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 1));
			}
			else {
				if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 1));
				}
			}
		}
		if (x + 1 < 8) {
			if (checker->getSquareAtPosition(x + 1, y)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 1, y));
			}
			else {
				if (checker->getSquareAtPosition(x + 1, y)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y));
				}
			}
		}
		if (x - 1 >= 0) {
			if (checker->getSquareAtPosition(x - 1, y)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 1, y));
			}
			else {
				if (checker->getSquareAtPosition(x - 1, y)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 1, y));
				}
			}
		}
		if (y + 1 < 8) {
			if (checker->getSquareAtPosition(x, y + 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x, y + 1));
			}
			else {
				if (checker->getSquareAtPosition(x, y + 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x, y + 1));
				}
			}
		}
		if (y - 1 >= 0) {
			if (checker->getSquareAtPosition(x, y - 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x, y - 1));
			}
			else {
				if (checker->getSquareAtPosition(x, y - 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x, y - 1));
				}
			}
		}
		return validMoves;
	}

	ModelRoiPiece::ModelRoiPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {
		//++counter;
	}
}