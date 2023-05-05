
#pragma once
#include "Command.h"
#include <memory>
namespace model
{
	class CommandsInvoker
	{
	public:
		static void executeCommand(std::shared_ptr<UserCommand> command)
		{
			command->execute();
			commandsDone_.push_back(command);
		}

		static void undoCommand() // marche bien
		{
			if (commandsDone_.empty())
			{
				return;
			}

			std::shared_ptr<UserCommand> command = commandsDone_.back();
			command->cancel();
			commandsDone_.pop_back();
			commandsUndone_.push_back(command);
		}

		static void redoCommand() // cause souvent des crash, des bugs
		{
			if (commandsUndone_.empty())
			{
				return;
			}

			std::shared_ptr<UserCommand> command = commandsUndone_.back();
			command->execute();
			commandsUndone_.pop_back();
			commandsDone_.push_back(command);
		}

	private:
		static std::vector<std::shared_ptr<UserCommand>> commandsDone_;
		static std::vector<std::shared_ptr<UserCommand>> commandsUndone_;
	};
}
