#include "ModelCavalierPiece.h"
#include "ModelChecker.h"
#include <utility>

namespace logic {
	const std::string ModelCavalierPiece::whiteImagePath = "images/white/cavalier_white.png";
	const std::string ModelCavalierPiece::blackImagePath = "images/black/cavalier_black.png";

	std::vector<ModelSquare*> ModelCavalierPiece::getValidMoves(ModelChecker* checker, bool validate)
	{
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();
		const int DESK_LENGHT = 8;

		int possibleMoves[][2] = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}};
		const int nPossibleMoves = 8;

		auto isMoveValid = [&checker, this](int posX, int posY) {
			return (posX >= 0 && posX < DESK_LENGHT && posY >= 0 && posY < DESK_LENGHT) && 
				(checker->getSquareAtPosition(posX, posY)->getPiece() == nullptr || 
					checker->getSquareAtPosition(posX, posY)->getPiece()->isWhite() != this->isWhite());
		};

		for (int i = 0; i < nPossibleMoves; ++i) {

			int newX = x + possibleMoves[i][0];
			int newY = y + possibleMoves[i][1];

			if (isMoveValid(newX, newY)) {
				validMoves.push_back(checker->getSquareAtPosition(newX, newY));
			}
		}

		return validMoves;
	}

	ModelCavalierPiece::ModelCavalierPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {
	}
}