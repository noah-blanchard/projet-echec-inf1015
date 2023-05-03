#pragma once
#include <memory>
#include <QObject>
#include "ModelSquare.h"

namespace logic {
 //singleton chessboard
	class ChessBoard 
	{
	public:
		static ChessBoard* getInstance();
		static void deleteInstance();
		//void setSquareAtPosition(int x, int y, ModelSquare* square);
		ModelSquare* getSquareAtPosition(int x, int y) const;
		void setSelectedSquare(ModelSquare* square);
		ModelSquare* getSelectedSquare() const;
		void setWhiteKingSquare(ModelSquare* square);
		void setBlackKingSquare(ModelSquare* square);
		ModelSquare* getWhiteKingSquare() const { return whiteKingSquare_.get(); }
		ModelSquare* getBlackKingSquare() const { return blackKingSquare_.get(); }
		void resetPlayableSquares();
		bool validateMove(ModelSquare* currentSquare, ModelSquare* move);
		//void resetPlayableSquares();
		// validate move with reference to std vector
		//bool validateMove(ModelSquare* currentSquare, ModelSquare* move);
		//void setWhiteKingSquare(ModelSquare* square);
		//void setBlackKingSquare(ModelSquare* square);
		//ModelSquare* getWhiteKingSquare() const { return whiteKingSquare_; }
		//ModelSquare* getBlackKingSquare() const { return blackKingSquare_; }
	private:
		ChessBoard();
		//~ChessBoard();
		//ChessBoard(const ChessBoard&) = delete;
		//ChessBoard& operator=(const ChessBoard&) = delete;
		static std::shared_ptr<ChessBoard> instance_;
		std::shared_ptr<ModelSquare> whiteKingSquare_;
		std::shared_ptr<ModelSquare> blackKingSquare_;
		std::shared_ptr<ModelSquare> squares_[8][8];
		std::shared_ptr<ModelSquare> selectedSquare_ = nullptr;

	};
}

