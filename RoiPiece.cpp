#pragma once

#include "RoiPiece.hpp"
#include "Position.hpp"
#include <QPixmap>

namespace logique {
	
	std::string RoiPiece::imageBlanc = "images/black/roi_black.png";
	std::string RoiPiece::imageNoir = "images/white/roi_white.png";
	RoiPiece::RoiPiece(int col, int ligne, bool c) : BasePiece(col, ligne, c, RoiPiece::imageBlanc, RoiPiece::imageNoir) { }
	
	std::vector<Position> RoiPiece::deplacementsPossibles() {

		std::vector<Position> deplacements;
		
		if (position.ligne > 0) {
			deplacements.push_back(Position(position.ligne - 1, position.colonne));
			if (position.colonne > 0)
			{
				deplacements.push_back(Position(position.ligne - 1, position.colonne - 1));
			}
			if (position.colonne < 7)
			{
				deplacements.push_back(Position(position.ligne - 1, position.colonne + 1));
			}
		}
		if (position.ligne < 7)
		{
			deplacements.push_back(Position(position.ligne + 1, position.colonne));
			if (position.colonne > 0)
			{
				deplacements.push_back(Position(position.ligne + 1, position.colonne - 1));
			}
			if (position.colonne < 7)
			{
				deplacements.push_back(Position(position.ligne + 1, position.colonne + 1));
			}
		}
			if (position.colonne > 0)
			{
				deplacements.push_back(Position(position.ligne, position.colonne - 1));
			}
			if (position.colonne < 7)
			{
				deplacements.push_back(Position(position.ligne, position.colonne + 1));
			}

			
			
			return deplacements;
		
	}
}