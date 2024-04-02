#pragma once
#include "BaseCommand.h"
#include "PointT.h"
class PrintDotCommand :
    public BaseCommand
{
private:
	float x;
	float y;
	Color color;
	REAL radius;
	PointT* point = nullptr;
public:
	PrintDotCommand(float x, float y, Color color, REAL radius);
	void Execute();
	void Undo();
	bool TryInstantiate(TriangleAssembler* assembler);
};

