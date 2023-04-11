#pragma once
#include "ModelSquare.h"
#include <QObject>

namespace logic {
	//class ModelSquare;
	class ModelChecker : public QObject
	{
		Q_OBJECT
	public:
		ModelChecker();
		~ModelChecker();
		ModelSquare* getSquareAtPosition(int x, int y) const;	
		void setSelectedSquare(ModelSquare* square);
		ModelSquare* getSelectedSquare() const;
		void resetPlayableSquares();
		// validate move with reference to std vector
		bool validateMove(ModelSquare* currentSquare, ModelSquare* move);
		
		void setWhiteKingSquare(ModelSquare* square);
		void setBlackKingSquare(ModelSquare* square);
	private:
		ModelSquare* whiteKingSquare;
		ModelSquare* blackKingSquare;
		ModelSquare* squares[8][8];
		ModelSquare* selectedSquare = nullptr;

	signals:
		void unallowedMoveSignal();
	
	};
}

