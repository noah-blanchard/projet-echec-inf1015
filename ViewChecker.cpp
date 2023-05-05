/**
 * @file ViewChecker.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief View for the Model Checker
 * @date 20/04/2023
 */

#include "ViewCheckerMainWindow.h"
#include <QMessageBox>
#include "State.h"


namespace view {
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

	
		helpDialog_ = new QDialog(this);
		helpDialog_->setFixedSize(440, 320);
		helpDialog_->setWindowTitle("Help");
		QLabel* helpLabel = new QLabel("To load a template file, click on the button \"Load Template File\" and select a file.\n"
			"To start a game with this template, click on the button \"Start a game with this template\".\n"
			"To restart the game with the current template, click on the button \"Restart Game with this layout\".\n"
			"To create custom templates, place a \".txt\" file in the \"game_layouts\" folder.\n"
			"The file should be filled with lines containing : column number (0-7), row number (0-7), is white (0-1), piece char\n"
			"The piece char should be : \n"
			"\"P\" for a pawn\n"
			"\"R\" for a rook\n"
			"\"N\" for a knight\n"
			"\"B\" for a bishop\n"
			"\"Q\" for a queen\n"
			"\"K\" for a king\n"
			"Example : for a white rook at the top left corner, the line should be : 0 0 1 R\n"
			"Example : for a black pawn at the bottom right corner, the line should be : 7 7 0 P\n"
			"Full examples already exist in the \"game_layouts\" folder.\n"
			, helpDialog_);
		helpLabel->setWordWrap(true);
		helpLabel->setAlignment(Qt::AlignCenter);
		helpLabel->setFixedSize(435, 315);
		helpLabel->setMargin(5);


		

		QSplitter* innerSplitter = new QSplitter(Qt::Horizontal);
		QLabel* label = new QLabel("Template file : ", innerSplitter);

		filePathLineEdit_ = new QLineEdit(innerSplitter);
		filePathLineEdit_->setReadOnly(true);
		QPushButton* loadFile = new QPushButton("Load Template File", innerSplitter);
		connect(loadFile, &QPushButton::clicked, this, &CheckerMainWindow::clickLoadFile);
		QPushButton* help = new QPushButton("?", innerSplitter);
		connect(help, &QPushButton::clicked, this, &CheckerMainWindow::clickHelp);

		

		QPushButton* startLayout = new QPushButton("Start a game with this template", rightSection);
		connect(startLayout, &QPushButton::clicked, this, &CheckerMainWindow::clickStartFile);


		gridLayout_ = new QGridLayout(leftSection);
		this->model_ = model;
		this->setCentralWidget(centralWidget_);

		// create left section
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				SquareLabel* square = new SquareLabel(model->getSquareAtPosition(i, j), this);
				square->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
				connect(square, &SquareLabel::clickPiece, this, &CheckerMainWindow::squareClickPiece);
				connect(square, &SquareLabel::clickMove, this, &CheckerMainWindow::squareClickMove);
				connect(square, &SquareLabel::clickEmpty, this, &CheckerMainWindow::unallowedMoveNotification);
				gridLayout_->addWidget(square, i, j);
			}
		}

		rightLayout->addWidget(button);
		rightLayout->addWidget(undo);
		rightLayout->addWidget(redo);
		rightLayout->addWidget(innerSplitter);
		rightLayout->addWidget(startLayout);
		rightLayout->addStretch();

		setCentralWidget(centralWidget_);

		setFixedSize(1000, 500);
		setWindowTitle("Simple Chess Game");

	}

	CheckerMainWindow::~CheckerMainWindow()
	{
		for (int i = 0; i < gridLayout_->count(); ++i)
		{
			QLayoutItem* item = gridLayout_->itemAt(i);
			if (item != nullptr)
			{
				gridLayout_->removeItem(item);
				delete item->widget();
				delete item;
			}
		}
		delete model_;
		delete helpDialog_;
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
		QMessageBox::warning(this, "Unallowed move", "This move is not allowed !");
	}

	void CheckerMainWindow::unallowedPieceNotification()
	{
		QMessageBox::warning(this, "Unallowed piece", "It is not your turn !");
	}

	void CheckerMainWindow::clickLoadFile()
	{
		QString filePath = QFileDialog::getOpenFileName(this, "Load Layout File", "game_layouts", "Text Files (*.txt)");
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

	void CheckerMainWindow::clickHelp()
	{
		
		helpDialog_->show();

	}
	
	void CheckerMainWindow::squareClickPiece()
	{
		model_->resetPlayableSquares();

		SquareLabel* clickedSquare = qobject_cast<SquareLabel*>(sender());

		bool isPieceAllowed = clickedSquare->getModel()->getPiece() != nullptr && model::GameController::isPieceAllowed(clickedSquare->getModel()->getPiece().get());
		
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
	
		model:: GameController::movePiece(clickedSquare->getModel(), model_);
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