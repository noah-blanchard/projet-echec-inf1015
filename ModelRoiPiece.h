#pragma once
#include <string>
#include "ModelPiece.h"

namespace logic {
	//static int counter;

	class ModelRoiPiece : public ModelPiece
	{
	public:
		ModelRoiPiece(bool isWhite);
		ModelRoiPiece();
		//~ModelRoiPiece();
		static void resetInstanceCounter();
		bool isKing() override;
		//get valid moves
		std::vector<ModelSquare*> getValidMoves(ModelChecker* checker, bool validate) override;

	private:
		static const std::string whiteImagePath;
		static const std::string blackImagePath;
		static int instanceCounter;
	};
}

