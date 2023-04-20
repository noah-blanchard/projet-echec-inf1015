/**
 * @file ViewCheckerMainWindow.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief View for the Checker MainWindow using Qt
 * @date 20/04/2023
 */

#pragma once
#include <QMainWindow>
#include <QGridLayout>
#include "ModelChecker.h"
#include "ControllerChecker.h"
#include "ViewSquareLabel.h"

namespace view {
	class ViewCheckerMainWindow : public QMainWindow
	{
		Q_OBJECT
	public:
		ViewCheckerMainWindow(logic::ModelChecker* model, QWidget* parent = nullptr);
		//~ViewChecker() override;
		void squareClickPiece();
		void squareClickMove();
		void unallowedMoveNotification();
		void unallowedPieceNotification();
		void showInfo(std::string message);
		void showError(std::string message);
	private:
		ViewSquareLabel* selectedViewSquare_ = nullptr;
		QGridLayout* gridLayout_;
		QWidget* centralWidget_;
		logic::ModelChecker* model_;
	};
}


