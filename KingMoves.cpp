#include "KingMoves.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
    std::vector<class ModelSquare*> KingMoves::calculate(ModelSquare* currentSquare, ModelChecker* checker, bool validate)
    {
		std::vector<ModelSquare*> validMoves;
		int posX = currentSquare->getX();
		int posY = currentSquare->getY();

		int possibleMoves[][2] = { {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

		auto isMoveValid = [&checker, currentSquare, this](int posX, int posY) {
			return (posX >= 0 && posX < 8 && posY >= 0 && posY < 8) && // check if the move is on the board
				(checker->getSquareAtPosition(posX, posY)->getPiece() == nullptr || // check if the move is on an empty square
					checker->getSquareAtPosition(posX, posY)->getPiece()->isWhite() != currentSquare->getPiece()->isWhite()); // check if the move is on an enemy piece
		};

		for (int i = 0; i < 8; ++i)
		{
			int newX = posX + possibleMoves[i][0];
			int newY = posY + possibleMoves[i][1];
			ModelSquare* square = checker->getSquareAtPosition(newX, newY);

			if (isMoveValid(newX, newY) && (!validate || checker->validateMove(currentSquare, square))) {
				validMoves.push_back(checker->getSquareAtPosition(newX, newY));
			}
		}

		return validMoves;
    }
}
