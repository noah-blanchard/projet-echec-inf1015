#include "ModelCavalierPiece.h"
#include "ModelChecker.h"

namespace logic {
	const std::string ModelCavalierPiece::whiteImagePath = "images/white/cavalier_white.png";
	const std::string ModelCavalierPiece::blackImagePath = "images/black/cavalier_black.png";

	std::vector<ModelSquare*> ModelCavalierPiece::getValidMoves(ModelChecker* checker)
	{
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();

		if (x - 1 >= 0 && y - 2 >= 0) {
			if (checker->getSquareAtPosition(x - 1, y - 2)->getPiece() == nullptr || checker->getSquareAtPosition(x - 1, y - 2)->getPiece()->isWhite() != this->isWhite()) { // if the square is empty
				validMoves.push_back(checker->getSquareAtPosition(x - 1, y - 2)); // add it to the list of valid moves
			}
		}
		if (x + 1 < 8 && y - 2 >= 0) {
			if (checker->getSquareAtPosition(x + 1, y - 2)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 1, y - 2));
			}
			else if (checker->getSquareAtPosition(x + 1, y - 2)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y - 2));
			}
		}
		if (x + 2 < 8 && y - 1 >= 0) {
			if (checker->getSquareAtPosition(x + 2, y - 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 2, y - 1));
			}
			else if (checker->getSquareAtPosition(x + 2, y - 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 2, y - 1));
			}
		}
		if (x + 2 < 8 && y + 1 < 8) {
			if (checker->getSquareAtPosition(x + 2, y + 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 2, y + 1));
			}
			else if (checker->getSquareAtPosition(x + 2, y + 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 2, y + 1));
			}
		}
		if (x + 1 < 8 && y + 2 < 8) {
			if (checker->getSquareAtPosition(x + 1, y + 2)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 2));
			}
			else if (checker->getSquareAtPosition(x + 1, y + 2)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 2));
			}
		}
		if (x - 1 >= 0 && y + 2 < 8) {
			if (checker->getSquareAtPosition(x - 1, y + 2)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 2));
			}
			else if (checker->getSquareAtPosition(x - 1, y + 2)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 2));
			}
		}
		if (x - 2 >= 0 && y + 1 < 8) {
			if (checker->getSquareAtPosition(x - 2, y + 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 2, y + 1));
			}
			else if (checker->getSquareAtPosition(x - 2, y + 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 2, y + 1));
			}
		}
		if (x - 2 >= 0 && y - 1 >= 0) {
			if (checker->getSquareAtPosition(x - 2, y - 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 2, y - 1));
			}
			else if (checker->getSquareAtPosition(x - 2, y - 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 2, y - 1));
			}
		}
		return validMoves;
	}

	ModelCavalierPiece::ModelCavalierPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {
	}
}