/**
 * @file ModelPawnPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelPawnPiece class
 * @date 20/04/2023
 */

#include "ModelPawnPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include "PawnMoves.h"

namespace model {
	
	const std::string Pawn::whiteImagePath_ = "images/white/pion_white.png";
	const std::string Pawn::blackImagePath_ = "images/black/pion_black.png";

    bool Pawn::isFirstMove()
    {
        return firstMove_;
    }

    void Pawn::firstMoveDone() {
		firstMove_ = false;
	}

    bool Pawn::transform(Square* square) {
        if (square->getX() == 0 || square->getX() == 7) {
			return true;
		}
		return false;
    }
	
	Pawn::Pawn(bool isWhite, bool firstMove) : Piece(isWhite, whiteImagePath_, blackImagePath_), firstMove_(firstMove) {
        calculators_.push_back(new PawnMoves());
    }

    Pawn::~Pawn() {
        for (auto& calculator : calculators_) {
			delete calculator;
		}
        calculators_.clear();
	}
}