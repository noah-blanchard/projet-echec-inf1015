#include "ValidMovesCalculator.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace model {
	/*std::vector<class ModelSquare*> ValidMovesCalculator::calculate(ModelSquare* currentSquare, ModelChecker* checker, bool validate) {
		std::vector<ModelSquare*> validMoves;
		if (currentSquare->getPiece() != nullptr) {
			if (currentSquare->getX() > 0 && currentSquare->getY() > 0) {
				validMoves.push_back(checker->getSquareAtPosition(currentSquare->getX() - 1, currentSquare->getY() - 1));
			}
		}
		return validMoves;
	}*/
}