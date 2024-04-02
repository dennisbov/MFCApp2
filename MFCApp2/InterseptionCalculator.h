#pragma once
#include <vector>
#include "PointMath.h"
#include "Drawables.h"

using namespace std;

class InterseptionCalculator
{
public:
	InterseptionCalculator(Drawer* drawer);
	InterseptionCalculator();
	void RedrawInterseñtions(const vector<vector<PointMath>>& polygons, int polygonsNumber);
	vector<vector<PointMath>> interseptions;

private:
	vector<PointMath> currentInterseption;
	vector<PointMath> calculateIntersection(vector<PointMath> polygon1, vector<PointMath> polygon2);
	MultiplePolygonDrawable visualization;
	Drawer* drawer;
};

