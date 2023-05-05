#include "Square.h"

namespace model
{
	Square::Square(int x, int y)
		: position_(std::make_pair(x, y)), status_(Status::UNPLAYABLE) {}

	std::pair<int, int> Square::getPosition() const
	{
		return position_;
	}

	void Square::markAs(Status status)
	{
		status_ = status;
	}
}