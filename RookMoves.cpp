#include "RookMoves.h"
#include "ChessBoard.h"
#include "Square.h"

namespace model
{
	std::array<std::pair<int, int>, 4> DISPLACEMENTS_ = 
	{
		std::pair<int, int> {-1,  0},
		std::pair<int, int> { 0,  1},
		std::pair<int, int> { 1,  0},
		std::pair<int, int> { 0, -1},
	};

	RookMoves::RookMoves(Piece* piece) : piece_(piece) {};

	std::vector<Square*> RookMoves::get()
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

	std::vector<Square*> RookMoves::guess()
	{
		std::vector<Square*> moves;

		auto currentSquare = ChessBoard::getSquare(piece_);

		for (auto [dx, dy] : DISPLACEMENTS_)
		{
			auto direction = ValidMoves::getDirection(currentSquare, dx, dy);

			for (auto square : direction)
			{
				moves.push_back(square);
			}
		}

		return moves;
	}
}