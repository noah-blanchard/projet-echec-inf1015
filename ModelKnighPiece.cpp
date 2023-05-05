/**
 * @file ModelKnightPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the Model for the Knight Piece
 * @date 20/04/2023
 */

#include "ModelKnightPiece.h"
#include "ModelChecker.h"
#include "KnightMoves.h"

namespace model
{
    const std::string Knight::whiteImagePath_ = "images/white/cavalier_white.png";
    const std::string Knight::blackImagePath_ = "images/black/cavalier_black.png";

    Knight::Knight(bool isWhite) : Piece(isWhite, whiteImagePath_, blackImagePath_) {
        calculators_.push_back(new KnightMoves());
    }

    Knight::~Knight() {
        for (auto& calculator : calculators_) {
			delete calculator;
		}
        calculators_.clear();
    }


}