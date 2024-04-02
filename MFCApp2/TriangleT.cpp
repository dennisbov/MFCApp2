#include "pch.h"
#include "TriangleT.h"


TriangleT::TriangleT() {
	EdgesArray = std::vector<PointT>(100, PointT());
}

PointT* TriangleT::AddEdge(PointT edge) {
	EdgesArray[lastElementIndex] = edge;
	lastElementIndex++;
	return &EdgesArray[lastElementIndex-1];
}

void TriangleT::RemoveEdge(PointT* edge) {
	int shift1 = 0;
	for (int i = 0; i < 3; i++)
	{
		if (&EdgesArray[i] == edge) {
			shift1++;
		}
		EdgesArray[i] = EdgesArray[i + shift1];
	}
	lastElementIndex--;
	
	int shift = 0;
}

std::vector<PointMath> TriangleT::GetPointsVector()
{
	std::vector<PointMath> result(lastElementIndex, PointMath());
	for (int i = 0; i < lastElementIndex; i++)
	{
		result[i] = EdgesArray[i].point;
	}
	
	return result;
}


