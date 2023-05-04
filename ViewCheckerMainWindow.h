/**
 * @file ViewCheckerMainWindow.h
 * @author Noah Blanchard / Bai Wu Li
 * @brief View for the Checker MainWindow using Qt
 * @date 20/04/2023
 */

#pragma once
#include <QMainWindow>
#include <QGridLayout>
#include <QSplitter>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QFile>
#include "ModelChecker.h"
#include "ViewSquareLabel.h"

namespace view {
	class CheckerMainWindow : public QMainWindow
	{
		Q_OBJECT
	public:
		CheckerMainWindow(model::Checker* model, QWidget* parent = nullptr);
		~CheckerMainWindow() override;
		void squareClickPiece();
		void squareClickMove();
		void clickRestartGame();
		void clickUndo();
		void clickRedo();
		void clickLoadFile();
		void clickStartFile();
		void unallowedMoveNotification();
		void unallowedPieceNotification();
		void showInfo(std::string message);
		void showError(std::string message);
	private:
		SquareLabel* selectedViewSquare_ = nullptr;
		QGridLayout* gridLayout_;
		QWidget* centralWidget_;
		std::string layoutFile_;
		QLineEdit* filePathLineEdit_;
		model::Checker* model_;
	};
}


