#include "BishopMoves.h"
#include "ChessBoard.h"
#include "Square.h"
namespace model
{
	const std::array<std::pair<int, int>, 4> BishopMoves::DISPLACEMENTS_ =
	{
		std::pair<int, int> {-1, -1},
		std::pair<int, int> {-1,  1},
		std::pair<int, int> { 1,  1},
		std::pair<int, int> {-1, -1},
	};

	BishopMoves::BishopMoves(Piece* piece) : piece_(piece) {};

	std::vector<Square*> BishopMoves::get()
	{
		std::vector<Square*> legalMoves;

		std::vector<Square*> moves = guess();

		for (auto move : moves)
		{
			if (willCauseCheckmate(piece_, move))
			{
				legalMoves.push_back(move);
			}
		}

		return legalMoves;
	}

	std::vector<Square*> BishopMoves::guess()
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