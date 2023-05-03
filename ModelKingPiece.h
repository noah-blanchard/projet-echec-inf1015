/**
 * @file ModelKingPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the King Piece
 * @date 20/04/2023
 */

#pragma once
#include <string>
#include "ModelPiece.h"

namespace logic {
	//static int counter;

	class ModelKingPiece : public ModelPiece
	{
	public:
		ModelKingPiece(bool isWhite);
		ModelKingPiece();
		//~ModelRoiPiece();
		static void resetInstanceCounter();
		bool isKing() override;
		//get valid moves
		//std::vector<ModelSquare*> getValidMoves(ModelChecker* checker, bool validate) override;

	private:
		static const std::string whiteImagePath_;
		static const std::string blackImagePath_;
		static int instanceCounter_;
	};
}

