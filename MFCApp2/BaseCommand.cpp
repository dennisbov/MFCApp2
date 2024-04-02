#include "pch.h"
#include "BaseCommand.h"

bool BaseCommand::TryInstantiate(TriangleAssembler* assembler) {
	this->assembler = assembler;
	return true;
}
