/**
 * @file ModelKingPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelKingPiece class
 * @date 20/04/2023
 */

#include "ModelKingPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include "KingMoves.h"

namespace model {
	const std::string King::whiteImagePath_ = "images/white/roi_white.png";
	const std::string King::blackImagePath_ = "images/black/roi_black.png";
	int King::instanceCounter_ = 0;

	void King::resetInstanceCounter() {
		instanceCounter_ = 0;
	}
	
	bool King::isKing() {
		return true;
	}
	
	King::King(bool isWhite) : Piece(isWhite, whiteImagePath_, blackImagePath_) {
		if (instanceCounter_ < 2) {
			instanceCounter_++;
			calculators_.push_back(new KingMoves());
		}
		else {
			///delete this;
			throw std::exception("Only 2 instances of ModelRoiPiece can be created");
		}
	}

	King::King() : King(false) {}

	King::~King() {
		for (auto& calculator : calculators_) {
			delete calculator;
		}
		calculators_.clear();
	}
}