#pragma once
#include <string>
#include "ModelPiece.h"

namespace logic {
	//static int counter;

	class ModelRoiPiece : public ModelPiece
	{
	public:
		ModelRoiPiece() = default;
		ModelRoiPiece(bool isWhite);
		//~ModelRoiPiece();
		bool isKing() override;
		//get valid moves
		std::vector<ModelSquare*> getValidMoves(ModelChecker* checker) override;

	private:
		static const std::string whiteImagePath;
		static const std::string blackImagePath;
	};
}

