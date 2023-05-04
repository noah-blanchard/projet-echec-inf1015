#include "gtest/gtest.h"
#include "ModelKingPiece.h"
#include "ModelChecker.h"
#include "ModelRook.h"
#include "State.h"

TEST(ModelKingPiece, Test_Max2_King) {
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

TEST(CheckMate, Test_Checkmate_1) {
	logic::ModelKingPiece::resetInstanceCounter();
	logic::ModelChecker* checkerModel = logic::GameController::startGameFileLayout(new QFile("game_layouts/check_mate_situation1.txt"), false);
	EXPECT_EQ(logic::GameController::isGameOver(), false);
	logic::GameController::selectPiece(checkerModel->getSquareAtPosition(2, 0), checkerModel);
	logic::GameController::movePiece(checkerModel->getSquareAtPosition(0, 0), checkerModel);
	bool isCheckMate = false;
	EXPECT_EQ(logic::GameController::getCurrentTurn()->isGameOver(checkerModel, isCheckMate), true);
	logic::ModelKingPiece::resetInstanceCounter();
	logic::ModelKingPiece::resetInstanceCounter();
}
//TEST()