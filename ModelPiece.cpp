/**
 * @file ModelPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelPiece class
 * @date 20/04/2023
 */

#include "ModelPiece.h"
#include "ModelSquare.h"
#include "ValidMovesCalculator.h"

namespace model {
	
	bool Piece::isWhite() {
		return white_;
	}

	bool Piece::isKing() {
		return false;
	}

	/*void ModelPiece::move(ModelSquare* square) {
		square->setPiece(this);
		emit movedSignal();
	}*/

	void Piece::setCurrentSquare(Square* square) {
		currentSquare = square;
	}

	bool Piece::isFirstMove()
	{
		return false;
	}

	Piece::Piece(bool isWhite, std::string whitePath, std::string blackPath)
	{
		white_ = isWhite;
		imagePath_ = isWhite ? whitePath : blackPath;
	}

	Piece::~Piece()
	{
		this->setCurrentSquare(nullptr);
	}

	void Piece::firstMoveDone() {
		//do nothing
	}

	bool Piece::transform(Square* square) {
		return false;
	}

	std::vector<class Square*> Piece::getValidMoves2(class Checker* checker, bool validate) {
		std::vector<Square*> validMoves;
		for (auto calculator : calculators_) {
			std::vector<Square*> moves = calculator->calculate(currentSquare, checker, validate);
			validMoves.insert(validMoves.end(), moves.begin(), moves.end());
		}
		return validMoves;
	}
}