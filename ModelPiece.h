/**
 * @file ModelPiece.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief Model for the Piece
 * @date 20/04/2023
 */

#pragma once
#include <string>
#include <vector>
#include <QObject>
//#include "ModelSquare.h"

namespace model {


	class Piece : public QObject
	{
		Q_OBJECT
			
	public:
		Piece() = default;
		Piece(bool isWhite, std::string whitePath, std::string blackPath);
		~Piece();

		bool isWhite();
		//virtual std::vector<class ModelSquare*> getValidMoves(class ModelChecker* checker, bool validate) = 0;
		virtual std::vector<class Square *> getValidMoves2(class Checker* checker, bool validate);
		std::string getImagePath() const { return imagePath_; }
		void setCurrentSquare(Square * square);
		virtual bool isFirstMove();
		virtual void firstMoveDone();
		virtual bool isKing();
		virtual bool transform(Square* square);
		//void move(ModelSquare* square);
	
	protected:
		std::vector<class ValidMovesCalculator*> calculators_;
		Square* currentSquare = nullptr;
	private:
		std::string imagePath_;
		bool white_;

	/*signals:
		void movedSignal();*/
	};
}

