#include "ModelFouPiece.h"

namespace logic {
	const std::string ModelFouPiece::whiteImagePath = "images/white/fou_white.png";
	const std::string ModelFouPiece::blackImagePath = "images/black/fou_black.png";

	std::vector<ModelSquare*> ModelFouPiece::getValidMoves(ModelSquare* square, ModelChecker* checker)
	{
		std::vector<ModelSquare*> validMoves;
		int x = square->getX();
		int y = square->getY();
		int i = 1;
		while (x + i < 8 && y + i < 8) {
			if (checker->getSquareAtPosition(x + i, y + i)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + i, y + i));
			}
			else {
				if (checker->getSquareAtPosition(x + i, y + i)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + i, y + i));
				}
				break;
			}
			i++;
		}
		i = 1;
		while (x - i >= 0 && y - i >= 0) {
			if (checker->getSquareAtPosition(x - i, y - i)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - i, y - i));
			}
			else {
				if (checker->getSquareAtPosition(x - i, y - i)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - i, y - i));
				}
				break;
			}
			i++;
		}
		i = 1;
		while (x + i < 8 && y - i >= 0) {
			if (checker->getSquareAtPosition(x + i, y - i)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + i, y - i));
			}
			else {
				if (checker->getSquareAtPosition(x + i, y - i)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + i, y - i));
				}
				break;
			}
			i++;
		}
		i = 1;
		while (x - i >= 0 && y + i < 8) {
			if (checker->getSquareAtPosition(x - i, y + i)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - i, y + i));
			}
			else {
				if (checker->getSquareAtPosition(x - i, y + i)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - i, y + i));
				}
				break;
			}
			i++;
		}
		return validMoves;
	}
}
