#pragma once

namespace logique {

	class CaseLogique {
	public:
		CaseLogique() = default;
		CaseLogique(int ligne, int colonne) : ligne(ligne), colonne(colonne) {}
	
	//private:
		int ligne = 0;
		int colonne = 0;
		BasePiece *occupant;
	};
	
}