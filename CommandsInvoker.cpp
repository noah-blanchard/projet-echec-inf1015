#include "CommandsInvoker.h"

void model::CommandsInvoker::executeCommand(Command* command)

{
	command->execute();
	commandsDone_.push_back(command);
}

void model::CommandsInvoker::undoCommand()

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

void model::CommandsInvoker::redoCommand()
{
	if (commandsUndone_.empty())
	{
		return;
	}

	Command* command = commandsUndone_.back();
	command->execute();
	commandsUndone_.pop_back();
	commandsDone_.push_back(command);
}
