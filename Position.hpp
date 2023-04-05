#pragma once

namespace logique {

	class Position {
	public:
		Position() = default;
		Position(int ligne, int colonne) : ligne(ligne), colonne(colonne) {}
	
	//private:
		int ligne = 0;
		int colonne = 0;
	};
	
}