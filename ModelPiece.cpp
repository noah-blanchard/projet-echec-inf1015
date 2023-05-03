/**
 * @file ModelPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelPiece class
 * @date 20/04/2023
 */

#include "ModelPiece.h"
#include "ModelSquare.h"
#include "ValidMovesCalculator.h"

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

	bool ModelPiece::isFirstMove()
	{
		return false;
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

	std::vector<class ModelSquare*> ModelPiece::getValidMoves2(class ChessBoard* checker, bool validate) {
		std::vector<ModelSquare*> validMoves;
		for (auto calculator : calculators_) {
			std::vector<ModelSquare*> moves = calculator->calculate(currentSquare, checker, validate);
			validMoves.insert(validMoves.end(), moves.begin(), moves.end());
		}
		return validMoves;
	}
}