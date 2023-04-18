#include "ModelRoiPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	const std::string ModelRoiPiece::whiteImagePath = "images/white/roi_white.png";
	const std::string ModelRoiPiece::blackImagePath = "images/black/roi_black.png";
	int ModelRoiPiece::instanceCounter = 0;

	void ModelRoiPiece::resetInstanceCounter() {
		instanceCounter = 0;
	}
	
	bool ModelRoiPiece::isKing() {
		return true;
	}

	/*std::vector<ModelSquare*> ModelRoiPiece::getValidMoves(ModelChecker* checker)
	{
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();
		if (x + 1 < 8 && y + 1 < 8) {
			if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece() == nullptr && checker->validateMove(currentSquare, checker->getSquareAtPosition(x + 1, y + 1))){
				validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 1));
			}
			else {
				if (checker->getSquareAtPosition(x + 1, y + 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y + 1));
				}
			}
		}
		if (x - 1 >= 0 && y - 1 >= 0) {
			if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 1, y - 1));
			}
			else {
				if (checker->getSquareAtPosition(x - 1, y - 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 1, y - 1));
				}
			}
		}
		if (x + 1 < 8 && y - 1 >= 0) {
			if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 1, y - 1));
			}
			else {
				if (checker->getSquareAtPosition(x + 1, y - 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y - 1));
				}
			}
		}
		if (x - 1 >= 0 && y + 1 < 8) {
			if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 1));
			}
			else {
				if (checker->getSquareAtPosition(x - 1, y + 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 1, y + 1));
				}
			}
		}
		if (x + 1 < 8) {
			if (checker->getSquareAtPosition(x + 1, y)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x + 1, y));
			}
			else {
				if (checker->getSquareAtPosition(x + 1, y)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x + 1, y));
				}
			}
		}
		if (x - 1 >= 0) {
			if (checker->getSquareAtPosition(x - 1, y)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x - 1, y));
			}
			else {
				if (checker->getSquareAtPosition(x - 1, y)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x - 1, y));
				}
			}
		}
		if (y + 1 < 8) {
			if (checker->getSquareAtPosition(x, y + 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x, y + 1));
			}
			else {
				if (checker->getSquareAtPosition(x, y + 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x, y + 1));
				}
			}
		}
		if (y - 1 >= 0) {
			if (checker->getSquareAtPosition(x, y - 1)->getPiece() == nullptr) {
				validMoves.push_back(checker->getSquareAtPosition(x, y - 1));
			}
			else {
				if (checker->getSquareAtPosition(x, y - 1)->getPiece()->isWhite() != this->isWhite()) {
					validMoves.push_back(checker->getSquareAtPosition(x, y - 1));
				}
			}
		}
		return validMoves;
	}*/

	std::vector<ModelSquare*> ModelRoiPiece::getValidMoves(ModelChecker* checker, bool validate)
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

	
	ModelRoiPiece::ModelRoiPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {
		if (instanceCounter < 2) {
			instanceCounter++;
		}
		else {
			///delete this;
			throw std::exception("Only 2 instances of ModelRoiPiece can be created");
		}
	}

	ModelRoiPiece::ModelRoiPiece() : ModelRoiPiece(false) {}
}