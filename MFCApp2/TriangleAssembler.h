#pragma once

#include "TriangleT.h"
#include "Drawer.h"
#include "InterseptionCalculator.h"
#include <vector>

class TriangleAssembler
{
public:
	std::vector<TriangleT> TriangleList;
	InterseptionCalculator interseptionCalculator;
	bool isEditing = false;
	TriangleAssembler(Drawer* drawer);
	TriangleAssembler();
	TriangleT* AddTriangle(TriangleT triangle);
	void RemoveTriangle(TriangleT* triangle);
	vector<vector<PointMath>> GetTriangleVector();
	TriangleT* currentTriangle = nullptr;
	int triangleCount = 0;
	Drawer* drawer;
};

