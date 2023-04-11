#pragma once
#include "ViewSquare.h"
#include "ModelSquare.h"
#include <QMessageBox>

namespace view {

	const QString ViewSquare::COLOR_LIGHT = "background-color: #F0D9B5;";
	const QString ViewSquare::COLOR_DARK = "background-color: #B58863;";
	const QString ViewSquare::COLOR_PLAYABLE = "background-color: #9AB0E4";

	//void ViewSquare::connectToPiece() {
	//	if (model->getPiece() != nullptr) {
	//		connect(this->getModel(), &logic::ModelSquare::updatePieceSignal, this, &ViewSquare::updatePiece);
	//	}
	//}
	//
	//void ViewSquare::disconnectFromPiece() {
	//	if (model->getPiece() != nullptr) {
	//		disconnect(this->getModel(), &logic::ModelSquare::updatePieceSignal, this, &ViewSquare::updatePiece);
	//	}
	//}

	void ViewSquare::updatePlayable() {
		if (model->isPlayable()) {
			setStyleSheet(COLOR_PLAYABLE);
		}
		else {
			setStyleSheet(model->isLight() ? COLOR_LIGHT : COLOR_DARK);
		}
	}

	void ViewSquare::updatePiece() {
		if (model->getPiece() != nullptr) {
			setImage(QPixmap(model->getPiece()->getImagePath().c_str()));
		}
		else {
			setImage(QPixmap());
		}
	}

	void ViewSquare::mousePressEvent(QMouseEvent* event)
	{
		if (model->isPlayable())
			emit clickMove();
		else if (model->getPiece() != nullptr)
			emit clickPiece();
	}

	void ViewSquare::setImage(QPixmap pixmap) {
		if (!pixmap.isNull()) setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		else setPixmap(QPixmap());
	}

	ViewSquare::ViewSquare(logic::ModelSquare* model, QWidget* parent)
		: QLabel(parent)
		, model(model)
	{
		
		setFixedSize(50, 50);
		setAlignment(Qt::AlignCenter);
		setStyleSheet(model->isLight() ? COLOR_LIGHT : COLOR_DARK);
		if (model->getPiece() != nullptr) {
			setImage(QPixmap(model->getPiece()->getImagePath().c_str()));
		}

		// connect the models signals.
		connect(model, &logic::ModelSquare::playableSignal, this, &ViewSquare::updatePlayable);
		connect(model, &logic::ModelSquare::updatePieceSignal, this, &ViewSquare::updatePiece);
	}

	ViewSquare::~ViewSquare()
	{
	}
}