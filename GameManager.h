#pragma once
#include <memory>
#include "ModelChecker.h"
#include "ViewChecker.h"

namespace logic {
	class GameManager {
	public:
		static void nextTurn();
		static bool isWhiteTurn();
		static bool isBlackTurn();

		// game objects
		static std::unique_ptr<ModelChecker> checker;

		static void deletePieceAtPosition(int x, int y);
		static void startDefaultGame();
		static void startEndgame1();
		static void showChecker();
		static void closeChecker();
		static void testKingMax();
		static void reset();
	private:
		static bool whiteTurn;
		static bool blackTurn;
		static bool whiteCheck;
		static bool blackCheck;
		static bool whiteCheckMate;
		static bool blackCheckMate;

		//models
		static std::unique_ptr<ModelChecker> checkerModel;

		//views
		static std::unique_ptr<view::ViewChecker> checkerView;

	};
}
