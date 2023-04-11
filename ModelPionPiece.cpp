#include "ModelPionPiece.h"

namespace logic {
	
	const std::string ModelPionPiece::whiteImagePath = "images/white/pion_white.png";
	const std::string ModelPionPiece::blackImagePath = "images/black/pion_black.png";

	std::vector<ModelSquare*> ModelPionPiece::getValidMoves(ModelChecker* checker) {
		
	}
	
	ModelPionPiece::ModelPionPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {}
}