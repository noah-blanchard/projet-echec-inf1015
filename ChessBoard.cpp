#include "ChessBoard.h"
#include "TempModelSquare.h"

namespace logic {
	std::shared_ptr<ChessBoard> ChessBoard::instance_ = nullptr;

	ChessBoard* ChessBoard::getInstance()
	{
		if(instance_ == nullptr)
			instance_ = std::shared_ptr<ChessBoard>(new ChessBoard());
		return instance_.get();
	}

	void ChessBoard::deleteInstance()
	{
		instance_ = nullptr;
	}

	ModelSquare* ChessBoard::getSquareAtPosition(int x, int y) const
	{
		return squares_[x][y].get();
	}

	void ChessBoard::setSelectedSquare(ModelSquare* square)
	{
		selectedSquare_ = std::shared_ptr<ModelSquare>(square);
	}

	ModelSquare* ChessBoard::getSelectedSquare() const
	{
		return selectedSquare_.get();
	}

	void ChessBoard::setWhiteKingSquare(ModelSquare* square)
	{
		whiteKingSquare_ = std::shared_ptr<ModelSquare>(square);
	}

	void ChessBoard::setBlackKingSquare(ModelSquare* square)
	{
		blackKingSquare_ = std::shared_ptr<ModelSquare>(square);
	}

	void ChessBoard::resetPlayableSquares()
	{
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				squares_[i][j]->setPlayable(false);
	}

	bool ChessBoard::validateMove(ModelSquare* currentSquare, ModelSquare* move)
	{
		bool result = true;
		//ModelSquare* kingPosition = nullptr;
		//TempModelSquare tempSquare;
		//tempSquare->setPiece(move->getPiece());
		//move->setPiece(currentSquare->getPiece());
		//if (currentSquare == whiteKingSquare_.get() || currentSquare == blackKingSquare_.get()) {
		//	kingPosition = move;
		//}
		//else if (currentSquare->getPiece()->isWhite()) {
		//	kingPosition = whiteKingSquare_.get();
		//}
		//else {
		//	kingPosition = blackKingSquare_.get();
		//}

		//currentSquare->setPiece(nullptr);

		//for (int i = 0; i < 8; ++i) {
		//	for (int j = 0; j < 8; ++j) {
		//		if (!(squares_[i][j]->getPiece() != nullptr && squares_[i][j]->getPiece()->isWhite() != move->getPiece()->isWhite())) // si la case est vide ou qu'elle contient une piece alliee, continue
		//			continue;

		//		std::vector<ModelSquare*> validMoves = squares_[i][j]->getPiece()->getValidMoves2(this, false);

		//		if (!(std::find(validMoves.begin(), validMoves.end(), kingPosition) != validMoves.end())) // s'il n'y a pas de roi dans validMoves de la case, continue
		//			continue;

		//		result = false;
		//		break;

		//	}
		//}

		//currentSquare->setPiece(move->getPiece());
		//move->setPiece(tempSquare->getPiece());
		return result;
	}

	ChessBoard::ChessBoard() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				squares_[i][j] = std::shared_ptr<ModelSquare>(new ModelSquare((i + j) % 2 == 0, i, j));
			}
		}
	}

}
