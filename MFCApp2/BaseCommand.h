#pragma once

#include "TriangleAssembler.h"

class BaseCommand
{
	protected:
		TriangleAssembler* assembler = nullptr;
	public:
		virtual bool TryInstantiate(TriangleAssembler* assembler);
		virtual void Execute() = 0;
		virtual void Undo() = 0;
};

