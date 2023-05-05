#pragma once

#include "Piece.h"

namespace model
{
	class PieceVisitor
	{
	public:
		virtual ~PieceVisitor() = default;

		virtual void visit(Piece&) = 0;

	private:
		PieceVisitor() = delete;
		PieceVisitor(const PieceVisitor&) = delete;
		PieceVisitor& operator=(const PieceVisitor&) = delete;
	};
}

