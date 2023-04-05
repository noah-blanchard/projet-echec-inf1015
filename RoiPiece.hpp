#pragma once

#include "BasePiece.hpp"

namespace logique {
	class RoiPiece : public BasePiece {
	public:
		RoiPiece() : BasePiece() {};
		RoiPiece(int ligne, int colonne, bool c) : BasePiece(ligne, colonne, c) {}
		~RoiPiece();

		std::vector<Position> deplacementsPossibles() override;
	private:

	};
}