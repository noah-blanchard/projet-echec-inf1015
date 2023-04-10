#pragma once
#include "ModelPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace logic {
	//class ModelChecker;
	class ModelReinePiece : public ModelPiece
	{
	public:
		ModelReinePiece() = default;
		ModelReinePiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {}
		//~ModelReinePiece();
		//get valid moves
		std::vector<ModelSquare*> getValidMoves(ModelChecker* checker) override;
	private:
		static const std::string whiteImagePath;
		static const std::string blackImagePath;
	};
}

