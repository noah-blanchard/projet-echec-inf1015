#pragma once
#include <QLabel>
#include "ModelSquare.h"
#include "ControllerSquare.h"

namespace view {
	class ViewSquare : public QLabel
	{
		Q_OBJECT
	public:
		ViewSquare(logic::ModelSquare* model, QWidget* parent = nullptr);
		~ViewSquare() override;
		
		void setImage(QPixmap image);

		logic::ModelSquare* getModel() const { return model; }
	private:
		logic::ModelSquare* model;
		
		void mousePressEvent(QMouseEvent* event) override;

		static const QString COLOR_LIGHT;
		static const QString COLOR_DARK;
		static const QString COLOR_PLAYABLE;
	

	public slots:
		void updatePlayable();
		void updatePiece();

	signals:
		void clickPiece();
		void clickMove();
		//void clickMove();
		
	};
}

