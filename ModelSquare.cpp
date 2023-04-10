#pragma once
#include "ModelSquare.h"

namespace logic {
	void ModelSquare::setPlayable(bool p) { 
		playable = p;
		emit playableSignal();
	}

	void ModelSquare::setPiece(ModelPiece* piece) { 
		this->piece = piece;
		if (piece != nullptr)
			piece->setCurrentSquare(this);
		emit updatePieceSignal();
	}
}