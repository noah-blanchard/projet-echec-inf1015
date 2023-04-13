#pragma once
#include "ViewChecker.h"
#include <QMessageBox>
#include "GameManager.h"

namespace view {
	ViewChecker::ViewChecker(logic::ModelChecker* model, QWidget* parent) {
		centralWidget = new QWidget(this);
		gridLayout = new QGridLayout(centralWidget);
		this->model = model;
		this->setCentralWidget(centralWidget);

		connect(this->model, &logic::ModelChecker::unallowedMoveSignal, this, &ViewChecker::unallowedMoveNotification);
		
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				ViewSquare* square = new ViewSquare(model->getSquareAtPosition(i, j), this);
				connect(square, &ViewSquare::clickPiece, this, &ViewChecker::squareClickPiece);
				connect(square, &ViewSquare::clickMove, this, &ViewChecker::squareClickMove);
				gridLayout->addWidget(square, i, j);
			}
		}
	}

	void ViewChecker::unallowedMoveNotification() {
		QMessageBox::warning(this, "Unallowed move", "You can't move there");
	}

	void ViewChecker::unallowedPieceNotification() {
		std::string color = logic::GameManager::isWhiteTurn() ? "white" : "black";
		std::string message = "It is " + color + "'s turn";

		QMessageBox::warning(this, "Unallowed piece", message.c_str());
	}
	
	void ViewChecker::squareClickPiece() {
		model->resetPlayableSquares();
		ViewSquare* clickedSquare = qobject_cast<ViewSquare*>(sender());
		if (clickedSquare->getModel()->getPiece() != nullptr && clickedSquare->getModel()->getPiece()->isWhite() == logic::GameManager::isWhiteTurn()) {
			selectedViewSquare = clickedSquare;
			logic::ControllerSquare::clickSquareControl(clickedSquare->getModel(), model);
		}
		else {
			unallowedPieceNotification();
		}
	}

	void ViewChecker::squareClickMove() {
		ViewSquare* clickedSquare = qobject_cast<ViewSquare*>(sender());
		if (clickedSquare->getModel()->isPlayable()) {
			//selectedViewSquare->disconnectFromPiece();
			//model->setSelectedSquare(clickedSquare->getModel());			
			logic::ControllerSquare::clickSquareMove(clickedSquare->getModel(), model);
			logic::GameManager::nextTurn();
		}
	}
}