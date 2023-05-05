#pragma once

#include "PieceVisitor.h"
#include "MovesCalculator.h"

namespace model
{
	class ValidMovesVisitor : public PieceVisitor
	{
	public:
		~ValidMovesVisitor() override = default;
	};
}

