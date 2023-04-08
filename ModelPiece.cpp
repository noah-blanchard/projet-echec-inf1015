#pragma once
#include "ModelPiece.h"

namespace logic {
	
	bool ModelPiece::isWhite() {
		return white;
	}

	ModelPiece::ModelPiece(bool isWhite, std::string whitePath, std::string blackPath)
	{
		white = isWhite;
		imagePath = isWhite ? whitePath : blackPath;
	}
}