#pragma once
#include "PointT.h"
#include "PolygonDrawable.h"
#include <vector>

struct TriangleT
{
	std::vector<PointT> EdgesArray;
	int lastElementIndex = 0;

public:
	PolygonDrawable polygonDrawable;
	TriangleT();
	PointT* AddEdge(PointT edge);
	void RemoveEdge(PointT* edge);
	std::vector<PointMath> GetPointsVector();
};

