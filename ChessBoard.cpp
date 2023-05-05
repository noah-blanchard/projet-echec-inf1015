#include "ChessBoard.h"

namespace model
{
	std::unique_ptr<ChessBoard> ChessBoard::instance_ = nullptr;

	std::array<std::unique_ptr<Square>, 64> ChessBoard::squares_ = {};

	std::unordered_map<Piece*, Square*> ChessBoard::pieceToSquare_ = {};

	ChessBoard& ChessBoard::get()
	{
		if (instance_ == nullptr)
		{
			instance_ = std::make_unique<ChessBoard>();
		}

		return *instance_.get();
	}

	Square* ChessBoard::getSquare(int x, int y)
	{
		int index = x + y * 8;

		return index >= 0 && index < 64 ? squares_[index].get() : nullptr;
	}

	Square* ChessBoard::getSquare(Piece* piece)
	{
		auto it = pieceToSquare_.find(piece);

		return it == pieceToSquare_.end() ? nullptr : it->second;
	}

	Piece* ChessBoard:: getPiece(Square* square)
	{
		auto it = std::find(pieceToSquare_.begin(), pieceToSquare_.end(), square);

		return it == pieceToSquare_.end() ? nullptr : it->first;
	}

	std::vector<Square*> ChessBoard::getEnemiesMoves(bool areEnemiesWhite)
	{
		std::vector<Square*> enemiesMoves;

		for (auto [enemyPiece, square] : pieceToSquare_)
		{
			if (enemyPiece->isWhite() == areEnemiesWhite)
			{
				auto enemyMoves = enemyPiece->getMoves();

				for (auto move : enemyMoves)
				{
					enemiesMoves.push_back(move);
				}
			}
		}

		return enemiesMoves;
	}

	void ChessBoard::movePiece(Piece* piece, Square* newSquare)
	{
		pieceToSquare_[piece] = newSquare;
	}

	
}