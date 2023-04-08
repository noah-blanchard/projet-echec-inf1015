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

		logic::ModelSquare* getModel() const { return model; }
	private:
		logic::ModelSquare* model;
		void mousePressEvent(QMouseEvent* event) override;

		static const QString COLOR_LIGHT;
		static const QString COLOR_DARK;
		static const QString COLOR_PLAYABLE;
	

	public slots:
		void updatePlayable();

	signals:
		void click();
		
	};
}

