#pragma once
#include <string>
#include "ModelPiece.h"

namespace logic {
	class ModelRoiPiece : public ModelPiece
	{
	public:
		ModelRoiPiece() = default;
		ModelRoiPiece(bool isWhite) : ModelPiece(isWhite, whiteImagePath, blackImagePath) {}
		//~ModelRoiPiece();
		
		//get valid moves
		std::vector<ModelSquare*> getValidMoves(ModelChecker* checker) override;

	private:
		static const std::string whiteImagePath;
		static const std::string blackImagePath;
	};
}

