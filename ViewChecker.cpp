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

	CheckerMainWindow::CheckerMainWindow(model::Checker* model, QWidget* parent) {
		centralWidget_ = new QWidget(this);
		QSplitter* splitter = new QSplitter(Qt::Horizontal, centralWidget_);
		splitter->setFixedSize(1000, 500);
		QWidget* leftSection = new QWidget(splitter);
		QWidget* rightSection = new QWidget(splitter);
		rightSection->setFixedWidth(500);
		QVBoxLayout* rightLayout = new QVBoxLayout(rightSection);
		QPushButton* button = new QPushButton("Restart Game with this layout", rightSection);
		connect(button, &QPushButton::clicked, this, &CheckerMainWindow::clickRestartGame);

		QPushButton* undo = new QPushButton("Undo", rightSection);
		connect(undo, &QPushButton::clicked, this, &CheckerMainWindow::clickUndo);

		QPushButton* redo = new QPushButton("Redo", rightSection);
		connect(redo, &QPushButton::clicked, this, &CheckerMainWindow::clickRedo);

	
		

		QPushButton* loadFile = new QPushButton("Load Template File", rightSection);
		connect(loadFile, &QPushButton::clicked, this, &CheckerMainWindow::clickLoadFile);

		QSplitter* innerSplitter = new QSplitter(Qt::Horizontal);
		QLabel* label = new QLabel("Template file : ", innerSplitter);

		filePathLineEdit_ = new QLineEdit(innerSplitter);
		filePathLineEdit_->setReadOnly(true);

		

		QPushButton* startLayout = new QPushButton("Start a game with this template", rightSection);
		connect(startLayout, &QPushButton::clicked, this, &CheckerMainWindow::clickStartFile);


		gridLayout_ = new QGridLayout(leftSection);
		this->model_ = model;
		this->setCentralWidget(centralWidget_);

		// connect signal and slot
		connect(this->model_, &model::Checker::unallowedMoveSignal, this, &CheckerMainWindow::unallowedMoveNotification);

		// create left section
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				SquareLabel* square = new SquareLabel(model->getSquareAtPosition(i, j), this);
				square->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
				connect(square, &SquareLabel::clickPiece, this, &CheckerMainWindow::squareClickPiece);
				connect(square, &SquareLabel::clickMove, this, &CheckerMainWindow::squareClickMove);
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
		/*rightLayout->addWidget(filePathLineEdit_); */
		rightLayout->addWidget(innerSplitter);
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

	CheckerMainWindow::~CheckerMainWindow()
	{
		delete model_;
		for (int i = 0; i < gridLayout_->count(); ++i) {
			delete gridLayout_->itemAt(i)->widget();
		}
		delete gridLayout_;
		delete centralWidget_;
	}

	
	void CheckerMainWindow::clickRestartGame() {
		model::GameController::restartGame();
	}

	void CheckerMainWindow::clickUndo()
	{
		model::GameController::undo();
	}

	void CheckerMainWindow::clickRedo()
	{
		model::GameController::redo();
	}

	void CheckerMainWindow::unallowedMoveNotification()
	{
		QMessageBox::warning(this, "Unallowed move", "You can't move there");
	}

	void CheckerMainWindow::unallowedPieceNotification()
	{


	}

	void CheckerMainWindow::clickLoadFile()
	{
		QString filePath = QFileDialog::getOpenFileName(this, "Load Layout File", "", "Text Files (*.txt)");
		if (filePath != "") {
			layoutFile_ = filePath.toStdString();
			filePathLineEdit_->setText(filePath);
		}
	}

	void CheckerMainWindow::clickStartFile()
	{
		if (layoutFile_ != "") {
			model::GameController::startGameFileLayout(layoutFile_, true);
		}
	}
	
	void CheckerMainWindow::squareClickPiece()
	{
		model_->resetPlayableSquares();

		SquareLabel* clickedSquare = qobject_cast<SquareLabel*>(sender());

		bool isPieceAllowed = clickedSquare->getModel()->getPiece() != nullptr /* && clickedSquare->getModel()->getPiece()->isWhite() == logic::GameManager::isWhiteTurn()*/;
		
		if (isPieceAllowed)
		{
			selectedViewSquare_ = clickedSquare;
			model::/*ControllerSquare */GameController::/*clickSquareControl*/selectPiece(clickedSquare->getModel(), model_);
		}
		else
		{
			unallowedPieceNotification();
		}
	}

	void CheckerMainWindow::squareClickMove()
	{
		SquareLabel* clickedSquare = qobject_cast<SquareLabel*>(sender());

		if (!(clickedSquare->getModel()->isPlayable()))
		{
			return;
		}

		//selectedViewSquare->disconnectFromPiece();
		//model->setSelectedSquare(clickedSquare->getModel());			
		model::/*ControllerSquare*/GameController::/*clickSquareMove*/movePiece(clickedSquare->getModel(), model_);
		/*logic::GameManager::nextTurn();*/
		if (model::GameController::isGameOver())
		{
			QMessageBox::information(this, "Game Over", "Checkmate");
		}
	}

	void CheckerMainWindow::showInfo(std::string message)
	{
		QMessageBox::information(this, "Info", message.c_str());
	}

	void CheckerMainWindow::showError(std::string message)
	{
		QMessageBox::critical(this, "Error", message.c_str());
	}
}