/**
 * @file ModelChecker.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Checker Board
 * @date 20/04/2023
 */

#pragma once
#include "ModelSquare.h"
#include "TempModelSquare.h"
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
		ModelSquare* getWhiteKingSquare() const { return whiteKingSquare_; }
		ModelSquare* getBlackKingSquare() const { return blackKingSquare_; }
	private:
		ModelSquare* whiteKingSquare_;
		ModelSquare* blackKingSquare_;
		ModelSquare* squares_[8][8];
		//std::unique_ptr < std::shared_ptr<ModelSquare*>> squares;
		ModelSquare* selectedSquare_ = nullptr;

	signals:
		void unallowedMoveSignal();
	
	};
}

