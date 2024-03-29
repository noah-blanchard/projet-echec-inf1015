/**
 * @file ModelKingPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the King Piece
 * @date 20/04/2023
 */

#pragma once
#include <string>
#include "ModelPiece.h"

namespace model {
	//static int counter;

	class King : public Piece
	{
	public:
		King(bool isWhite);
		King();
		~King();
		static void resetInstanceCounter();
		bool isKing() override;

	private:
		static const std::string whiteImagePath_;
		static const std::string blackImagePath_;
		static int instanceCounter_;
	};
}

