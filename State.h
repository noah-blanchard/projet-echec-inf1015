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
	class Command
	{
	public:
		Command() = default;
		virtual ~Command() = default;
		virtual void execute() = 0;
		virtual void cancel() = 0;
	};

	class SelectPieceCommand : public Command
	{
	public:
		SelectPieceCommand(ModelSquare* clickedSquare, ModelChecker* checker)
		{
			checker->setSelectedSquare(clickedSquare);
			validMoves_ = clickedSquare->getPiece()->getValidMoves(checker, true);
		}

		void execute() override
		{
			for (ModelSquare* square : validMoves_)
			{
				square->setPlayable(true);
			}
		}

		void cancel() override
		{
			for (ModelSquare* square : validMoves_)
			{
				square->setPlayable(false);
			}
		}

	private:
		std::vector <ModelSquare*> validMoves_;
	};

	class MovePieceCommand : public Command
	{
	public:
		MovePieceCommand(ModelSquare* clickedSquare, ModelChecker* checker) :
			clickedSquare_(clickedSquare),
			checker_(checker) {}

		void execute() override
		{
			playableSquareToReset_ = checker_->getSelectedSquare()->getPiece()->getValidMoves(checker_, true);
			clickedSquarePiece_ = clickedSquare_->getPiece();
			clickedSquare_->setPiece(checker_->getSelectedSquare()->getPiece());
			
			checkerPiece_ = checker_->getSelectedSquare()->getPiece();
			checker_->getSelectedSquare()->setPiece(nullptr);

			whiteKingSquare_ = checker_->getWhiteKingSquare();
			blackKingSquare_ = checker_->getBlackKingSquare();

			if (clickedSquare_->getPiece()->isKing() && clickedSquare_->getPiece()->isWhite())
				checker_->setWhiteKingSquare(clickedSquare_);
			else if (clickedSquare_->getPiece()->isKing() && !clickedSquare_->getPiece()->isWhite())
				checker_->setBlackKingSquare(clickedSquare_);

			checkerSquare_ = checker_->getSelectedSquare();
			checker_->setSelectedSquare(nullptr); 
			
			for (ModelSquare* square : playableSquareToReset_)
			{
				square->setPlayable(false);
			}
		}

		void cancel() override
		{
			for (ModelSquare* square : playableSquareToReset_)
			{
				square->setPlayable(true);
			}

			checker_->setSelectedSquare(checkerSquare_);
			checker_->setWhiteKingSquare(whiteKingSquare_);
			checker_->setBlackKingSquare(blackKingSquare_);

			checker_->getSelectedSquare()->setPiece(checkerPiece_);
			clickedSquare_->setPiece(clickedSquarePiece_);
		}

	private:
		ModelSquare* clickedSquare_;
		ModelChecker* checker_;
		std::shared_ptr<ModelPiece> clickedSquarePiece_;
		std::shared_ptr<ModelPiece> checkerPiece_;
		std::vector <ModelSquare*> playableSquareToReset_;
		ModelSquare* checkerSquare_;
		ModelSquare* whiteKingSquare_;
		ModelSquare* blackKingSquare_;

	};

	class CommandsInvoker
	{
	public:
		static void executeCommand(Command* command)
		{
			command->execute();
			commandsDone_.push_back(command);
		}

		static void undoCommand()
		{
			if (commandsDone_.empty())
			{
				return;
			}

			Command* command = commandsDone_.back();
			command->cancel();
			commandsDone_.pop_back();
			commandsUndone_.push_back(command);
		}

		static void redoCommand()		{
			if (commandsUndone_.empty())
			{
				return;
			}

			Command* command = commandsUndone_.back();
			command->execute();
			commandsUndone_.pop_back();
			commandsDone_.push_back(command);	
		}

	private:
		inline static std::vector<Command*> commandsDone_;
		inline static std::vector<Command*> commandsUndone_;
	};

	class GameTurn
	{
	public:
		virtual ~GameTurn() = default;

		virtual void selectPiece(ModelSquare* clickedSquare, ModelChecker* checker)
		{
			CommandsInvoker::executeCommand(new SelectPieceCommand(clickedSquare, checker));
		}

		virtual void movePiece(ModelSquare* clickedSquare, ModelChecker* checker)
		{
			CommandsInvoker::executeCommand(new MovePieceCommand(clickedSquare, checker));
		}

		virtual bool isGameOver(ModelChecker* checker, bool& isGameOver) = 0;
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

		void movePiece(ModelSquare* clickedSquare, ModelChecker* checker) override
		{
			GameTurn::movePiece(clickedSquare, checker);
		}

		bool isGameOver(ModelChecker* checker, bool& isGameOver) override
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					std::shared_ptr<ModelPiece> piece = checker->getSquareAtPosition(i, j)->getPiece();

					if (piece != nullptr && piece->isWhite() && !piece->getValidMoves(checker, true).empty())
					{
						return isGameOver = false;
					}
				}
			}

			return isGameOver = true;
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

		void movePiece(ModelSquare* clickedSquare, ModelChecker* checker) override
		{
			GameTurn::movePiece(clickedSquare, checker);
		}

		bool isGameOver(ModelChecker* checker, bool& isGameOver) override
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					std::shared_ptr<ModelPiece> piece = checker->getSquareAtPosition(i, j)->getPiece();

					if (piece != nullptr && !piece->isWhite() && !piece->getValidMoves(checker, true).empty())
					{
						return isGameOver = false;
					}
				}
			}

			return isGameOver = true;
		}

	};

	class Checkmate : public GameTurn
	{
	public :
	void selectPiece(ModelSquare* clickedSquare, ModelChecker* checker) override
		{
			// do nothing
		}

		void movePiece(ModelSquare* clickedSquare, ModelChecker* checker) override
		{
			// do nothing
		}

		bool isGameOver(ModelChecker* checker, bool& isGameOver) override
		{
			return isGameOver = true;
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

			currentTurn_->movePiece(clickedSquare, checker);
			currentTurn_ = transitions_[currentTurn_];
			
			if (currentTurn_->isGameOver(checker, isGameOver_))
			{
				currentTurn_ = checkmate_;
			}
 
		}

		static void undo()
		{
			CommandsInvoker::undoCommand();
		}

		static void redo()
		{
			CommandsInvoker::redoCommand();
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
		inline static std::map<GameTurn*, GameTurn*> transitions_ = { {whiteTurn_, blackTurn_}, {blackTurn_, whiteTurn_} };
		inline static std::unique_ptr<view::ViewCheckerMainWindow> checkerView_ = nullptr;
	};
}