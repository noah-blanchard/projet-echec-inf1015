
#pragma once
#include "ChessBoard.h"
#include "WhiteTurn.h"
#include "BlackTurn.h"
#include "GameOver.h"
#include "ViewCheckerMainWindow.h"

namespace model
{
	class GameController
	{
	public:
		static void selectPiece(Piece* piece)
		{
			currentTurn_->selectPiece(piece);
		}

		static void movePiece(Piece* piece, Square* selectedSquare)
		{
			// change the state

			currentTurn_->movePiece(piece, selectedSquare);
			currentTurn_ = transitions_[currentTurn_];

			if (currentTurn_->isGameOver())
			{
				currentTurn_ = checkmate_;
			}

		}

		static void startNewGame()
		{
			checkerView_ = nullptr;
			currentTurn_ = whiteTurn_;
			//ChessBoard::addPiece<class King>(0, 3, false);
			//ChessBoard::addPiece<class King>(5, 0, true);
			//ChessBoard::addPiece<class Queen>(0, 4, false);
			//ChessBoard::addPiece<class Queen>(5, 1, true);
			//ChessBoard::addPiece<class Bishop>(0, 2, false);
			//ChessBoard::addPiece<class Bishop>(5, 2, true);
			//ChessBoard::addPiece<class Bishop>(0, 5, false);
			//ChessBoard::addPiece<class Bishop>(5, 5, true);

			checkerView_ = std::make_unique<view::ViewCheckerMainWindow>();
			checkerView_->show();
		}

	private:
		inline static std::shared_ptr<PlayerTurn> whiteTurn_ = std::make_shared<WhiteTurn>();
		inline static std::shared_ptr<PlayerTurn> blackTurn_ = std::make_shared<BlackTurn>();
		inline static std::shared_ptr<PlayerTurn> checkmate_ = std::make_shared<GameOver>();
		inline static std::shared_ptr<PlayerTurn> currentTurn_ = whiteTurn_;
		inline static std::unordered_map<std::shared_ptr<PlayerTurn>, std::shared_ptr<PlayerTurn>> transitions_ = { {whiteTurn_, blackTurn_}, {blackTurn_, whiteTurn_} };
		inline static std::unique_ptr<view::ViewCheckerMainWindow> checkerView_ = nullptr;
	};
}


