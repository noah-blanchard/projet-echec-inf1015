#include "gtest/gtest.h"
#include "ModelKingPiece.h"
#include "ModelChecker.h"
#include "ModelRook.h"
#include "State.h"
#include <QApplication>

TEST(ChessGame, Test_Max2_King) {
	model::King::resetInstanceCounter();
	model::King* king1 = new model::King(true);
	model::King* king2 = new model::King(true);
	try {
		EXPECT_ANY_THROW(model::King * king3 = new model::King(true));
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete king1;
	delete king2;
	model::King::resetInstanceCounter();

}

// test check mate situation 1

TEST(ChessGame, Test_Checkmate_1) {
	model::King::resetInstanceCounter();
	model::Checker* checkerModel = model::GameController::testCheckmate1();
	EXPECT_EQ(model::GameController::isGameOver(), false);
	model::GameController::selectPiece(checkerModel->getSquareAtPosition(2, 0), checkerModel);
	model::GameController::movePiece(checkerModel->getSquareAtPosition(0, 0), checkerModel);
	bool isCheckMate = false;
	EXPECT_EQ(model::GameController::getCurrentTurn()->isGameOver(checkerModel, isCheckMate), true);
	model::King::resetInstanceCounter();
	model::King::resetInstanceCounter();
	delete checkerModel;
}

// test no moves for king in the start of the game
TEST(ChessGame, No_Possible_Moves) {
	model::King::resetInstanceCounter();
	model::Checker* checkerModel = model::GameController::testDefaultGame();
	EXPECT_EQ(checkerModel->getSquareAtPosition(7, 4)->getPiece()->getValidMoves2(checkerModel, false).size(), 0);
	model::King::resetInstanceCounter();
	delete checkerModel;
}

// test the impossibility to play when it 's not your turn
TEST(ChessGame, No_White_Play_When_Black_Turn) {
	model::King::resetInstanceCounter();
	model::Checker* checkerModel = model::GameController::testDefaultGame();
	// selecting a white piece
	model::GameController::selectPiece(checkerModel->getSquareAtPosition(6, 0), checkerModel);
	EXPECT_TRUE(checkerModel->getSelectedSquare() != nullptr);
	EXPECT_TRUE(checkerModel->getSelectedSquare()->getPiece()->isWhite() == true);
	// moving a white piece
	model::GameController::movePiece(checkerModel->getSquareAtPosition(5, 0), checkerModel);
	EXPECT_TRUE(checkerModel->getSelectedSquare() == nullptr);

	// trying to select a white piece again
	model::GameController::selectPiece(checkerModel->getSquareAtPosition(5, 0), checkerModel);
	EXPECT_TRUE(checkerModel->getSelectedSquare() == nullptr);
	model::King::resetInstanceCounter();
	delete checkerModel;
}