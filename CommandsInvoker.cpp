#include "CommandsInvoker.h"

namespace model
{
	std::vector<std::shared_ptr<UserCommand>> commandsDone_;
	std::vector<std::shared_ptr<UserCommand>> commandsUndone_;

	void CommandsInvoker::executeCommand(std::shared_ptr<UserCommand> command)
	{
		command->execute();
		commandsDone_.push_back(command);
	}

	void CommandsInvoker::undoCommand()
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

	void CommandsInvoker::redoCommand()
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
}