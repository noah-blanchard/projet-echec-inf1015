///**
// * @file GameManager.cpp
// * @author Noah Blanchard / Bai Wu Li
// * @brief GameManager class implementation
// * @date 20/04/2023
// */
//
//
//#pragma once
//#include <memory>
//#include "GameManager.h"
//#include "ModelKingPiece.h"
//#include "ModelQueenPiece.h"
//#include "ModelBishopPiece.h"
//#include "ModelPawnPiece.h"
//#include "ModelKnightPiece.h"
//
//namespace logic
//{
//    // initialize game variables
//    bool GameManager::whiteTurn_      =  true;
//    bool GameManager::blackTurn_      = false;
//    bool GameManager::whiteCheck_     = false;
//    bool GameManager::blackCheck_     = false;
//    bool GameManager::whiteCheckMate_ = false;
//    bool GameManager::blackCheckMate_ = false;
//    //std::unique_ptr<logic::ModelChecker> GameManager::checkerModel_ = nullptr;
//    std::unique_ptr<view::ViewCheckerMainWindow> GameManager::checkerView_ = nullptr;
//
//    void GameManager::nextTurn()
//    {
//        whiteTurn_ = !whiteTurn_;
//        blackTurn_ = !blackTurn_;
//    }
//
//    bool GameManager::isWhiteTurn()
//    {
//        return whiteTurn_;
//    }
//
//    bool GameManager::isBlackTurn()
//    {
//        return blackTurn_;
//    }
//
//    void GameManager::startEndgame1() {
//        ModelChecker* checkerModel = new ModelChecker();
//
//        // créer les objets en utilisant std::make_shared
//        auto blackKing   = std::make_shared<ModelKingPiece>(false);
//        auto whiteKing   = std::make_shared<ModelKingPiece>(true);
//        auto whiteBishop = std::make_shared<ModelBishopPiece>(true);
//        auto blackBishop = std::make_shared<ModelBishopPiece>(false);
//        auto blackPawn   = std::make_shared<ModelPawnPiece>(false, false);
//		auto blackKnight = std::make_shared<ModelKnightPiece>(false);
//        auto whiteQueen = std::make_shared<ModelQueenPiece>(true);
//
//        // utiliser les shared_ptr pour initialiser les cases
//        checkerModel->getSquareAtPosition(0, 3)->setPiece(blackKing);
//        checkerModel->setBlackKingSquare(checkerModel->getSquareAtPosition(0, 3));
//        checkerModel->getSquareAtPosition(5, 0)->setPiece(whiteKing);
//        checkerModel->setWhiteKingSquare(checkerModel->getSquareAtPosition(5, 0));
//        checkerModel->getSquareAtPosition(5, 6)->setPiece(blackPawn);
//        checkerModel->getSquareAtPosition(6, 0)->setPiece(whiteBishop);
//        checkerModel->getSquareAtPosition(6, 2)->setPiece(blackBishop);
//		checkerModel->getSquareAtPosition(6, 4)->setPiece(blackKnight);
//        checkerModel->getSquareAtPosition(0, 0)->setPiece(whiteQueen);
//
//        checkerView_ = std::make_unique<view::ViewCheckerMainWindow>(checkerModel);
//        showChecker();
//    }
//
//    void GameManager::testKingMax() {
//  //     try {
//  //         checkerModel_ = std::make_unique<logic::ModelChecker>();
//  //          checkerView_ = std::make_unique<view::ViewCheckerMainWindow>(checkerModel_.get());
//  //          showChecker();
//		//	auto king1 = std::make_shared<ModelKingPiece>(true);
//  //          checkerModel_->getSquareAtPosition(0, 0)->setPiece(king1);
//		//	checkerView_->showInfo("King 1 created");
//		//	auto king2 = std::make_shared<ModelKingPiece>(false);
//  //          checkerModel_->getSquareAtPosition(0, 1)->setPiece(king2);
//		//	checkerView_->showInfo("King 2 created");
//		//	auto king3 = std::make_shared<ModelKingPiece>(true);
//		//}
//  //      catch (std::exception& e) {
//  //          checkerView_->showError(e.what());
//  //      }
//    }
//
//    void GameManager::reset()
//    {
//        ModelKingPiece::resetInstanceCounter();
//        closeChecker();
//        //checkerModel_ = nullptr;
//        checkerView_ = nullptr;
//    }
//
//    void GameManager::showChecker() {
//        if (checkerView_ != nullptr)
//         checkerView_->show();
//    }
//
//    void GameManager::closeChecker() {
//        if(checkerView_ != nullptr)
//		    checkerView_->close();
//    }
//
//}
