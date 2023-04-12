#pragma once
#include "ModelPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	class ModelFouPiece : public ModelPiece
	{
	public:
		ModelFouPiece() = default;
		ModelFouPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {}
		//~ModelFouPiece();
		
		//get valid moves
		std::vector<ModelSquare*> getValidMoves(ModelChecker* checker, bool validate) override;
	private:
		static const std::string whiteImagePath;
		static const std::string blackImagePath;
	};
};


