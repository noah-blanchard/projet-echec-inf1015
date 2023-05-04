/**
 * @file ModelChecker.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelChecker class
 * @date 20/04/2023
 */

#pragma once
#include "ModelChecker.h"

namespace model {

	void Checker::setSelectedSquare(Square* square)
	{
		selectedSquare_ = square;
	}

	void Checker::setWhiteKingSquare(Square* square)
	{
		whiteKingSquare_ = square;
	}
	
	void Checker::setBlackKingSquare(Square* square)
	{
		blackKingSquare_ = square;
	}

	void Checker::resetPlayableSquares()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				squares_[i][j]->setPlayable(false);
			}
		}
	}
	
	bool Checker::validateMove(Square* square, Square* validMove) {
		bool result = true;
		Square* kingPosition = nullptr;
		TempSquare tempSquare;
		tempSquare->setPiece(validMove->getPiece());
		validMove->setPiece(square->getPiece());
		if (square == whiteKingSquare_ || square == blackKingSquare_) {
			kingPosition = validMove;
		}
		else if (square->getPiece()->isWhite()) {
			kingPosition = whiteKingSquare_;
		}
		else {
			kingPosition = blackKingSquare_;
		}

		square->setPiece(nullptr);

		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (!(squares_[i][j]->getPiece() != nullptr && squares_[i][j]->getPiece()->isWhite() != validMove->getPiece()->isWhite())) // si la case est vide ou qu'elle contient une piece alliee, continue
					continue;

				std::vector<Square*> validMoves = squares_[i][j]->getPiece()->getValidMoves2(this, false);

				if (!(std::find(validMoves.begin(), validMoves.end(), kingPosition) != validMoves.end())) // s'il n'y a pas de roi dans validMoves de la case, continue
					continue;

				result = false;
				break;

			}
		}

		square->setPiece(validMove->getPiece());
		validMove->setPiece(tempSquare->getPiece());
		return result;		
	}
	
	Square* Checker::getSelectedSquare() const
	{
		return selectedSquare_;
	}

	Square* Checker::getSquareAtPosition(int x, int y) const
	{
		return squares_[x][y];
	}


	Checker::Checker()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				squares_[i][j] = new Square((i + j) % 2 == 0, i, j);
			}
		}
	}

	Checker::~Checker()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				delete squares_[i][j];
			}
		}
		//delete whiteKingSquare;
		//delete blackKingSquare;
	}

}