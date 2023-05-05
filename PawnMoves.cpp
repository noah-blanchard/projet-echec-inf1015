#include "PawnMoves.h"
#include "ChessBoard.h"
#include "Square.h"

namespace model
{
	bool hasMoved_ = false;

	PawnMoves::PawnMoves(Piece* piece)
		: piece_(piece)
	{
	}

	std::vector<Square*> PawnMoves::get()
	{
		std::vector<Square*> legalMoves;

		for (auto move : guess())
		{
			if (willCauseCheckmate(piece_, move))
			{
				legalMoves.push_back(move);
			}
		}

		return legalMoves;
	}

	std::vector<Square*> PawnMoves::guess()
	{

		std::vector<Square*> pseudoLegalMoves;

		auto currentSquare = ChessBoard::getSquare(piece_);

		int dy = piece_->isWhite() ? 1 : -1;
		dy *= hasMoved_ ? 1 : 2;

		for (int i = 1; i <= dy; ++i)
		{
			auto [x, y] = currentSquare->getPosition();
			auto nextSquare = ChessBoard::getSquare(x, y + i);

			if (nextSquare != nullptr && ChessBoard::getPiece(nextSquare) != nullptr)
			{
				pseudoLegalMoves.push_back(nextSquare);
			}
		}

		for (int i = -1; i <= 1; i += 2)
		{
			auto [x, y] = currentSquare->getPosition();
			Square* nextSquare = ChessBoard::getSquare(x + i, y + dy);

			if (nextSquare != nullptr && hasEnemyPiece(nextSquare))
			{
				pseudoLegalMoves.push_back(nextSquare);
			}
		}

		return pseudoLegalMoves;
	}


}