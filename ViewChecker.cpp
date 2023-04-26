/**
 * @file ViewChecker.cpp
 * @author Noah Blanchard / Bai Wu Li
 * @brief View for the Model Checker
 * @date 20/04/2023
 */

#pragma once
#include <QMessageBox>
#include "ViewCheckerMainWindow.h"
#include "GameManager.h"

namespace view
{
	ViewCheckerMainWindow::ViewCheckerMainWindow(logic::ModelChecker* model, QWidget* parent)
	{
		centralWidget_ = new QWidget(this);
		gridLayout_    = new QGridLayout(centralWidget_);
		this->model_   = model;
		this->setCentralWidget(centralWidget_);

		connect(this->model_, &logic::ModelChecker::unallowedMoveSignal, this, &ViewCheckerMainWindow::unallowedMoveNotification);
		
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				ViewSquareLabel* square = new ViewSquareLabel(model->getSquareAtPosition(i, j), this);
				connect(square, &ViewSquareLabel::clickPiece, this, &ViewCheckerMainWindow::squareClickPiece);
				connect(square, &ViewSquareLabel::clickMove, this, &ViewCheckerMainWindow::squareClickMove);
				gridLayout_->addWidget(square, i, j);
			}
		}
	}

	void ViewCheckerMainWindow::unallowedMoveNotification()
	{
		QMessageBox::warning(this, "Unallowed move", "You can't move there");
	}

	void ViewCheckerMainWindow::unallowedPieceNotification()
	{
		std::string color = logic::GameManager::isWhiteTurn() ? "white" : "black";
		std::string message = "It is " + color + "'s turn";

		QMessageBox::warning(this, "Unallowed piece", message.c_str());
	}
	
	void ViewCheckerMainWindow::squareClickPiece()
	{
		model_->resetPlayableSquares();

		ViewSquareLabel* clickedSquare = qobject_cast<ViewSquareLabel*>(sender());

		bool isPieceAllowed = clickedSquare->getModel()->getPiece() != nullptr && clickedSquare->getModel()->getPiece()->isWhite() == logic::GameManager::isWhiteTurn();
		
		if (isPieceAllowed)
		{
			selectedViewSquare_ = clickedSquare;
			logic::ControllerSquare::clickSquareControl(clickedSquare->getModel(), model_);
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
		logic::ControllerSquare::clickSquareMove(clickedSquare->getModel(), model_);
		logic::GameManager::nextTurn();
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