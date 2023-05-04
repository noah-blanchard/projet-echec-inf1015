#include "gtest/gtest.h"
#include "ModelKingPiece.h"

TEST(ModelKingPiece, Test_Max2_King) {
  logic::ModelKingPiece::resetInstanceCounter();
  logic::ModelKingPiece* king1 = new logic::ModelKingPiece(true);
  logic::ModelKingPiece* king2 = new logic::ModelKingPiece(true);
  EXPECT_ANY_THROW(logic::ModelKingPiece* king3 = new logic::ModelKingPiece(true));
  delete king1;
  delete king2;
}