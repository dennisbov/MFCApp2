#include "pch.h"
#include "ConfirmTriangleCommand.h"

ConfirmTriangleCommand::ConfirmTriangleCommand(float drawableWidth, Color drawableMainColor, Color drawableBorderColor)
{
	this->drawableWidth = drawableWidth;
	this->drawableMainColor = drawableMainColor;
	this->drawableBorderColor = drawableBorderColor;
}

void ConfirmTriangleCommand::Execute() {
	triangle = assembler->currentTriangle;
	assembler->currentTriangle = nullptr;
	assembler->isEditing = false;

	triangle->polygonDrawable.SetDrawSettings(triangle->GetPointsVector(), drawableBorderColor, drawableMainColor, drawableWidth);
	
	triangle->polygonDrawable.edgesCount = triangle->lastElementIndex;
	assembler->drawer->AddDrawable(&triangle->polygonDrawable);

	PrintIntersections(0);
}
void ConfirmTriangleCommand::Undo() {
	assembler->currentTriangle = triangle;
	assembler->isEditing = true;

	assembler->drawer->RemoveDrawable(&triangle->polygonDrawable);
	triangle = nullptr;

	PrintIntersections(1);
}

bool ConfirmTriangleCommand::TryInstantiate(TriangleAssembler* assembler){
	BaseCommand::TryInstantiate(assembler);
	if (assembler->isEditing == true && assembler->currentTriangle->lastElementIndex >= 3) {
		return true;
	}
	return false;
}

void ConfirmTriangleCommand::PrintIntersections(int offset)
{
	vector<vector<PointMath>> polygonsToIntersect = assembler->GetTriangleVector();

	assembler->interseptionCalculator.RedrawInterseñtions(polygonsToIntersect, polygonsToIntersect.size() - offset);
}



