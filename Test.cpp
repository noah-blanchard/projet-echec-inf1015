#include "gtest/gtest.h"
#include "ModelKingPiece.h"
#include "ModelChecker.h"
#include "ModelRook.h"
#include "State.h"

TEST(ChessGame, Test_Max2_King) {
	logic::ModelKingPiece::resetInstanceCounter();
	logic::ModelKingPiece* king1 = new logic::ModelKingPiece(true);
	logic::ModelKingPiece* king2 = new logic::ModelKingPiece(true);
	try {
		EXPECT_ANY_THROW(logic::ModelKingPiece * king3 = new logic::ModelKingPiece(true));
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete king1;
	delete king2;
	logic::ModelKingPiece::resetInstanceCounter();

}

// test check mate situation 1

TEST(ChessGame, Test_Checkmate_1) {
	logic::ModelKingPiece::resetInstanceCounter();
	logic::ModelChecker* checkerModel = logic::GameController::startGameFileLayout(new QFile("game_layouts/check_mate_situation1.txt"), false);
	EXPECT_EQ(logic::GameController::isGameOver(), false);
	logic::GameController::selectPiece(checkerModel->getSquareAtPosition(2, 0), checkerModel);
	logic::GameController::movePiece(checkerModel->getSquareAtPosition(0, 0), checkerModel);
	bool isCheckMate = false;
	EXPECT_EQ(logic::GameController::getCurrentTurn()->isGameOver(checkerModel, isCheckMate), true);
	logic::ModelKingPiece::resetInstanceCounter();
	logic::ModelKingPiece::resetInstanceCounter();
	delete checkerModel;
}

// test no moves for king in the start of the game
TEST(ChessGame, No_Possible_Moves) {
	logic::ModelKingPiece::resetInstanceCounter();
	logic::ModelChecker* checkerModel = logic::GameController::startGameFileLayout(new QFile("game_layouts/classic_game_layout.txt"), false);
	EXPECT_EQ(checkerModel->getSquareAtPosition(7, 4)->getPiece()->getValidMoves2(checkerModel, false).size(), 0);
	logic::ModelKingPiece::resetInstanceCounter();
	delete checkerModel;
}