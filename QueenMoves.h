
#pragma once
#include "ValidMoves.h"
namespace model
{
	class QueenMoves : public ValidMoves
	{
	public:
		QueenMoves(Piece* piece);

		std::vector<Square*> get() override;

		std::vector<Square*> guess() override;

	private:
		static const std::array<std::pair<int, int>, 8> DISPLACEMENTS_;
		Piece* piece_;
	};
}

