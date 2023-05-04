#pragma once
#include <vector>
#include "ModelSquare.h"
#include "ModelChecker.h"

namespace model {
	class Command
	{
	public:
		Command() = default;
		virtual ~Command() = default;
		virtual void execute() = 0;
		virtual void cancel() = 0;
	};
}
