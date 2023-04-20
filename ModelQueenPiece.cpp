/**
 * @file ModelQueenPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the Queen Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelQueenPiece.h"

namespace logic {
	const std::string ModelQueenPiece::whiteImagePath_ = "images/white/reine_white.png";
	const std::string ModelQueenPiece::blackImagePath_ = "images/black/reine_black.png";
	
	std::vector<ModelSquare*> ModelQueenPiece::getValidMoves(ModelChecker* checker, bool validate) {
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