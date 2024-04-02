#include "pch.h"
#include "CommandConstructor.h"

CommandConstructor::CommandConstructor(TriangleAssembler* triangleAssembler)
{
	this->triangleAssembler = triangleAssembler;
	this->CommandJournal = std::vector<BaseCommand*>(10000, nullptr);
	commandNumber = 0;
	lastCommandIndex = 0;
}

CommandConstructor::CommandConstructor()
{
	this->triangleAssembler = nullptr;
	this->CommandJournal = std::vector<BaseCommand*>();
	commandNumber = 0;
	lastCommandIndex = 0;
}

void CommandConstructor::TryAddCommand(BaseCommand* command)
{
	if (command->TryInstantiate(triangleAssembler)) {
		if(CommandJournal[lastCommandIndex] != nullptr)
		{
			delete CommandJournal[lastCommandIndex];
		}
		CommandJournal[lastCommandIndex] = command;
		lastCommandIndex++;
		commandNumber = lastCommandIndex;
		command->Execute();
	}
}

void CommandConstructor::undoCommand()
{
	if (lastCommandIndex > 0) {
		CommandJournal[lastCommandIndex - 1]->Undo();
		lastCommandIndex--;
	}
}

void CommandConstructor::reduCommand()
{
	if (lastCommandIndex < commandNumber) {
		CommandJournal[lastCommandIndex]->Execute();
		lastCommandIndex++;
	}
}


