/**
 * @file ViewSquare.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief View for the Model Square
 * @date 20/04/2023
 */

#include "ViewSquareLabel.h"
#include "ModelSquare.h"
#include <QMessageBox>

namespace view
{

	const QString SquareLabel::COLOR_LIGHT_    = "background-color: #F0D9B5;";
	const QString SquareLabel::COLOR_DARK_     = "background-color: #B58863;";
	const QString SquareLabel::COLOR_PLAYABLE_ = "background-color: #9AB0E4";

	void SquareLabel::updatePlayable()
	{
		setStyleSheet(model_->isPlayable() ? COLOR_PLAYABLE_ : model_->isLight() ? COLOR_LIGHT_ : COLOR_DARK_);
	}

	void SquareLabel::updatePiece()
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

	void SquareLabel::transformPiece()
	{
		if (!this->model_->getPiece())
		{
			return;
		}

		// Determine the possible piece types for transformation
		std::vector<std::string> pieceTypes = { "Queen", "Rook", "Bishop", "Knight" };
		QList<QString> qItems;

		for (const auto& pieceType : pieceTypes)
		{
			qItems.append(pieceType.c_str());
		}

		// Ask the user to select a piece type
		QString selected = QInputDialog::getItem(this, "Pawn Transformation", "Select a piece type", qItems, 0, false);

		// If the user cancels, do nothing
		if (selected.isNull())
		{
			return;
		}

		// Otherwise, transform the piece
		model_->transformPiece(selected.toStdString());
	}

	void SquareLabel::mousePressEvent(QMouseEvent* event)
	{
		if (model_->isPlayable()) {
			emit clickMove();
		}
		else if(model_->getPiece() != nullptr) {
			emit clickPiece();
		}
		else {
			emit clickEmpty();
		}
	}

	void SquareLabel::setImage(QPixmap pixmap)
	{
		setPixmap(pixmap.isNull() ? QPixmap() : pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	}

	SquareLabel::SquareLabel(model::Square* model, QWidget* parent)
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
		connect(model, &model::Square::playableSignal, this, &SquareLabel::updatePlayable);
		connect(model, &model::Square::updatePieceSignal, this, &SquareLabel::updatePiece);
		connect(model, &model::Square::transformPieceSignal, this, &SquareLabel::transformPiece);
	}

	SquareLabel::~SquareLabel()
	{
	
	}
}