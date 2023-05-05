#include "GameController.h"

namespace model
{
	std::shared_ptr<PlayerTurn> GameController::whiteTurn_ = std::make_shared<WhiteTurn>();
	std::shared_ptr<PlayerTurn> GameController::blackTurn_ = std::make_shared<BlackTurn>();
	std::shared_ptr<PlayerTurn> GameController::checkmate_ = std::make_shared<GameOver>();
	std::shared_ptr<PlayerTurn> GameController::currentTurn_ = whiteTurn_;
	std::unordered_map<std::shared_ptr<PlayerTurn>, std::shared_ptr<PlayerTurn>> GameController::transitions_ = { {whiteTurn_, blackTurn_}, {blackTurn_, whiteTurn_} };
	 std::unique_ptr<view::ViewCheckerMainWindow> GameController::checkerView_ = nullptr;
	void GameController::selectPiece(Piece* piece)
	{
		currentTurn_->selectPiece(piece);
	}

	void GameController::movePiece(Piece* piece, Square* selectedSquare)
	{
		// change the state

		currentTurn_->movePiece(piece, selectedSquare);
		currentTurn_ = transitions_[currentTurn_];

		if (currentTurn_->isGameOver())
		{
			currentTurn_ = checkmate_;
		}

	}

	void GameController::startNewGame()
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
}
