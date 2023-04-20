/**
 * @file ModelQueenPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Queen Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	//class ModelChecker;
	class ModelQueenPiece : public ModelPiece
	{
	public:
		ModelQueenPiece() = default;
		ModelQueenPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath_, blackImagePath_) {}
		//~ModelReinePiece();
		//get valid moves
		std::vector<ModelSquare*> getValidMoves(ModelChecker* checker, bool validate) override;
	private:
		static const std::string whiteImagePath_;
		static const std::string blackImagePath_;
	};
}

