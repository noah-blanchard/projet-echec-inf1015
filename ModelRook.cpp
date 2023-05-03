#include "ModelRook.h"
#include "RookMoves.h"

namespace logic {
	const std::string ModelRook::whiteImagePath_ = "images/white/tour_white.png";
	const std::string ModelRook::blackImagePath_ = "images/black/tour_black.png";

	ModelRook::ModelRook(bool isWhite) : ModelPiece(isWhite, whiteImagePath_, blackImagePath_) {

		calculators_.push_back(new RookMoves());

	}
}