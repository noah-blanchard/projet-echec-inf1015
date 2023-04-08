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
				connect(square, &ViewSquare::click, this, &ViewChecker::squareClicked);
				gridLayout->addWidget(square, i, j);
			}
		}
	}

	void ViewChecker::squareClicked() {
		ViewSquare* clickedSquare = qobject_cast<ViewSquare*>(sender());
		if (clickedSquare->getModel()->getPiece() != nullptr) {
			logic::ControllerSquare::clickSquareControl(clickedSquare->getModel(), model);
		}
	}
}