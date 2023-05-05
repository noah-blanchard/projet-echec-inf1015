/**
 * @file ModelQueenPiece.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief Implementation of the Queen Piece
 * @date 20/04/2023
 */

#include "ModelQueenPiece.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include "RookMoves.h"
#include "BishopMoves.h"

namespace model
{
	const std::string Queen::whiteImagePath_ = "images/white/reine_white.png";
	const std::string Queen::blackImagePath_ = "images/black/reine_black.png";
	
	Queen::Queen(bool isWhite) : Piece(isWhite, whiteImagePath_, blackImagePath_) {
		
		calculators_.push_back(new RookMoves());
		calculators_.push_back(new BishopMoves());

	}
	Queen::~Queen()
	{
		for (auto& calculator : calculators_)
		{
			delete calculator;
		}
		calculators_.clear();
	}
}