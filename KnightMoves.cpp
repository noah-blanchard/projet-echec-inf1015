#include "KnightMoves.h"
#include "ChessBoard.h"
#include "Square.h"

namespace model
{
	const std::array<std::pair<int, int>, 8> KnightMoves::DISPLACEMENTS_ =
	{
		std::pair<int, int> {-1, -2},
		std::pair<int, int> {-2, -1},
		std::pair<int, int> {-2,  1},
		std::pair<int, int> {-1,  2},
		std::pair<int, int> { 1,  2},
		std::pair<int, int> { 2,  1},
		std::pair<int, int> { 2, -1},
		std::pair<int, int> { 1, -2},
	};

	KnightMoves::KnightMoves(Piece* piece) : piece_(piece) {};

	std::vector<Square*> KnightMoves::get()
	{
		std::vector<Square*> legalMoves;
		std::vector<Square*> pseudoLegalMoves = guess();

		for (Square* move : pseudoLegalMoves) // TODO : use copy_if
		{
			if (!willCauseCheckmate(piece_, move))
			{
				legalMoves.push_back(move);
			}
		}

		return legalMoves;
	}


	std::vector<Square*> KnightMoves::guess()
	{
		std::vector<Square*> pseudoLegalMoves;

		auto currentSquare = ChessBoard::getSquare(piece_);

		for (auto [dx, dy] : DISPLACEMENTS_) // TODO : use copy_if
		{
			auto [x, y] = currentSquare->getPosition();
			Square* nextSquare = ChessBoard::getSquare(x + dx, y + dy);

			if (nextSquare != nullptr && !hasAllyPiece(nextSquare))
			{
				pseudoLegalMoves.push_back(nextSquare);
			}
		}

		return pseudoLegalMoves;
	}
}