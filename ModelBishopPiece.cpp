/**
 * @file ModelBishopPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the Bishop Piece
 * @date 20/04/2023
 */

#include "ModelBishopPiece.h"
#include "BishopMoves.h"

namespace model {
    const std::string Bishop::whiteImagePath_ = "images/white/fou_white.png";
    const std::string Bishop::blackImagePath_ = "images/black/fou_black.png";

    Bishop::Bishop(bool isWhite) : Piece(isWhite, whiteImagePath_, blackImagePath_)
    {
        calculators_.push_back(new BishopMoves());
	}

    Bishop::~Bishop()
    {
        for (auto& calculator : calculators_)
        {
			delete calculator;
		}
        calculators_.clear();
	}
}