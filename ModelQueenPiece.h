/**
 * @file ModelQueenPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Queen Piece
 * @date 20/04/2023
 */

#pragma once
#include "ModelPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace model {
	class Queen : public Piece
	{
	public:
		Queen() = default;
		Queen(bool isWhite);
		~Queen();
	private:
		static const std::string whiteImagePath_;
		static const std::string blackImagePath_;
	};
}

