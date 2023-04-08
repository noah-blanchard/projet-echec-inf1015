#pragma once
#include "ViewSquare.h"
#include "ModelSquare.h"
#include <QMessageBox>

namespace view {

	const QString ViewSquare::COLOR_LIGHT = "background-color: #F0D9B5;";
	const QString ViewSquare::COLOR_DARK = "background-color: #B58863;";
	const QString ViewSquare::COLOR_PLAYABLE = "background-color: #9AB0E4";

	void ViewSquare::updatePlayable() {
		if (model->isPlayable()) {
			setStyleSheet(COLOR_PLAYABLE);
		}
		else {
			setStyleSheet(model->isLight() ? COLOR_LIGHT : COLOR_DARK);
		}
	}

	void ViewSquare::mousePressEvent(QMouseEvent* event)
	{
		emit click();
	}

	ViewSquare::ViewSquare(logic::ModelSquare* model, QWidget* parent)
		: QLabel(parent)
		, model(model)
	{
		
		setFixedSize(50, 50);
		setAlignment(Qt::AlignCenter);
		setStyleSheet(model->isLight() ? COLOR_LIGHT : COLOR_DARK);
		if (model->getPiece() != nullptr) {
			QPixmap pixmap(model->getPiece()->getImagePath().c_str());
			setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		}

		// connect the models signals.
		connect(model, &logic::ModelSquare::playableSignal, this, &ViewSquare::updatePlayable);

	}

	ViewSquare::~ViewSquare()
	{
	}
}