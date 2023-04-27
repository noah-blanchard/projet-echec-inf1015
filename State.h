#include "controllerSquare.h"
#include "modelChecker.h"
#include "ViewCheckerMainWindow.h"
#include "ModelSquare.h"
#include "ModelChecker.h"
#include <map>
#include "GameManager.h"
#include "ModelKingPiece.h"
#include "ModelQueenPiece.h"
#include "ModelBishopPiece.h"
#include "ModelPawnPiece.h"
#include "ModelKnightPiece.h"


#pragma once
namespace logic
{
	class GameTurn
	{
	public:
		virtual ~GameTurn() = default;

		virtual void selectPiece(ModelSquare* clickedSquare, ModelChecker* checker)
		{
			checker->setSelectedSquare(clickedSquare);
			std::vector <ModelSquare*> validMoves = clickedSquare->getPiece()->getValidMoves(checker, true);
			for (ModelSquare* square : validMoves)
			{
				square->setPlayable(true);
			}
		}

		virtual void movePiece(ModelSquare* clickedSquare, ModelChecker* checker, bool& isGameOver)
		{
			clickedSquare->setPiece(checker->getSelectedSquare()->getPiece());
			checker->getSelectedSquare()->setPiece(nullptr);

			if (clickedSquare->getPiece()->isKing() && clickedSquare->getPiece()->isWhite())
				checker->setWhiteKingSquare(clickedSquare);
			else if (clickedSquare->getPiece()->isKing() && !clickedSquare->getPiece()->isWhite())
				checker->setBlackKingSquare(clickedSquare);

			checker->setSelectedSquare(nullptr);
			checker->resetPlayableSquares();
		}
	};


	class WhiteTurn : public GameTurn
	{
	public:
		void selectPiece(ModelSquare* clickedSquare, ModelChecker* checker) override
		{
			if (clickedSquare->getPiece()->isWhite())
			{
				GameTurn::selectPiece(clickedSquare, checker);
			}
		}

		void movePiece(ModelSquare* clickedSquare, ModelChecker* checker, bool& isGameOver) override
		{
			GameTurn::movePiece(clickedSquare, checker, isGameOver);

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					std::shared_ptr<ModelPiece> piece = checker->getSquareAtPosition(i, j)->getPiece();

					if (piece != nullptr && !piece->isWhite() && !piece->getValidMoves(checker, true).empty())
					{
						return;
					}
				}
			}

			isGameOver = true;
		}


	};

	class BlackTurn : public GameTurn
	{
	public:
		void selectPiece(ModelSquare* clickedSquare, ModelChecker* checker) override
		{
			if (!clickedSquare->getPiece()->isWhite())
			{
				GameTurn::selectPiece(clickedSquare, checker);
			}
		}

		void movePiece(ModelSquare* clickedSquare, ModelChecker* checker, bool& isGameOver) override
		{
			GameTurn::movePiece(clickedSquare, checker, isGameOver);
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					std::shared_ptr<ModelPiece> piece = checker->getSquareAtPosition(i, j)->getPiece();

					if (piece != nullptr && piece->isWhite() && !piece->getValidMoves(checker, true).empty())
					{
						return;
					}
				}
			}

			isGameOver = true;
		}

	};

	class Checkmate : public GameTurn
	{
	public :
	void selectPiece(ModelSquare* clickedSquare, ModelChecker* checker) override
		{
			// do nothing
		}

		void movePiece(ModelSquare* clickedSquare, ModelChecker* checker, bool& isGameOver) override
		{
			// do nothing
		}
	};

	class GameController
	{
	public:
		static void selectPiece(ModelSquare* clickedSquare, ModelChecker* checker)
		{
			currentTurn_->selectPiece(clickedSquare, checker);
		}

		static void movePiece(ModelSquare* clickedSquare, ModelChecker* checker)
		{
			// change the state

			currentTurn_->movePiece(clickedSquare, checker, isGameOver_);
			currentTurn_ = transitions_[currentTurn_];

			if (isGameOver_)
			{
				currentTurn_ = checkmate_;
			}
		}

		static void startNewGame()
		{
			//checkerView_->close();
			checkerView_ = nullptr;
			currentTurn_ = whiteTurn_;
			ModelChecker* checkerModel = new ModelChecker();

			// créer les objets en utilisant std::make_shared
			auto blackKing = std::make_shared<ModelKingPiece>(false);
			auto whiteKing = std::make_shared<ModelKingPiece>(true);
			auto whiteBishop = std::make_shared<ModelBishopPiece>(true);
			auto blackBishop = std::make_shared<ModelBishopPiece>(false);
			auto blackPawn = std::make_shared<ModelPawnPiece>(false, false);
			auto blackKnight = std::make_shared<ModelKnightPiece>(false);
			auto whiteQueen = std::make_shared<ModelQueenPiece>(true);

			// utiliser les shared_ptr pour initialiser les cases
			checkerModel->getSquareAtPosition(0, 3)->setPiece(blackKing);
			checkerModel->setBlackKingSquare(checkerModel->getSquareAtPosition(0, 3));
			checkerModel->getSquareAtPosition(5, 0)->setPiece(whiteKing);
			checkerModel->setWhiteKingSquare(checkerModel->getSquareAtPosition(5, 0));
			checkerModel->getSquareAtPosition(5, 6)->setPiece(blackPawn);
			checkerModel->getSquareAtPosition(6, 0)->setPiece(whiteBishop);
			checkerModel->getSquareAtPosition(6, 2)->setPiece(blackBishop);
			checkerModel->getSquareAtPosition(6, 4)->setPiece(blackKnight);
			checkerModel->getSquareAtPosition(0, 0)->setPiece(whiteQueen);

			checkerView_ = std::make_unique<view::ViewCheckerMainWindow>(checkerModel);
			checkerView_->show();
		}

		static bool isGameOver()
		{
			return isGameOver_;
		}

	private:
		inline static GameTurn* blackTurn_ = new BlackTurn;
		inline static GameTurn* whiteTurn_ = new WhiteTurn;
		inline static GameTurn* checkmate_ = new Checkmate;
		inline static GameTurn* currentTurn_ = whiteTurn_;
		inline static bool isGameOver_ = false;
		inline static std::map<GameTurn*, GameTurn*> transitions_ = { {whiteTurn_, blackTurn_}, {blackTurn_, whiteTurn_}, {checkmate_, checkmate_} };
		inline static std::unique_ptr<view::ViewCheckerMainWindow> checkerView_ = nullptr;
	};
}