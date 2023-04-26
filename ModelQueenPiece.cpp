/**
 * @file ModelQueenPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the Queen Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelQueenPiece.h"

namespace logic
{
	const std::string ModelQueenPiece::whiteImagePath_ = "images/white/reine_white.png";
	const std::string ModelQueenPiece::blackImagePath_ = "images/black/reine_black.png";
	
	std::vector<ModelSquare*> ModelQueenPiece::getValidMoves(ModelChecker* checker, bool validate)
	{
		std::vector<ModelSquare*> validMoves;
		int x = currentSquare->getX();
		int y = currentSquare->getY();

		int direction[8][2] = { {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };

		auto isInsideChessBoard = [&checker, this](int posX, int posY)
		{
			return (posX >= 0 && posX < 8 && posY >= 0 && posY < 8);
		};

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 1; isInsideChessBoard(x + j * direction[i][0], y + j * direction[i][1]); ++j)
			{
				ModelSquare* square = checker->getSquareAtPosition(x + j * direction[i][0], y + j * direction[i][1]);

				if (!(!validate || checker->validateMove(currentSquare, square)))
				{
					continue;
				}

				if (square->getPiece() == nullptr)
				{
					validMoves.push_back(square);
					continue;
				}
				
				if (square->getPiece()->isWhite() != this->isWhite())
				{
					validMoves.push_back(square);
				}

				break;
			}
		}

		return validMoves;
	}
}