/**
 * @file ViewSquare.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief View for the Model Square
 * @date 20/04/2023
 */

#pragma once
#include "ViewSquareLabel.h"
#include "ModelSquare.h"
#include <QMessageBox>

namespace view
{

	const QString ViewSquareLabel::COLOR_LIGHT_    = "background-color: #F0D9B5;";
	const QString ViewSquareLabel::COLOR_DARK_     = "background-color: #B58863;";
	const QString ViewSquareLabel::COLOR_PLAYABLE_ = "background-color: #9AB0E4";

	void ViewSquareLabel::updatePlayable()
	{
		setStyleSheet(model_->isPlayable() ? COLOR_PLAYABLE_ : model_->isLight() ? COLOR_LIGHT_ : COLOR_DARK_);
	}

	void ViewSquareLabel::updatePiece()
	{
		if (model_->getPiece() != nullptr)
		{
			setImage(QPixmap(model_->getPiece()->getImagePath().c_str()));
		}
		else
		{
			setImage(QPixmap());
		}
	}

	void ViewSquareLabel::mousePressEvent(QMouseEvent* event)
	{
		emit model_->isPlayable() ? clickMove() : model_->getPiece() != nullptr ? clickPiece() : void();
	}

	void ViewSquareLabel::setImage(QPixmap pixmap)
	{
		setPixmap(pixmap.isNull() ? QPixmap() : pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	}

	ViewSquareLabel::ViewSquareLabel(logic::ModelSquare* model, QWidget* parent)
		: QLabel(parent)
		, model_(model)
	{
		
		setFixedSize(50, 50);
		setAlignment(Qt::AlignCenter);
		setStyleSheet(model->isLight() ? COLOR_LIGHT_ : COLOR_DARK_);

		if (model->getPiece() != nullptr)
		{
			setImage(QPixmap(model->getPiece()->getImagePath().c_str()));
		}

		// connect the models signals.
		connect(model, &logic::ModelSquare::playableSignal, this, &ViewSquareLabel::updatePlayable);
		connect(model, &logic::ModelSquare::updatePieceSignal, this, &ViewSquareLabel::updatePiece);
	}

	ViewSquareLabel::~ViewSquareLabel()
	{
	}
}