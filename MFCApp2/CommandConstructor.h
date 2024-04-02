#pragma once
#include <vector>
#include "Commands.h"
#include "TriangleAssembler.h"

class CommandConstructor
{
private:
	std::vector<BaseCommand*> CommandJournal;
	int lastCommandIndex;
	int commandNumber;
public:
	TriangleAssembler* triangleAssembler;
	CommandConstructor(TriangleAssembler* triangleAssembler);
	CommandConstructor();

	void TryAddCommand(BaseCommand* command);
	void undoCommand();
	void reduCommand();
};

