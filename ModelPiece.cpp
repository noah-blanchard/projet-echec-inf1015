#pragma once
#include "ModelPiece.h"
#include "ModelSquare.h"

namespace logic {
	
	bool ModelPiece::isWhite() {
		return white;
	}

	/*void ModelPiece::move(ModelSquare* square) {
		square->setPiece(this);
		emit movedSignal();
	}*/

	ModelPiece::ModelPiece(bool isWhite, std::string whitePath, std::string blackPath)
	{
		white = isWhite;
		imagePath = isWhite ? whitePath : blackPath;
	}
}