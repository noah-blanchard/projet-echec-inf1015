#pragma once
#include "Command.h"

namespace model {
	class CommandsInvoker
	{
	public:
		static void executeCommand(Command* command)
		{
			command->execute();
			commandsDone_.push_back(command);
		}

		static void undoCommand()
		{
			if (commandsDone_.empty())
			{
				return;
			}

			Command* command = commandsDone_.back();
			command->cancel();
			commandsDone_.pop_back();
			commandsUndone_.push_back(command);
		}

		static void redoCommand() {
			if (commandsUndone_.empty())
			{
				return;
			}

			Command* command = commandsUndone_.back();
			command->execute();
			commandsUndone_.pop_back();
			commandsDone_.push_back(command);
		}

	private:
		inline static std::vector<Command*> commandsDone_;
		inline static std::vector<Command*> commandsUndone_;
	};
}

