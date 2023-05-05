#pragma once
#include "modelChecker.h"
#include "ViewCheckerMainWindow.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include <map>
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

		static void startGameFileLayout(std::string& file, bool showChessboard);
		static void restartGame();
		static bool isPieceAllowed(Piece* piece);
		static std::shared_ptr<Piece> createPieceFromChar(char pieceChar, bool isWhite);
		static bool isGameOver();

		// for testing
		static Checker* testDefaultGame();
		static std::unique_ptr<Checker> testCheckmate1();

	private:
		inline static std::string currentFileLayout_ = "";
		inline static std::shared_ptr<GameTurn> blackTurn_ = std::make_shared<BlackTurn>();
		inline static std::shared_ptr<GameTurn> whiteTurn_ = std::make_shared<WhiteTurn>();
		inline static std::shared_ptr<GameTurn> checkmate_ = std::make_shared<Checkmate>();
		inline static std::shared_ptr<GameTurn> currentTurn_ = whiteTurn_;
		inline static bool isGameOver_ = false;
		inline static std::map<std::shared_ptr<GameTurn>, std::shared_ptr<GameTurn>> transitions_ = { {whiteTurn_, blackTurn_}, {blackTurn_, whiteTurn_} };
		inline static std::shared_ptr<view::CheckerMainWindow> checkerView_ = nullptr;

	};
}