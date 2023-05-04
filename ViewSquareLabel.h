/**
 * @file ViewSquareLabel.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief View for the Square using QLabel
 * @date 20/04/2023
 */

#pragma once
#include <QLabel>
#include "ModelSquare.h"
#include <QInputDialog>

namespace view {
	class SquareLabel : public QLabel
	{
		Q_OBJECT
	public:
		SquareLabel(model::Square* model, QWidget* parent = nullptr);
		~SquareLabel() override;
		
		void setImage(QPixmap image);

		model::Square* getModel() const { return model_; }
	private:
		model::Square* model_;
		
		void mousePressEvent(QMouseEvent* event) override;

		static const QString COLOR_LIGHT_;
		static const QString COLOR_DARK_;
		static const QString COLOR_PLAYABLE_;
	

	public slots:
		void updatePlayable();
		void updatePiece();
		void transformPiece();

	signals:
		void clickPiece();
		void clickMove();
		//void clickMove();
		
	};
}

