/**
 * @file ViewChecker.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief View for the Model Checker
 * @date 20/04/2023
 */

#pragma once
#include "ViewCheckerMainWindow.h"
#include <QMessageBox>
#include /*"GameManager.h"*/ "State.h"


namespace view {
	//ViewCheckerMainWindow::ViewCheckerMainWindow(logic::ModelChecker* model, QWidget* parent) {
	//	centralWidget_ = new QWidget(this);
	//	gridLayout_ = new QGridLayout(centralWidget_);
	//	this->model_ = model;
	//	this->setCentralWidget(centralWidget_);

	//	connect(this->model_, &logic::ModelChecker::unallowedMoveSignal, this, &ViewCheckerMainWindow::unallowedMoveNotification);
	//	
	//	for (int i = 0; i < 8; ++i) {
	//		for (int j = 0; j < 8; ++j) {
	//			ViewSquareLabel* square = new ViewSquareLabel(model->getSquareAtPosition(i, j), this);
	//			connect(square, &ViewSquareLabel::clickPiece, this, &ViewCheckerMainWindow::squareClickPiece);
	//			connect(square, &ViewSquareLabel::clickMove, this, &ViewCheckerMainWindow::squareClickMove);
	//			gridLayout_->addWidget(square, i, j);
	//		}
	//	}
	//}

	ViewCheckerMainWindow::ViewCheckerMainWindow(logic::ChessBoard* model, QWidget* parent) {
		centralWidget_ = new QWidget(this);
		QSplitter* splitter = new QSplitter(Qt::Horizontal, centralWidget_);
		splitter->setFixedSize(1000, 500);
		QWidget* leftSection = new QWidget(splitter);
		QWidget* rightSection = new QWidget(splitter);
		rightSection->setFixedWidth(500);
		QVBoxLayout* rightLayout = new QVBoxLayout(rightSection);
		QPushButton* button = new QPushButton("Restart Game", rightSection);
		connect(button, &QPushButton::clicked, this, &ViewCheckerMainWindow::clickRestartGame);

		QPushButton* undo = new QPushButton("Undo", rightSection);
		connect(undo, &QPushButton::clicked, this, &ViewCheckerMainWindow::clickUndo);

		QPushButton* redo = new QPushButton("Redo", rightSection);
		connect(redo, &QPushButton::clicked, this, &ViewCheckerMainWindow::clickRedo);

		QPushButton* loadFile = new QPushButton("Load File", rightSection);
		connect(loadFile, &QPushButton::clicked, this, &ViewCheckerMainWindow::clickLoadFile);

		filePathLineEdit_ = new QLineEdit(rightSection);
		filePathLineEdit_->setReadOnly(true);

		QPushButton* startLayout = new QPushButton("Start a game with this template", rightSection);
		connect(startLayout, &QPushButton::clicked, this, &ViewCheckerMainWindow::clickStartFile);

		gridLayout_ = new QGridLayout(leftSection);
		this->model_ = std::shared_ptr<logic::ChessBoard>(model);
		this->setCentralWidget(centralWidget_);

		// connect signal and slot
		//connect(model_.get(), &logic::ChessBoard::unallowedMoveSignal, this, &ViewCheckerMainWindow::unallowedMoveNotification); inutile

		// create left section
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				ViewSquareLabel* square = new ViewSquareLabel(model->getSquareAtPosition(i, j), this);
				square->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
				connect(square, &ViewSquareLabel::clickPiece, this, &ViewCheckerMainWindow::squareClickPiece);
				connect(square, &ViewSquareLabel::clickMove, this, &ViewCheckerMainWindow::squareClickMove);
				gridLayout_->addWidget(square, i, j);
			}
		}
		// set left section as central widget

		// create right section

		// add button to right section
		rightLayout->addWidget(button);
		rightLayout->addWidget(undo);
		rightLayout->addWidget(redo);
		rightLayout->addWidget(loadFile);
		rightLayout->addWidget(filePathLineEdit_);
		rightLayout->addWidget(startLayout);
		// add stretch to push button to the top
		rightLayout->addStretch();

		// create horizontal splitter
		
		// set main window as central widget
		setCentralWidget(centralWidget_);

		// set main window size
		setFixedSize(1000, 500);
		setWindowTitle("Simple Chess Game");
	}

	
	void ViewCheckerMainWindow::clickRestartGame() {
		logic::ControllerChecker::restartGameEvent();
	}

	void ViewCheckerMainWindow::clickUndo()
	{
		logic::GameController::undo();
	}

	void ViewCheckerMainWindow::clickRedo()
	{
		logic::GameController::redo();
	}

	void ViewCheckerMainWindow::unallowedMoveNotification()
	{
		QMessageBox::warning(this, "Unallowed move", "You can't move there");
	}

	void ViewCheckerMainWindow::unallowedPieceNotification()
	{
		/*std::string color = logic::GameManager::isWhiteTurn() ? "white" : "black";*/
		/*std::string message = "It is " + color + "'s turn";*/

		/*QMessageBox::warning(this, "Unallowed piece", message.c_str());*/
	}

	void ViewCheckerMainWindow::clickLoadFile()
	{
		QString filePath = QFileDialog::getOpenFileName(this, "Load Layout File", "", "Text Files (*.txt)");
		if (filePath != "") {
			layoutFile_ = new QFile(filePath);
			filePathLineEdit_->setText(filePath);
		}
	}

	void ViewCheckerMainWindow::clickStartFile()
	{
		if (layoutFile_ != nullptr) {
			logic::GameController::startGameFileLayout(layoutFile_);
		}
	}
	
	void ViewCheckerMainWindow::squareClickPiece()
	{
		model_->resetPlayableSquares();

		ViewSquareLabel* clickedSquare = qobject_cast<ViewSquareLabel*>(sender());

		bool isPieceAllowed = clickedSquare->getModel()->getPiece() != nullptr /* && clickedSquare->getModel()->getPiece()->isWhite() == logic::GameManager::isWhiteTurn()*/;
		
		if (isPieceAllowed)
		{
			selectedViewSquare_ = clickedSquare;
			logic::/*ControllerSquare */GameController::/*clickSquareControl*/selectPiece(clickedSquare->getModel(), model_.get());
		}
		else
		{
			unallowedPieceNotification();
		}
	}

	void ViewCheckerMainWindow::squareClickMove()
	{
		ViewSquareLabel* clickedSquare = qobject_cast<ViewSquareLabel*>(sender());

		if (!(clickedSquare->getModel()->isPlayable()))
		{
			return;
		}

		//selectedViewSquare->disconnectFromPiece();
		//model->setSelectedSquare(clickedSquare->getModel());			
		logic::/*ControllerSquare*/GameController::/*clickSquareMove*/movePiece(clickedSquare->getModel(), model_.get());
		/*logic::GameManager::nextTurn();*/
		if (logic::GameController::isGameOver())
		{
			QMessageBox::information(this, "Game Over", "Checkmate");
		}
	}

	void ViewCheckerMainWindow::showInfo(std::string message)
	{
		QMessageBox::information(this, "Info", message.c_str());
	}

	void ViewCheckerMainWindow::showError(std::string message)
	{
		QMessageBox::critical(this, "Error", message.c_str());
	}
}