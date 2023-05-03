/**
 * @file ModelChecker.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelChecker class
 * @date 20/04/2023
 */

#pragma once
#include "ModelChecker.h"

namespace logic {

	void ModelChecker::setSelectedSquare(ModelSquare* square)
	{
		selectedSquare_ = square;
	}

	void ModelChecker::setWhiteKingSquare(ModelSquare* square)
	{
		whiteKingSquare_ = square;
	}
	
	void ModelChecker::setBlackKingSquare(ModelSquare* square)
	{
		blackKingSquare_ = square;
	}

	void ModelChecker::resetPlayableSquares()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				squares_[i][j]->setPlayable(false);
			}
		}
	}
	
	bool ModelChecker::validateMove(ModelSquare* square, ModelSquare* validMove) {
		bool result = true;
		ModelSquare* kingPosition = nullptr;
		TempModelSquare tempSquare;
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

				std::vector<ModelSquare*> validMoves = squares_[i][j]->getPiece()->getValidMoves2(this, false);

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
	
	ModelSquare* ModelChecker::getSelectedSquare() const
	{
		return selectedSquare_;
	}

	ModelSquare* ModelChecker::getSquareAtPosition(int x, int y) const
	{
		return squares_[x][y];
	}


	ModelChecker::ModelChecker()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				squares_[i][j] = new ModelSquare((i + j) % 2 == 0, i, j);
			}
		}
	}

	ModelChecker::~ModelChecker()
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