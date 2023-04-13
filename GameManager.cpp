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

    void GameManager::showChecker() {
        checkerView->show();
    }
}
