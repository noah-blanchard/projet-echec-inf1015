

#pragma once
#include "ValidMoves.h"
namespace model
{
	class KingMoves : public ValidMoves
	{
	public:
		KingMoves(Piece* piece);

		std::vector<Square*> get() override;

		std::vector<Square*> guess() override;

	private:
		Piece* piece_;
		static const std::array<std::pair<int, int>, 8> DISPLACEMENTS_;
	};
}

