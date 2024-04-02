#pragma once
#include "BaseCommand.h"
#include "MultiplePolygonDrawable.h"
#include "MathFunctions.h"

class ConfirmTriangleCommand :
    public BaseCommand
{
private:
	TriangleT* triangle = nullptr;
	float drawableWidth;
	Color drawableMainColor;
	Color drawableBorderColor;
	void PrintIntersections(int offset);

public:
	ConfirmTriangleCommand(float drawableWidth, Color drawableMainColor, Color drawableBorderColor);
	void Execute();
	void Undo();
	bool TryInstantiate(TriangleAssembler* assembler);
};

