
#pragma once
#include <utility>
#include "Piece.h"
namespace model
{
	enum class Status { PLAYABLE, UNPLAYABLE };

	class Square
	{
	public:
		Square(int x, int y);

		std::pair<int, int> getPosition() const;

		void markAs(Status status);

	private:
		std::pair<int, int> position_;
		Status status_;
	};
}
