#pragma once
#include "ViewChecker.h"
#include <QMessageBox>

namespace view {
	ViewChecker::ViewChecker(logic::ModelChecker* model, QWidget* parent) {
		centralWidget = new QWidget(this);
		gridLayout = new QGridLayout(centralWidget);
		this->model = model;
		this->setCentralWidget(centralWidget);
		
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				ViewSquare* square = new ViewSquare(model->getSquareAtPosition(i, j), this);
				connect(square, &ViewSquare::clickPiece, this, &ViewChecker::squareClickPiece);
				connect(square, &ViewSquare::clickMove, this, &ViewChecker::squareClickMove);
				gridLayout->addWidget(square, i, j);
			}
		}
	}

	void ViewChecker::squareClickPiece() {
		model->resetPlayableSquares();
		ViewSquare* clickedSquare = qobject_cast<ViewSquare*>(sender());
		if (clickedSquare->getModel()->getPiece() != nullptr) {
			selectedViewSquare = clickedSquare;
			logic::ControllerSquare::clickSquareControl(clickedSquare->getModel(), model);
		}
	}

	void ViewChecker::squareClickMove() {
		ViewSquare* clickedSquare = qobject_cast<ViewSquare*>(sender());
		if (clickedSquare->getModel()->isPlayable()) {
			//selectedViewSquare->disconnectFromPiece();
			//model->setSelectedSquare(clickedSquare->getModel());			
			logic::ControllerSquare::clickSquareMove(clickedSquare->getModel(), model);
		}
	}
}