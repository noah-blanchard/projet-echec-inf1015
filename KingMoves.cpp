#include "KingMoves.h"
#include "ChessBoard.h"
#include "Square.h"

namespace model
{
	const std::array<std::pair<int, int>, 8> KingMoves::DISPLACEMENTS_ =
	{
		std::pair<int, int> {-1, -1},
		std::pair<int, int> {-1,  0},
		std::pair<int, int> {-1,  1},
		std::pair<int, int> { 0, -1},
		std::pair<int, int> { 0,  1},
		std::pair<int, int> { 1, -1},
		std::pair<int, int> { 1,  0},
		std::pair<int, int> { 1,  1},
	};

	KingMoves::KingMoves(Piece* piece) : piece_(piece) {};

	std::vector<Square*> KingMoves::get()
	{
		std::vector<Square*> legalMoves;
		std::vector<Square*> pseudoLegalMoves = this->guess();

		for (Square* move : pseudoLegalMoves)
		{
			if (!willCauseCheckmate(piece_, move))
			{
				legalMoves.push_back(move);
			}
		}

		return legalMoves;
	}

	std::vector<Square*> KingMoves::guess()
	{
		std::vector<Square*> pseudoLegalMoves;

		auto currentSquare = ChessBoard::getSquare(piece_);

		for (auto [dx, dy] : DISPLACEMENTS_)
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