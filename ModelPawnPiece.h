/**
 * @file ModelPawnPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Pawn Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"

namespace logic {
	class ModelPawnPiece : public ModelPiece
	{
	public:
		ModelPawnPiece() = default;
		ModelPawnPiece(bool isWhite, bool firstMove);
		//~ModelPionPiece();

		//get valid moves
		//std::vector<ModelSquare*> getValidMoves(ModelChecker* checker, bool validate) override;
		bool isFirstMove() override;
		void firstMoveDone() override;
		bool transform(ModelSquare* square) override;
	
	private:
		bool firstMove_ = true;
		static const std::string whiteImagePath_;
		static const std::string blackImagePath_;
	};
}

