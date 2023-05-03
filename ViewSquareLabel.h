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
#include "ControllerSquare.h"

namespace view {
	class ViewSquareLabel : public QLabel
	{
		Q_OBJECT
	public:
		ViewSquareLabel(logic::ModelSquare* model, QWidget* parent = nullptr);
		~ViewSquareLabel() override;
		
		void setImage(QPixmap image);

		logic::ModelSquare* getModel() const { return model_; }
	private:
		logic::ModelSquare* model_;
		
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

