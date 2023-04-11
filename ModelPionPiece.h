#pragma once
#include "ModelPiece.h"

namespace logic {
	class ModelPionPiece : public ModelPiece
	{
	public:
		ModelPionPiece() = default;
		ModelPionPiece(bool isWhite, bool firstMove);
		//~ModelPionPiece();

		//get valid moves
		std::vector<ModelSquare*> getValidMoves(ModelChecker* checker) override;
	
	private:
		bool firstMove = true;
		static const std::string whiteImagePath;
		static const std::string blackImagePath;
	};
}

