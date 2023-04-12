#pragma once
#include "ModelChecker.h"

namespace logic {

	void ModelChecker::setSelectedSquare(ModelSquare* square)
	{
		selectedSquare = square;
	}

	void ModelChecker::setWhiteKingSquare(ModelSquare* square)
	{
		whiteKingSquare = square;
	}
	
	void ModelChecker::setBlackKingSquare(ModelSquare* square)
	{
		blackKingSquare = square;
	}

	void ModelChecker::resetPlayableSquares()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				squares[i][j]->setPlayable(false);
			}
		}
	}
	
	bool ModelChecker::validateMove(ModelSquare* square, ModelSquare* validMove) {
		ModelSquare* kingPosition = nullptr;
		ModelSquare* tempSquare = new ModelSquare();
		tempSquare->setPiece(validMove->getPiece());
		validMove->setPiece(square->getPiece());
		if (square == whiteKingSquare || square == blackKingSquare) {
			kingPosition = validMove;
		}
		else{
			if (square->getPiece()->isWhite())
				kingPosition = whiteKingSquare;
			else
				kingPosition = blackKingSquare;
		}

		square->setPiece(nullptr );

		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				
				if (squares[i][j]->getPiece() != nullptr && squares[i][j]->getPiece()->isWhite() != validMove->getPiece()->isWhite()) {
					std::vector<ModelSquare*> validMoves = squares[i][j]->getPiece()->getValidMoves(this, false);
					if (std::find(validMoves.begin(), validMoves.end(), kingPosition) != validMoves.end()) {
						square->setPiece(validMove->getPiece());
						validMove->setPiece(tempSquare->getPiece());
						//emit unallowedMoveSignal();
						return false;
					}
				}
			}
		}
		square->setPiece(validMove->getPiece());
		validMove->setPiece(tempSquare->getPiece());
		delete tempSquare;
		return true;		
	}
	
	ModelSquare* ModelChecker::getSelectedSquare() const
	{
		return selectedSquare;
	}

	ModelSquare* ModelChecker::getSquareAtPosition(int x, int y) const
	{
		return squares[x][y];
	}


	ModelChecker::ModelChecker()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				squares[i][j] = new ModelSquare((i + j) % 2 == 0, i, j);
			}
		}
	}

	ModelChecker::~ModelChecker()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				delete squares[i][j];
			}
		}
		//delete whiteKingSquare;
		//delete blackKingSquare;
	}

}