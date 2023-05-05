
#pragma once
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <vector>
#include "Square.h"
namespace model
{
	class ChessBoard // TODO : patron Composite
	{
	public:
		static ChessBoard& get(); // getInstance

		static Square* getSquare(int x, int y);

		static Square* getSquare(Piece* piece);

		static Piece* getPiece(Square* square);

		static std::vector<Square*> getEnemiesMoves(bool areEnemiesWhite);

		// static void init(); // TODO : utiliser le patron Builder
		
		//template <class Piece>
		//static void addPiece(int x, int y, bool isWhite)
		//{
		//	auto piece = std::make_unique<Piece>(isWhite);
		//	auto square = ChessBoard::getSquare(x, y);

		//	pieceToSquare_.insert({ piece.get(), square });
		//}

		// TODO : patron Factory pour creer les pieces 
		static void movePiece(Piece* piece, Square* newSquare);

	private:
		// TODO : constructeurs
		static std::unique_ptr<ChessBoard> instance_;
		static std::array<std::unique_ptr<Square>, 64> squares_; // TODO : methode pour les initialiser
		static std::unordered_map<Piece*, Square*> pieceToSquare_;
	};
}
