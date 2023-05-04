/**
 * @file ModelBishopPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Bishop Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace model {
	class Bishop : public Piece
	{
	public:
		Bishop() = default;
		Bishop(bool isWhite);
		//~ModelFouPiece();
		
		//get valid moves
		//std::vector<ModelSquare*> getValidMoves(ModelChecker* checker, bool validate) override;
	private:
		static const std::string whiteImagePath_;
		static const std::string blackImagePath_;
	};
};


