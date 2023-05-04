#include "ModelRook.h"
#include "RookMoves.h"

namespace model {
	const std::string Rook::whiteImagePath_ = "images/white/tour_white.png";
	const std::string Rook::blackImagePath_ = "images/black/tour_black.png";

	Rook::Rook(bool isWhite) : Piece(isWhite, whiteImagePath_, blackImagePath_) {

		calculators_.push_back(new RookMoves());

	}
}