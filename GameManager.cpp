#pragma once
#include "GameManager.h"
#include "ModelRoiPiece.h"
#include "ModelFouPiece.h"
#include "ModelPionPiece.h"
#include <memory>
#include "ModelCavalierPiece.h"

namespace logic {

    // initialize game variables

    bool GameManager::whiteTurn = true;
    bool GameManager::blackTurn = false;
    bool GameManager::whiteCheck = false;
    bool GameManager::blackCheck = false;
    bool GameManager::whiteCheckMate = false;
    bool GameManager::blackCheckMate = false;
    std::unique_ptr<logic::ModelChecker> GameManager::checkerModel = nullptr;
    std::unique_ptr<view::ViewChecker> GameManager::checkerView = nullptr;

    void GameManager::nextTurn() {
        whiteTurn = !whiteTurn;
        blackTurn = !blackTurn;
    }

    bool GameManager::isWhiteTurn() {
        return whiteTurn;
    }

    bool GameManager::isBlackTurn() {
        return blackTurn;
    }

    void GameManager::startEndgame1() {
        checkerModel = std::make_unique<logic::ModelChecker>();

        // créer les objets en utilisant std::make_shared
        auto roiNoir = std::make_shared<ModelRoiPiece>(false);
        auto roiBlanc = std::make_shared<ModelRoiPiece>(true);
        auto fouBlanc = std::make_shared<ModelFouPiece>(true);
        auto fouNoir = std::make_shared<ModelFouPiece>(false);
        auto pionNoir = std::make_shared<ModelPionPiece>(false, false);
		auto cavalierNoir = std::make_shared<ModelCavalierPiece>(false);

        // utiliser les shared_ptr pour initialiser les cases
        checkerModel->getSquareAtPosition(0, 3)->setPiece(roiNoir);
        checkerModel->setBlackKingSquare(checkerModel->getSquareAtPosition(0, 3));
        checkerModel->getSquareAtPosition(5, 0)->setPiece(roiBlanc);
        checkerModel->setWhiteKingSquare(checkerModel->getSquareAtPosition(5, 0));
        checkerModel->getSquareAtPosition(5, 6)->setPiece(pionNoir);
        checkerModel->getSquareAtPosition(6, 0)->setPiece(fouBlanc);
        checkerModel->getSquareAtPosition(6, 2)->setPiece(fouNoir);
		checkerModel->getSquareAtPosition(6, 4)->setPiece(cavalierNoir);

        checkerView = std::make_unique<view::ViewChecker>(checkerModel.get());
        showChecker();
    }

    void GameManager::testKingMax() {
       try {
           checkerModel = std::make_unique<logic::ModelChecker>();
            checkerView = std::make_unique<view::ViewChecker>(checkerModel.get());
            showChecker();
			auto king1 = std::make_shared<ModelRoiPiece>(true);
            checkerModel->getSquareAtPosition(0, 0)->setPiece(king1);
			checkerView->showInfo("King 1 created");
			auto king2 = std::make_shared<ModelRoiPiece>(false);
            checkerModel->getSquareAtPosition(0, 1)->setPiece(king2);
			checkerView->showInfo("King 2 created");
			auto king3 = std::make_shared<ModelRoiPiece>(true);
		}
        catch (std::exception& e) {
            checkerView->showError(e.what());
        }
    }

    void GameManager::reset() {
        ModelRoiPiece::resetInstanceCounter();;
        closeChecker();
        checkerModel = nullptr;
        checkerView = nullptr;
    }

    void GameManager::showChecker() {
        checkerView->show();
    }

    void GameManager::closeChecker() {
		checkerView->close();
    }

}
