#include "pch.h"
#include "TriangleAssembler.h"

TriangleAssembler::TriangleAssembler(Drawer* drawer)
{
	this->drawer = drawer;
	this->TriangleList = std::vector<TriangleT>(10000, TriangleT());
	this->interseptionCalculator = InterseptionCalculator(drawer);
}

TriangleAssembler::TriangleAssembler()
{
	this->drawer = nullptr;
	this->TriangleList = std::vector<TriangleT>();
	this->interseptionCalculator = InterseptionCalculator(drawer);
}

TriangleT* TriangleAssembler::AddTriangle(TriangleT triangle)
{
	TriangleList[triangleCount] = triangle;
	triangleCount++;
	return &TriangleList[triangleCount - 1];
}

void TriangleAssembler::RemoveTriangle(TriangleT* triangle)
{
	int shift = 0;
	
	for (int i = 0; i < triangleCount; i++)
	{
		
		if (&TriangleList[i] == triangle)
		{
			shift++;
		}
		TriangleList[i] = TriangleList[i + shift];
	}
	triangleCount--;
}

vector<vector<PointMath>> TriangleAssembler::GetTriangleVector()
{
	vector<vector<PointMath>> result(triangleCount, vector<PointMath>());
	for (int i = 0; i < triangleCount; i++)
	{
		result[i] = TriangleList[i].GetPointsVector();
	}
	return result;
}
