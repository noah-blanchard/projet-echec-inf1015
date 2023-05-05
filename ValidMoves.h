#pragma once
#include <vector>
#include "Square.h"
#include "Piece.h"
namespace model
{
	class ValidMoves
	{
	public:
		virtual ~ValidMoves() = default;

		virtual std::vector<Square*> get() = 0;

		virtual std::vector<Square*> guess() = 0;

	protected:
		ValidMoves() = default;

		bool hasAllyPiece(Square* square);

		bool hasEnemyPiece(Square* square);

		bool willCauseCheckmate(Piece* piece, Square* newSquare);

		std::vector<Square*> getDirection(Square* currentSquare, int dx, int dy);
		
	private:
		Piece* piece_;
	};
}