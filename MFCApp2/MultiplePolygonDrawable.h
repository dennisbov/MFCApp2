#pragma once
#include "Drawable.h"
#include "vector"
#include "PointMath.h"

class MultiplePolygonDrawable :
    public Drawable
{
public:
	std::vector<std::vector<PointMath>> polygons;
	std::vector<Color> colors;
	MultiplePolygonDrawable();
	void Draw(Graphics& graphics);
	Color pickRandomColor();
};

