
#pragma once
#include <vector>
namespace model
{
	class UserCommand
	{
	public:
		virtual void execute() = 0;
		virtual void cancel() = 0;
	};
}