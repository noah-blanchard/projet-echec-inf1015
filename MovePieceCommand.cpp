#include "MovePieceCommand.h"

void model::MovePieceCommand::execute()

{
	playableSquareToReset_ = checker_->getSelectedSquare()->getPiece()->getValidMoves2(checker_, true);
	clickedSquarePiece_ = clickedSquare_->getPiece();
	clickedSquare_->setPiece(checker_->getSelectedSquare()->getPiece());

	if (clickedSquare_->getPiece()->transform(clickedSquare_)) {
		clickedSquare_->emitTransformSignal();
	}

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

	for (Square* square : playableSquareToReset_)
	{
		square->setPlayable(false);
	}
}

void model::MovePieceCommand::cancel()

{
	for (Square* square : playableSquareToReset_)
	{
		square->setPlayable(true);
	}

	checker_->setSelectedSquare(checkerSquare_);
	checker_->setWhiteKingSquare(whiteKingSquare_);
	checker_->setBlackKingSquare(blackKingSquare_);

	checker_->getSelectedSquare()->setPiece(checkerPiece_);
	clickedSquare_->setPiece(clickedSquarePiece_);
}
