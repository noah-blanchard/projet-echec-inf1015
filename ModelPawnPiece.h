/**
 * @file ModelPawnPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Pawn Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"

namespace model {
	class Pawn : public Piece
	{
	public:
		Pawn() = default;
		Pawn(bool isWhite, bool firstMove);
		//~ModelPionPiece();

		//get valid moves
		//std::vector<ModelSquare*> getValidMoves(ModelChecker* checker, bool validate) override;
		bool isFirstMove() override;
		void firstMoveDone() override;
		bool transform(Square* square) override;
	
	private:
		bool firstMove_ = true;
		static const std::string whiteImagePath_;
		static const std::string blackImagePath_;
	};
}

