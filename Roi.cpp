#pragma once

#include "RoiPiece.hpp"
#include "Position.hpp"

namespace logique {
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

		
	}
}