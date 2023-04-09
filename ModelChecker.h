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
	private:
		ModelSquare* squares[8][8];
		ModelSquare* selectedSquare = nullptr;
	};
}

