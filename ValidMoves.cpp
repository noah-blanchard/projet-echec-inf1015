#include "ValidMoves.h"
#include "ChessBoard.h"
#include "Square.h"

namespace model
{

	bool ValidMoves::willCauseCheckmate(Piece* piece,Square* newSquare)
	{
		auto oldSquare = ChessBoard::getSquare(piece);

		ChessBoard::movePiece(piece, newSquare);

		bool willCauseCheckmate = false;

		//auto canThreatAllyKing = [](Square* square)
		//{
		//	return square->getPiece()->isWhite() == square->getPiece()->isWhite();
		//};

		//for (auto [enemy, moves] : ChessBoard::getEnemiesMoves(!piece->isWhite()))
		//{
		//	auto enemyMoves = moves->guess();

		//	if (std::any_of(enemyMoves.begin(), enemyMoves.end(), canThreatAllyKing)
		//	{
		//		willCauseCheckmate = true;

		//		break;
		//	}
		//}

		ChessBoard::movePiece(piece, oldSquare);

		return willCauseCheckmate;
	}

	bool ValidMoves::hasAllyPiece(Square* square)
	{
		return piece_->isWhite() == ChessBoard::getPiece(square)->isWhite();
	}

	bool ValidMoves::hasEnemyPiece(Square* square)
	{
		return piece_->isWhite() != ChessBoard::getPiece(square)->isWhite();
	}

	std::vector<Square*> ValidMoves::getDirection(Square* currentSquare, int dx, int dy)
	{
		std::vector<Square*> moves;

		auto [x, y] = currentSquare->getPosition();

		bool isMovePathObstructed = false;

		for (int i = 1; !isMovePathObstructed; ++i)
		{
			auto nextSquare = ChessBoard::getSquare((x + dx) * i, (y + dy) * i);

			if (nextSquare != nullptr && !hasAllyPiece(nextSquare))
			{
				moves.push_back(nextSquare);
			}
			else
			{
				isMovePathObstructed = true;
			}
		}

		return moves;
	}
}
