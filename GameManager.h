/**
 * @file GameManager.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief GameManager class definition
 * @date 20/04/2023
 */

#pragma once
#include <memory>
#include "ModelChecker.h"
#include "ViewCheckerMainWindow.h"

namespace model {
	class GameManager {
	public:
		static void nextTurn();
		static bool isWhiteTurn();
		static bool isBlackTurn();

		// game objects
		static std::unique_ptr<Checker> checker;

		static void deletePieceAtPosition(int x, int y);
		static void startDefaultGame();
		static void startEndgame1();
		static void showChecker();
		static void closeChecker();
		static void testKingMax();
		static void reset();
	private:
		static bool whiteTurn_;
		static bool blackTurn_;
		static bool whiteCheck_;
		static bool blackCheck_;
		static bool whiteCheckMate_;
		static bool blackCheckMate_;

		//models
		//static std::unique_ptr<ModelChecker> checkerModel_;

		//views
		static std::unique_ptr<view::CheckerMainWindow> checkerView_;

	};
}
