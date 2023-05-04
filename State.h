#pragma once
#include "modelChecker.h"
#include "ViewCheckerMainWindow.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include <map>
#include "GameManager.h"
#include "ModelKingPiece.h"
#include "ModelQueenPiece.h"
#include "ModelBishopPiece.h"
#include "ModelPawnPiece.h"
#include "ModelKnightPiece.h"
#include "ModelRook.h"
#include "CommandsInvoker.h"
#include "GameTurn.h"
#include "WhiteTurn.h"
#include "BlackTurn.h"
#include "Checkmate.h"


#pragma once
namespace model
{
	class GameController
	{
	public:


		static void selectPiece(Square* clickedSquare, Checker* checker);

		static void movePiece(Square* clickedSquare, Checker* checker);

		static void undo();

		static void redo();

		static GameTurn* getCurrentTurn();

		//static void startNewGame()
		//{
		//	if(checkerView_ != nullptr) checkerView_->close();
		//	checkerView_ = nullptr;
		//	currentTurn_ = whiteTurn_;
		//	Checker* checkerModel = new Checker();

		//	// créer les objets en utilisant std::make_shared
		//	auto blackKing = std::make_shared<King>(false);
		//	auto whiteKing = std::make_shared<King>(true);
		//	auto whiteBishop = std::make_shared<Bishop>(true);
		//	auto blackBishop = std::make_shared<Bishop>(false);
		//	auto blackPawn = std::make_shared<Pawn>(false, false);
		//	auto blackKnight = std::make_shared<Knight>(false);
		//	auto whiteQueen = std::make_shared<Queen>(true);

		//	// utiliser les shared_ptr pour initialiser les cases
		//	checkerModel->getSquareAtPosition(0, 3)->setPiece(blackKing);
		//	checkerModel->setBlackKingSquare(checkerModel->getSquareAtPosition(0, 3));
		//	checkerModel->getSquareAtPosition(5, 0)->setPiece(whiteKing);
		//	checkerModel->setWhiteKingSquare(checkerModel->getSquareAtPosition(5, 0));
		//	checkerModel->getSquareAtPosition(5, 6)->setPiece(blackPawn);
		//	checkerModel->getSquareAtPosition(6, 0)->setPiece(whiteBishop);
		//	checkerModel->getSquareAtPosition(6, 2)->setPiece(blackBishop);
		//	checkerModel->getSquareAtPosition(6, 4)->setPiece(blackKnight);
		//	checkerModel->getSquareAtPosition(0, 0)->setPiece(whiteQueen);

		//	checkerView_ = std::make_unique<view::CheckerMainWindow>(checkerModel);
		//	checkerView_->show();
		//}

		static void startGameFileLayout(QFile* file, bool showChessboard);
		static void restartGame();
		static std::shared_ptr<Piece> createPieceFromChar(char pieceChar, bool isWhite);
		static bool isGameOver();

		// for testing
		static Checker* testDefaultGame();
		static std::unique_ptr<Checker> testCheckmate1();

	private:
		inline static QFile* currentFileLayout_ = nullptr;
		inline static GameTurn* blackTurn_ = new BlackTurn;
		inline static GameTurn* whiteTurn_ = new WhiteTurn;
		inline static GameTurn* checkmate_ = new Checkmate;
		inline static GameTurn* currentTurn_ = whiteTurn_;
		inline static bool isGameOver_ = false;
		inline static std::map<GameTurn*, GameTurn*> transitions_ = { {whiteTurn_, blackTurn_}, {blackTurn_, whiteTurn_} };
		inline static std::unique_ptr<view::CheckerMainWindow> checkerView_ = nullptr;
	};
}