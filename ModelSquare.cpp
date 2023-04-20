/**
 * @file ModelSquare.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelSquare class
 * @date 20/04/2023
 */

#pragma once
#include "ModelSquare.h"

namespace logic {
	void ModelSquare::setPlayable(bool p) { 
		playable_ = p;
		emit playableSignal();
	}

	void ModelSquare::setPiece(std::shared_ptr<ModelPiece> piece) { 
		this->piece_ = piece;
		if (piece != nullptr) {
			piece->setCurrentSquare(nullptr);
			piece->setCurrentSquare(this);
		}
		emit updatePieceSignal();
	}

	ModelSquare::~ModelSquare() {
	}
}