
#pragma once
#include "ValidMoves.h"
namespace model
{
	class RookMoves : public ValidMoves
	{
	public:
		RookMoves(Piece* piece);

		std::vector<Square*> get() override;

		std::vector<Square*> guess() override;

	private:
		Piece* piece_;
		static const std::array<std::pair<int, int>, 4> DISPLACEMENTS_; // TODO : remplacer par un objet
	};
}

