#include "pch.h"
#include "PrintDotCommand.h"
PrintDotCommand::PrintDotCommand(float x, float y, Color color, REAL radius){
	this->x = x;
	this->y = y;
	this->color = color;
	this->radius = radius;
}

void PrintDotCommand::Execute() {
	point = assembler->currentTriangle->AddEdge(PointT(PointMath(x, y), color, radius));
	assembler->drawer->AddDrawable(&point->drawable);
	
}

void PrintDotCommand::Undo() {
	assembler->drawer->RemoveDrawable(&point->drawable);
	assembler->currentTriangle->RemoveEdge(point);
}

bool PrintDotCommand::TryInstantiate(TriangleAssembler* assembler){
	BaseCommand::TryInstantiate(assembler);
	if (assembler->currentTriangle == nullptr) {
		return false;
	}
	if (assembler->isEditing == true) {
		return true;
	}
	return false;
}