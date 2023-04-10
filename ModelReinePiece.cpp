#pragma once
#include "ModelReinePiece.h"

namespace logic {
	const std::string ModelReinePiece::whiteImagePath = "images/white/reine_white.png";
	const std::string ModelReinePiece::blackImagePath = "images/black/reine_black.png";
	
	std::vector<ModelSquare*> ModelReinePiece::getValidMoves(ModelChecker* checker)
	{
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();
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
		i = 1;
		while (x + i < 8) {
			if (checker->getSquareAtPosition(x + i, y)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + i, y));
			}
			else {
				if (checker->getSquareAtPosition(x + i, y)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + i, y));
				}
				break;
			}
			i++;
		}
		i = 1;
		while (x - i >= 0) {
			if (checker->getSquareAtPosition(x - i, y)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - i, y));
			}
			else {
				if (checker->getSquareAtPosition(x - i, y)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - i, y));
				}
				break;
			}
			i++;
		}
		i = 1;
		while (y + i < 8) {
			if (checker->getSquareAtPosition(x, y + i)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x, y + i));
			}
			else {
				if (checker->getSquareAtPosition(x, y + i)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x, y + i));
				}
				break;
			}
			i++;
		}
		i = 1;
		while (y - i >= 0) {
			if (checker->getSquareAtPosition(x, y - i)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x, y - i));
			}
			else {
				if (checker->getSquareAtPosition(x, y - i)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x, y - i));
				}
				break;
			}
			i++;
		}
		return validMoves;
	}
}