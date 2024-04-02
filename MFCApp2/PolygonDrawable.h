#pragma once
#include "Drawable.h"
#include "MathFunctions.h"
#include <vector>

class PolygonDrawable :
    public Drawable
{
	public:
		std::vector<PointMath> edges;
		Color borderColor;
		Point pointsArray[100];
		int edgesCount = 0;
		PolygonDrawable(std::vector<PointMath> edges, Color borderColor, Color mainColor, REAL borderWidth);
		PolygonDrawable();
		void Draw(Graphics& graphics);
		void SetDrawSettings(std::vector<PointMath> edges, Color borderColor, Color mainColor, REAL borderWidth);
};

