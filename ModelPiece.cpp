/**
 * @file ModelPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelPiece class
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"
#include "ModelSquare.h"

namespace logic {
	
	bool ModelPiece::isWhite() {
		return white_;
	}

	bool ModelPiece::isKing() {
		return false;
	}

	/*void ModelPiece::move(ModelSquare* square) {
		square->setPiece(this);
		emit movedSignal();
	}*/

	void ModelPiece::setCurrentSquare(ModelSquare* square) {
		currentSquare = square;
	}

	ModelPiece::ModelPiece(bool isWhite, std::string whitePath, std::string blackPath)
	{
		white_ = isWhite;
		imagePath_ = isWhite ? whitePath : blackPath;
	}

	ModelPiece::~ModelPiece()
	{
		this->setCurrentSquare(nullptr);
	}

	void ModelPiece::firstMoveDone() {
		//do nothing
	}

	bool ModelPiece::transform(ModelSquare* square) {
		return false;
	}
}