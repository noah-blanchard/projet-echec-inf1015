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
#include "ControllerChecker.h"
#include "ViewSquareLabel.h"
#include "ChessBoard.h"

namespace view {
	class ViewCheckerMainWindow : public QMainWindow
	{
		Q_OBJECT
	public:
		ViewCheckerMainWindow(logic::ChessBoard* model, QWidget* parent = nullptr);
		//~ViewChecker() override;
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
		ViewSquareLabel* selectedViewSquare_ = nullptr;
		QGridLayout* gridLayout_;
		QWidget* centralWidget_;
		QFile* layoutFile_;
		QLineEdit* filePathLineEdit_;
		std::shared_ptr<logic::ChessBoard> model_;
	};
}


