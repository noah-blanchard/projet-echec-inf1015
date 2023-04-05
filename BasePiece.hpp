#pragma once
#include "Position.hpp"
#include <vector>

namespace logique {
	
	class BasePiece {
	public:
		BasePiece() = default;
		BasePiece(int col, int ligne, bool c) : position(col, ligne), camp(c) {}
		~BasePiece();

		void moveTo(Position);
		virtual void transform(BasePiece piece) = 0; // on verra au niveau du paramètre
		virtual std::vector<Position> deplacementsPossibles() = 0;
		
	//private:
		Position position;
		bool camp;
	};
	
}