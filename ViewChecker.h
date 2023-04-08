#pragma once
#include <QMainWindow>
#include <QGridLayout>
#include "ModelChecker.h"
#include "ControllerChecker.h"
#include "ViewSquare.h"

namespace view {
	class ViewChecker : public QMainWindow
	{
		Q_OBJECT
	public:
		ViewChecker(logic::ModelChecker* model, QWidget* parent = nullptr);
		//~ViewChecker() override;
		void squareClicked();
	private:
		QGridLayout* gridLayout;
		QWidget* centralWidget;
		logic::ModelChecker* model;
	};
}

