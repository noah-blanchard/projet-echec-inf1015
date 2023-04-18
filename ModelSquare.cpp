#pragma once
#include "ModelSquare.h"

namespace logic {
	void ModelSquare::setPlayable(bool p) { 
		playable = p;
		emit playableSignal();
	}

	void ModelSquare::setPiece(std::shared_ptr<ModelPiece> piece) { 
		this->piece = piece;
		if (piece != nullptr) {
			piece->setCurrentSquare(nullptr);
			piece->setCurrentSquare(this);
		}
		emit updatePieceSignal();
	}

	ModelSquare::~ModelSquare() {
	}
}