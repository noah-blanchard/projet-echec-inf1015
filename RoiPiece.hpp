#pragma once

#include "BasePiece.hpp"

namespace logique {
	class RoiPiece : public BasePiece {
	public:

		RoiPiece() : BasePiece() {};
		RoiPiece(int ligne, int colonne, bool c);
		//~RoiPiece();

		std::vector<Position> deplacementsPossibles() override;
	private:
		static std::string imageBlanc;
		static std::string imageNoir;
	};
}