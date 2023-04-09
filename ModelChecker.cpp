#pragma once
#include "ModelChecker.h"

namespace logic {

	void ModelChecker::setSelectedSquare(ModelSquare* square)
	{
		selectedSquare = square;
	}

	void ModelChecker::resetPlayableSquares()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				squares[i][j]->setPlayable(false);
			}
		}
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
	}
}