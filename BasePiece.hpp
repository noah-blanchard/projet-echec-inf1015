#pragma once
#include "Position.hpp"
#include <vector>
#include <QPixmap>

namespace logique {
	
	class BasePiece {
	public:
		
		BasePiece() = default;
		BasePiece(int col, int ligne, bool c, std::string blanc, std::string noir) : position(Position(col, ligne)), camp(c) {
			if (camp) {
				image = blanc;
			}
			else {
				image = noir;
			}
		}

		void moveTo(Position);
		//virtual void transform(BasePiece piece); // on verra au niveau du paramètre
		virtual std::vector<Position> deplacementsPossibles() = 0;
		
		Position position;
		bool camp;
		std::string image;
	private:
		static std::string imageNoir;
		static std::string imageBlanc;
	};
	
}