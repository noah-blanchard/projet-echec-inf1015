/**
 * @file GameManager.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief GameManager class implementation
 * @date 20/04/2023
 */


#pragma once
#include "GameManager.h"
#include "ModelKingPiece.h"
#include "ModelBishopPiece.h"
#include "ModelPawnPiece.h"
#include <memory>
#include "ModelKnightPiece.h"

namespace logic {

    // initialize game variables

    bool GameManager::whiteTurn_ = true;
    bool GameManager::blackTurn_ = false;
    bool GameManager::whiteCheck_ = false;
    bool GameManager::blackCheck_ = false;
    bool GameManager::whiteCheckMate_ = false;
    bool GameManager::blackCheckMate_ = false;
    std::unique_ptr<logic::ModelChecker> GameManager::checkerModel_ = nullptr;
    std::unique_ptr<view::ViewCheckerMainWindow> GameManager::checkerView_ = nullptr;

    void GameManager::nextTurn() {
        whiteTurn_ = !whiteTurn_;
        blackTurn_ = !blackTurn_;
    }

    bool GameManager::isWhiteTurn() {
        return whiteTurn_;
    }

    bool GameManager::isBlackTurn() {
        return blackTurn_;
    }

    void GameManager::startEndgame1() {
        checkerModel_ = std::make_unique<logic::ModelChecker>();

        // créer les objets en utilisant std::make_shared
        auto roiNoir = std::make_shared<ModelKingPiece>(false);
        auto roiBlanc = std::make_shared<ModelKingPiece>(true);
        auto fouBlanc = std::make_shared<ModelBishopPiece>(true);
        auto fouNoir = std::make_shared<ModelBishopPiece>(false);
        auto pionNoir = std::make_shared<ModelPawnPiece>(false, false);
		auto cavalierNoir = std::make_shared<ModelKnightPiece>(false);

        // utiliser les shared_ptr pour initialiser les cases
        checkerModel_->getSquareAtPosition(0, 3)->setPiece(roiNoir);
        checkerModel_->setBlackKingSquare(checkerModel_->getSquareAtPosition(0, 3));
        checkerModel_->getSquareAtPosition(5, 0)->setPiece(roiBlanc);
        checkerModel_->setWhiteKingSquare(checkerModel_->getSquareAtPosition(5, 0));
        checkerModel_->getSquareAtPosition(5, 6)->setPiece(pionNoir);
        checkerModel_->getSquareAtPosition(6, 0)->setPiece(fouBlanc);
        checkerModel_->getSquareAtPosition(6, 2)->setPiece(fouNoir);
		checkerModel_->getSquareAtPosition(6, 4)->setPiece(cavalierNoir);

        checkerView_ = std::make_unique<view::ViewCheckerMainWindow>(checkerModel_.get());
        showChecker();
    }

    void GameManager::testKingMax() {
       try {
           checkerModel_ = std::make_unique<logic::ModelChecker>();
            checkerView_ = std::make_unique<view::ViewCheckerMainWindow>(checkerModel_.get());
            showChecker();
			auto king1 = std::make_shared<ModelKingPiece>(true);
            checkerModel_->getSquareAtPosition(0, 0)->setPiece(king1);
			checkerView_->showInfo("King 1 created");
			auto king2 = std::make_shared<ModelKingPiece>(false);
            checkerModel_->getSquareAtPosition(0, 1)->setPiece(king2);
			checkerView_->showInfo("King 2 created");
			auto king3 = std::make_shared<ModelKingPiece>(true);
		}
        catch (std::exception& e) {
            checkerView_->showError(e.what());
        }
    }

    void GameManager::reset() {
        ModelKingPiece::resetInstanceCounter();;
        closeChecker();
        checkerModel_ = nullptr;
        checkerView_ = nullptr;
    }

    void GameManager::showChecker() {
        checkerView_->show();
    }

    void GameManager::closeChecker() {
		checkerView_->close();
    }

}
