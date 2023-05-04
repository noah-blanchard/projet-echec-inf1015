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

namespace model {
	//class ModelSquare;
	class Checker : public QObject
	{
		Q_OBJECT
	public:
		Checker();
		~Checker();
		Square* getSquareAtPosition(int x, int y) const;	
		void setSelectedSquare(Square* square);
		Square* getSelectedSquare() const;
		void resetPlayableSquares();
		// validate move with reference to std vector
		bool validateMove(Square* currentSquare, Square* move);
		
		void setWhiteKingSquare(Square* square);
		void setBlackKingSquare(Square* square);
		Square* getWhiteKingSquare() const { return whiteKingSquare_; }
		Square* getBlackKingSquare() const { return blackKingSquare_; }
	private:
		Square* whiteKingSquare_;
		Square* blackKingSquare_;
		Square* squares_[8][8];
		//std::unique_ptr < std::shared_ptr<ModelSquare*>> squares;
		Square* selectedSquare_ = nullptr;

	signals:
		void unallowedMoveSignal();
	
	};
}

