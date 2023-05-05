
#pragma once
#include "ValidMoves.h"
namespace model
{
	class KnightMoves : public ValidMoves
	{
	public:
		KnightMoves(Piece* piece);

		std::vector<Square*> get() override;

		std::vector<Square*> guess() override;

	private:
		Piece* piece_;
		static const std::array<std::pair<int, int>, 8> DISPLACEMENTS_; // TODO : remplacer par un objet de type Move
	};
}
