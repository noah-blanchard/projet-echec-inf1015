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

	/*std::vector<ModelSquare*> ModelRoiPiece::getValidMoves(ModelChecker* checker)
	{
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();
		if (x + 1 < 8 && y + 1 < 8) {
			if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece() == nullptr && checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 1, y + 1))){
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
	}*/

	std::vector<ModelSquare*> ModelRoiPiece::getValidMoves(ModelChecker* checker, bool validate)
	{
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();

		// Check all possible squares around the current square
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) {
					// Ignore the current square
					continue;
				}
				int newX = x + i;
				int newY = y + j;
				if (newX < 0 || newX > 7 || newY < 0 || newY > 7) {
					// Ignore squares outside the board
					continue;
				}
				ModelSquare* square = checker->getSquareAtPosition(newX, newY);
				ModelPiece* piece = square->getPiece();
				if (piece == nullptr || piece->isWhite() != this->isWhite()) {
					// The square is empty or contains an opponent's piece
					// Check if the move is valid
					if (!validate || checker->validateMove(currentSquare, square)) {
						validMoves.push_back(square);
					}
				}
			}
		}
		return validMoves;
	}

	
	ModelRoiPiece::ModelRoiPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {
		//++counter;
	}
}