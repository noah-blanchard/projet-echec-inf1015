#pragma once
#include <vector>
#include "ValidMoves.h"
namespace model
{
	class Piece
	{
	public:
		Piece(bool isWhite);

		bool isWhite() const;

		virtual std::vector<Square*> getMoves() = 0;

	private:
		bool isWhite_;
	};
}