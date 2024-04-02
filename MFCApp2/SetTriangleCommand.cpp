#include "pch.h"
#include "SetTriangleCommand.h"

void SetTriangleCommand::Execute() {
	assembler->currentTriangle = assembler->AddTriangle(TriangleT());
	assembler->isEditing = true;
}
void SetTriangleCommand::Undo() {
	assembler->RemoveTriangle(assembler->currentTriangle);
	assembler->currentTriangle = nullptr;
	assembler->isEditing = false;
}

bool SetTriangleCommand::TryInstantiate(TriangleAssembler* assembler)
{
	BaseCommand::TryInstantiate(assembler);
	if (assembler->isEditing == false) {
		return true;
	}
	
	return false;
}