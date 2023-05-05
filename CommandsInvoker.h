#pragma once
#include "Command.h"

namespace model {
	class CommandsInvoker
	{
	public:

		static void executeCommand(Command* command);

		static void undoCommand();

		static void redoCommand();

	private:
		inline static std::vector<Command*> commandsDone_;
		inline static std::vector<Command*> commandsUndone_;
	};
}

