#pragma once
#include "BaseCommand.h"
#include "TriangleT.h"
class SetTriangleCommand :
    public BaseCommand
{
public:
	void Execute();
	void Undo();
	bool TryInstantiate(TriangleAssembler* assembler);
};

