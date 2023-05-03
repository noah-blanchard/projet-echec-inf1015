/**
 * @file ModelSquare.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the ModelSquare class
 * @date 20/04/2023
 */

#pragma once
#include "ModelSquare.h"
#include "ModelQueenPiece.h"
#include "ModelBishopPiece.h"
#include "ModelKnightPiece.h"

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
		/*if (piece != nullptr && piece->transform(this)) {
			emit transformPieceSignal();
		}*/
		//else {
			emit updatePieceSignal();
		//}
	}

	void ModelSquare::emitTransformSignal() {
		emit transformPieceSignal();
	}

	void ModelSquare::transformPiece(std::string selected) {
		if (selected == "Queen") {
			this->setPiece(std::make_shared<ModelQueenPiece>(this->getPiece()->isWhite()));
		}
		//else if (*selected == "Rook") {
		//	this->setPiece(std::make_shared<ModelRookPiece>(this->getPiece()->isWhite()));
		//}
		else if (selected == "Bishop") {
			this->setPiece(std::make_shared<ModelBishopPiece>(this->getPiece()->isWhite()));
		}
		else if (selected == "Knight") {
			this->setPiece(std::make_shared<ModelKnightPiece>(this->getPiece()->isWhite()));
		}
		/*	else {
				throw std::invalid_argument("Invalid piece type");
			}*/

		emit updatePieceSignal();
	}

	ModelSquare::~ModelSquare() {
	}
}