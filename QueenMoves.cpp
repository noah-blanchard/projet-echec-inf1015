#include "QueenMoves.h"
#include "ChessBoard.h"
#include "Square.h"

namespace model
{
	std::array<std::pair<int, int>, 8> DISPLACEMENTS_ =
	{
		std::pair<int, int> {-1, -1},
		std::pair<int, int> {-1,  1},
		std::pair<int, int> { 1,  1},
		std::pair<int, int> { 1, -1},
		std::pair<int, int> { 0, -1},
		std::pair<int, int> {-1,  0},
		std::pair<int, int> { 0,  1},
		std::pair<int, int> { 1,  0},
	};

	QueenMoves::QueenMoves(Piece* piece) : piece_(piece) {};

	std::vector<Square*> QueenMoves::get()
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

	std::vector<Square*> QueenMoves::guess()
	{
		std::vector<Square*> pseudoLegalMoves;

		auto currentSquare = ChessBoard::getSquare(piece_);

		for (auto [dx, dy] : DISPLACEMENTS_)
		{
			auto direction = ValidMoves::getDirection(currentSquare, dx, dy);

			for (auto square : direction)
			{
				pseudoLegalMoves.push_back(square);
			}
		}

		return pseudoLegalMoves;
	}
}