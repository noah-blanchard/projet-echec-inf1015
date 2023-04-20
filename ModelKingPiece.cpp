/**
 * @file ModelKingPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelKingPiece class
 * @date 20/04/2023
 */

#include "ModelKingPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	const std::string ModelKingPiece::whiteImagePath_ = "images/white/roi_white.png";
	const std::string ModelKingPiece::blackImagePath_ = "images/black/roi_black.png";
	int ModelKingPiece::instanceCounter_ = 0;

	void ModelKingPiece::resetInstanceCounter() {
		instanceCounter_ = 0;
	}
	
	bool ModelKingPiece::isKing() {
		return true;
	}

	std::vector<ModelSquare*> ModelKingPiece::getValidMoves(ModelChecker* checker, bool validate)
	{
		std::vector<ModelSquare*> validMoves;
		int posX = currentSquare->getX();
		int posY = currentSquare->getY();

		int possibleMoves[][2] = { {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

		auto isMoveValid = [&checker, this](int posX, int posY) {
			return (posX >= 0 && posX < 8 && posY >= 0 && posY < 8) && // check if the move is on the board
				(checker->getSquareAtPosition(posX, posY)->getPiece() == nullptr || // check if the move is on an empty square
					checker->getSquareAtPosition(posX, posY)->getPiece()->isWhite() != this->isWhite()); // check if the move is on an enemy piece
		};

		for (int i = 0; i < 8; ++i)
		{
			int newX = posX + possibleMoves[i][0];
			int newY = posY + possibleMoves[i][1];
			ModelSquare* square = checker->getSquareAtPosition(newX, newY);

			if (isMoveValid(newX, newY) && (!validate || checker->validateMove(currentSquare, square))){
				validMoves.push_back(checker->getSquareAtPosition(newX, newY));
			}
		}

		return validMoves;
	}

	
	ModelKingPiece::ModelKingPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath_, blackImagePath_) {
		if (instanceCounter_ < 2) {
			instanceCounter_++;
		}
		else {
			///delete this;
			throw std::exception("Only 2 instances of ModelRoiPiece can be created");
		}
	}

	ModelKingPiece::ModelKingPiece() : ModelKingPiece(false) {}
}