#include "RookMoves.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
    std::vector<class ModelSquare*> logic::RookMoves::calculate(ModelSquare* currentSquare, ModelChecker* checker, bool validate)
    {
        std::vector<ModelSquare*> validMoves;
        int x = currentSquare->getX();
        int y = currentSquare->getY();

        int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

        auto isInsideChessBoard = [&checker](int posX, int posY)
        {
            return (posX >= 0 && posX < 8 && posY >= 0 && posY < 8);
        };

        for (int i = 0; i < 4; i++)
        {
			int posX = x + direction[i][0];
			int posY = y + direction[i][1];
            while (isInsideChessBoard(posX, posY))
            {
				auto square = checker->getSquareAtPosition(posX, posY);
                if (square->getPiece() == nullptr)
                {
                    if (!validate || checker->validateMove(currentSquare, square))
                    {
						validMoves.push_back(square);
					}
				}
                else
                {
                    if (square->getPiece()->isWhite() != currentSquare->getPiece()->isWhite())
                    {
                        if (!validate || checker->validateMove(currentSquare, square))
                        {
							validMoves.push_back(square);
						}
					}
					break;
				}
				posX += direction[i][0];
				posY += direction[i][1];
			}
		}

        return validMoves;
    }
}
